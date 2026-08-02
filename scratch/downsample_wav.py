import struct
import os
import sys

def resample_and_mono_wav(in_path, out_path, target_rate=16000):
    print(f"Processing: {in_path} -> {out_path} at {target_rate}Hz Mono")
    with open(in_path, 'rb') as f:
        data = f.read()
        
    if data[:4] != b'RIFF' or data[8:12] != b'WAVE':
        print("Not a valid WAV file")
        return False
        
    offset = 12
    chunks = []
    fmt_chunk_index = -1
    data_chunk_index = -1
    
    while offset < len(data):
        chunk_id = data[offset:offset+4]
        if len(chunk_id) < 4:
            break
        chunk_len = struct.unpack('<I', data[offset+4:offset+8])[0]
        chunk_data = data[offset+8:offset+8+chunk_len]
        
        chunks.append({
            'id': chunk_id,
            'len': chunk_len,
            'data': chunk_data
        })
        
        if chunk_id == b'fmt ':
            fmt_chunk_index = len(chunks) - 1
        elif chunk_id == b'data':
            data_chunk_index = len(chunks) - 1
            
        offset += 8 + chunk_len
        if chunk_len % 2 != 0:
            offset += 1
            
    if fmt_chunk_index == -1 or data_chunk_index == -1:
        print("fmt or data chunks not found")
        return False
        
    fmt = chunks[fmt_chunk_index]
    wFormatTag, wChannels, dwSamplesPerSec, dwAvgBytesPerSec, wBlockAlign, wBitsPerSample = struct.unpack(
        '<HHIIHH', fmt['data'][:16]
    )
    
    audio_data = chunks[data_chunk_index]['data']
    bytes_per_sample = wBitsPerSample // 8
    
    # 1. Convert to Mono first if it is stereo
    mono_frames = []
    num_input_frames = len(audio_data) // (bytes_per_sample * wChannels)
    
    if wBitsPerSample == 16:
        fmt_str = f"<{wChannels}h"
        for i in range(num_input_frames):
            frame_offset = i * bytes_per_sample * wChannels
            channels = struct.unpack_from(fmt_str, audio_data, frame_offset)
            avg = sum(channels) // wChannels
            mono_frames.append(avg)
    elif wBitsPerSample == 8:
        fmt_str = f"<{wChannels}B"
        for i in range(num_input_frames):
            frame_offset = i * bytes_per_sample * wChannels
            channels = struct.unpack_from(fmt_str, audio_data, frame_offset)
            avg = sum(channels) // wChannels
            mono_frames.append(avg)
    else:
        print(f"Unsupported bits per sample: {wBitsPerSample}")
        return False
        
    # 2. Resample to target_rate using Linear Interpolation
    ratio = dwSamplesPerSec / target_rate
    num_output_frames = int(num_input_frames / ratio)
    resampled_frames = []
    
    for j in range(num_output_frames):
        src_pos = j * ratio
        src_idx_floor = int(src_pos)
        src_idx_ceil = min(src_idx_floor + 1, num_input_frames - 1)
        weight = src_pos - src_idx_floor
        
        val_floor = mono_frames[src_idx_floor]
        val_ceil = mono_frames[src_idx_ceil]
        
        # Linear interpolation
        interpolated = val_floor * (1.0 - weight) + val_ceil * weight
        resampled_frames.append(int(interpolated))
        
    # 3. Pack resampled audio data
    new_audio_data = bytearray()
    if wBitsPerSample == 16:
        for val in resampled_frames:
            new_audio_data.extend(struct.pack('<h', val))
    elif wBitsPerSample == 8:
        for val in resampled_frames:
            new_audio_data.extend(struct.pack('<B', val))
            
    # 4. Update loops metadata in 'smpl' chunk
    # Since we resampled the audio, any loop start/end frame indices in the 'smpl' chunk 
    # must be scaled by the resampling ratio!
    for chunk in chunks:
        if chunk['id'] == b'smpl' and len(chunk['data']) >= 36:
            smpl_data = bytearray(chunk['data'])
            # The 'smpl' chunk has:
            # 0-27: basic fields
            # 28-31: cSampleLoops (number of loop definitions)
            # 32-35: cbSamplerData
            # Followed by cSampleLoops structures of 24 bytes each:
            #   0-3: dwIdentifier
            #   4-7: dwType
            #   8-11: dwStart (loop start frame index)
            #   12-15: dwEnd (loop end frame index)
            #   16-19: dwFraction
            #   20-23: dwPlayCount
            cSampleLoops = struct.unpack('<I', smpl_data[28:32])[0]
            for loop_idx in range(cSampleLoops):
                loop_offset = 36 + loop_idx * 24
                if loop_offset + 24 <= len(smpl_data):
                    dwStart = struct.unpack('<I', smpl_data[loop_offset+8:loop_offset+12])[0]
                    dwEnd = struct.unpack('<I', smpl_data[loop_offset+12:loop_offset+16])[0]
                    
                    # Scale loop points
                    new_start = int(dwStart / ratio)
                    new_end = int(dwEnd / ratio)
                    
                    struct.pack_into('<I', smpl_data, loop_offset+8, new_start)
                    struct.pack_into('<I', smpl_data, loop_offset+12, new_end)
                    print(f"  Adjusted loop points for {chunk['id'].decode()}: {dwStart}->{new_start}, {dwEnd}->{new_end}")
            chunk['data'] = bytes(smpl_data)
            
    # 5. Update format info
    new_wChannels = 1
    new_wBlockAlign = bytes_per_sample
    new_dwAvgBytesPerSec = target_rate * new_wBlockAlign
    
    extra_bytes = fmt['data'][16:]
    new_fmt_data = struct.pack(
        '<HHIIHH', wFormatTag, new_wChannels, target_rate, new_dwAvgBytesPerSec, new_wBlockAlign, wBitsPerSample
    ) + extra_bytes
    
    chunks[fmt_chunk_index]['data'] = new_fmt_data
    chunks[fmt_chunk_index]['len'] = len(new_fmt_data)
    
    chunks[data_chunk_index]['data'] = bytes(new_audio_data)
    chunks[data_chunk_index]['len'] = len(new_audio_data)
    
    # 6. Rebuild WAV binary
    riff_len = 4
    for c in chunks:
        riff_len += 8 + c['len']
        if c['len'] % 2 != 0:
            riff_len += 1
            
    out_data = bytearray()
    out_data.extend(b'RIFF')
    out_data.extend(struct.pack('<I', riff_len))
    out_data.extend(b'WAVE')
    
    for c in chunks:
        out_data.extend(c['id'])
        out_data.extend(struct.pack('<I', c['len']))
        out_data.extend(c['data'])
        if c['len'] % 2 != 0:
            out_data.append(0)
            
    with open(out_path, 'wb') as file:
        file.write(out_data)
    print("  Done.")
    return True

def main():
    desktop_dir = r"C:\Users\zscha\OneDrive\Desktop"
    target_dir = "sound/direct_sound_samples"
    
    mapping = {
        "042.wav": "osrs_accordion.wav",
        "3443L.wav": "osrs_flute.wav",
        "666.wav": "osrs_guitar.wav",
        "oboeL.wav": "osrs_oboe.wav"
    }
    
    os.makedirs(target_dir, exist_ok=True)
    
    for src_name, dst_name in mapping.items():
        src_path = os.path.join(desktop_dir, src_name)
        dst_path = os.path.join(target_dir, dst_name)
        if os.path.exists(src_path):
            # Downsample to 16000Hz (good GBA compromise for CPU and audio quality)
            resample_and_mono_wav(src_path, dst_path, target_rate=16000)
        else:
            print(f"Source file {src_path} not found")

if __name__ == '__main__':
    main()
