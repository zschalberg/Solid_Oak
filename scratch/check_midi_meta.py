import struct
import sys

def parse_variable_length_quantity(data, offset):
    value = 0
    while True:
        byte = data[offset]
        offset += 1
        value = (value << 7) | (byte & 0x7F)
        if not (byte & 0x80):
            break
    return value, offset

def inspect_midi_meta(filepath):
    print(f"Inspecting Meta events in: {filepath}")
    with open(filepath, 'rb') as f:
        data = f.read()
        
    if data[:4] != b'MThd':
        print("Not a valid MIDI file")
        return
        
    header_length = struct.unpack('>I', data[4:8])[0]
    file_format, num_tracks, division = struct.unpack('>HHH', data[8:8+header_length])
    print(f"Format: {file_format}, Tracks: {num_tracks}")
    
    offset = 8 + header_length
    for t in range(num_tracks):
        if offset >= len(data):
            break
        if data[offset:offset+4] != b'MTrk':
            break
            
        track_length = struct.unpack('>I', data[offset+4:offset+8])[0]
        track_start = offset + 8
        track_end = track_start + track_length
        offset = track_end
        
        track_data = data[track_start:track_end]
        t_offset = 0
        running_status = None
        
        print(f"\n--- Track {t} ---")
        
        while t_offset < len(track_data):
            delta, t_offset = parse_variable_length_quantity(track_data, t_offset)
            if t_offset >= len(track_data):
                break
                
            status = track_data[t_offset]
            if status & 0x80:
                t_offset += 1
                running_status = status
            else:
                status = running_status
                
            msg_type = status & 0xF0
            
            if msg_type in (0x80, 0x90):
                t_offset += 2
            elif msg_type in (0xA0, 0xB0, 0xE0):
                t_offset += 2
            elif msg_type in (0xC0, 0xD0):
                t_offset += 1
            elif status == 0xFF:
                meta_type = track_data[t_offset]
                t_offset += 1
                meta_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                meta_val = track_data[t_offset:t_offset+meta_len]
                t_offset += meta_len
                
                # Check for Marker (0x06) or Text (0x01)
                text = meta_val.decode('utf-8', errors='ignore').strip()
                if meta_type == 0x06:
                    print(f"  [MARKER] at delta {delta}: '{text}'")
                elif meta_type == 0x01:
                    print(f"  [TEXT] at delta {delta}: '{text}'")
                elif meta_type == 0x03:
                    print(f"  [TRACK NAME] at delta {delta}: '{text}'")
                elif meta_type == 0x2F:
                    print(f"  [END OF TRACK]")
            elif status in (0xF0, 0xF7):
                sys_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += sys_len
            else:
                break

def main():
    if len(sys.argv) > 1:
        inspect_midi_meta(sys.argv[1])
    else:
        inspect_midi_meta("sound/songs/midi/mus_route1.mid")

if __name__ == '__main__':
    main()
