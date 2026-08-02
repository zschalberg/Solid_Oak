import struct
import sys
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

def inspect_midi(filepath):
    print(f"Inspecting: {filepath}")
    with open(filepath, 'rb') as f:
        data = f.read()
        
    if data[:4] != b'MThd':
        print("Not a valid MIDI file")
        return
        
    header_length = struct.unpack('>I', data[4:8])[0]
    file_format, num_tracks, division = struct.unpack('>HHH', data[8:8+header_length])
    print(f"Format: {file_format}, Tracks: {num_tracks}, Division: {division}")
    
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
        
        channels = set()
        program_changes = []
        note_count = 0
        min_note = 127
        max_note = 0
        track_name = f"Track {t}"
        
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
            channel = status & 0x0F
            
            if msg_type == 0x80 or msg_type == 0x90:
                note = track_data[t_offset]
                velocity = track_data[t_offset+1]
                t_offset += 2
                channels.add(channel)
                if msg_type == 0x90 and velocity > 0:
                    note_count += 1
                    min_note = min(min_note, note)
                    max_note = max(max_note, note)
            elif msg_type in (0xA0, 0xB0, 0xE0):
                t_offset += 2
                channels.add(channel)
            elif msg_type in (0xC0, 0xD0):
                val = track_data[t_offset]
                t_offset += 1
                channels.add(channel)
                if msg_type == 0xC0:
                    program_changes.append(val)
            elif status == 0xFF:
                meta_type = track_data[t_offset]
                t_offset += 1
                meta_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                meta_val = track_data[t_offset:t_offset+meta_len]
                t_offset += meta_len
                if meta_type == 0x03:
                    try:
                        track_name = meta_val.decode('utf-8', errors='ignore').strip()
                    except:
                        pass
            elif status in (0xF0, 0xF7):
                sys_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += sys_len
            else:
                break
                
        print(f"\n--- {track_name} (Track {t}) ---")
        print(f"  Note Count: {note_count}")
        if note_count > 0:
            print(f"  Note Range: {min_note} to {max_note}")
        if channels:
            print(f"  MIDI Channels: {sorted(list(channels))}")
        if program_changes:
            print(f"  Program Changes (Instruments): {program_changes}")

if __name__ == '__main__':
    inspect_midi(r"C:\Users\zscha\Downloads\Sea_Shanty_2.mid")
