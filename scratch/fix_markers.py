import struct
import os

def parse_variable_length_quantity(data, offset):
    value = 0
    while True:
        byte = data[offset]
        offset += 1
        value = (value << 7) | (byte & 0x7F)
        if not (byte & 0x80):
            break
    return value, offset

def write_variable_length_quantity(value):
    data = bytearray()
    if value == 0:
        return b'\x00'
    while value > 0:
        byte = value & 0x7F
        value >>= 7
        if data:
            byte |= 0x80
        data.insert(0, byte)
    return bytes(data)

def rename_markers(filepath):
    print(f"Renaming loop markers in: {filepath}")
    with open(filepath, 'rb') as f:
        data = f.read()
        
    if data[:4] != b'MThd':
        print("Not a valid MIDI file")
        return
        
    header_length = struct.unpack('>I', data[4:8])[0]
    file_format, num_tracks, division = struct.unpack('>HHH', data[8:8+header_length])
    
    offset = 8 + header_length
    new_midi_data = bytearray(data[:offset])
    
    for t in range(num_tracks):
        track_id = data[offset:offset+4]
        track_len = struct.unpack('>I', data[offset+4:offset+8])[0]
        track_data = data[offset+8:offset+8+track_len]
        offset += 8 + track_len
        
        if t != 0:
            # Leave all instrument tracks completely unmodified
            new_midi_data.extend(track_id)
            new_midi_data.extend(struct.pack('>I', track_len))
            new_midi_data.extend(track_data)
            continue
            
        # Parse Track 0 and rename the markers
        t_offset = 0
        running_status = None
        rebuilt_track = bytearray()
        
        while t_offset < len(track_data):
            delta, t_offset = parse_variable_length_quantity(track_data, t_offset)
            rebuilt_track.extend(write_variable_length_quantity(delta))
            
            event_start = t_offset
            status = track_data[t_offset]
            
            has_status = (status & 0x80) != 0
            if has_status:
                t_offset += 1
                running_status = status
            else:
                status = running_status
                
            msg_type = status & 0xF0
            
            if msg_type in (0x80, 0x90):
                t_offset += 2
                rebuilt_track.extend(track_data[event_start:t_offset])
            elif msg_type in (0xA0, 0xB0, 0xE0):
                t_offset += 2
                rebuilt_track.extend(track_data[event_start:t_offset])
            elif msg_type in (0xC0, 0xD0):
                t_offset += 1
                rebuilt_track.extend(track_data[event_start:t_offset])
            elif status == 0xFF:
                meta_type = track_data[t_offset]
                t_offset += 1
                meta_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                meta_val = track_data[t_offset:t_offset+meta_len]
                t_offset += meta_len
                
                if meta_type == 0x06: # Marker
                    text = meta_val.decode('utf-8', errors='ignore').strip()
                    if text == '[loopStart]':
                        # Rename to '[' (length 1)
                        new_meta = b'\xFF\x06\x01['
                        rebuilt_track.extend(new_meta)
                        print("  Renamed '[loopStart]' to '['")
                    elif text == '[loopEnd]':
                        # Rename to ']' (length 1)
                        new_meta = b'\xFF\x06\x01]'
                        rebuilt_track.extend(new_meta)
                        print("  Renamed '[loopEnd]' to ']'")
                    else:
                        rebuilt_track.extend(track_data[event_start:t_offset])
                else:
                    rebuilt_track.extend(track_data[event_start:t_offset])
            elif status in (0xF0, 0xF7):
                sys_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += sys_len
                rebuilt_track.extend(track_data[event_start:t_offset])
            else:
                break
                
        new_midi_data.extend(b'MTrk')
        new_midi_data.extend(struct.pack('>I', len(rebuilt_track)))
        new_midi_data.extend(rebuilt_track)
        
    with open(filepath, 'wb') as file:
        file.write(new_midi_data)
    print("Loop markers renamed successfully.")

if __name__ == '__main__':
    # 1. Restore the clean copied MIDI file first to remove the stereo/all-tracks stuff
    import shutil
    shutil.copyfile(r"C:\Users\zscha\Downloads\Sea_Shanty_2.mid", "sound/songs/midi/mus_sea_shanty_2.mid")
    # 2. Rename markers in the restored file
    rename_markers("sound/songs/midi/mus_sea_shanty_2.mid")
