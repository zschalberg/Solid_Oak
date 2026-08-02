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

def auto_loop_midi(in_path, out_path):
    print(f"Auto-looping MIDI: {in_path} -> {out_path}")
    with open(in_path, 'rb') as f:
        data = f.read()
        
    if data[:4] != b'MThd':
        print("Not a valid MIDI file")
        return
        
    header_length = struct.unpack('>I', data[4:8])[0]
    file_format, num_tracks, division = struct.unpack('>HHH', data[8:8+header_length])
    
    # First, let's find the maximum tick position across all tracks to determine the loop end point
    max_ticks = 0
    offset = 8 + header_length
    
    for t in range(num_tracks):
        track_len = struct.unpack('>I', data[offset+4:offset+8])[0]
        track_data = data[offset+8:offset+8+track_len]
        offset += 8 + track_len
        
        t_offset = 0
        running_status = None
        absolute_ticks = 0
        
        while t_offset < len(track_data):
            delta, t_offset = parse_variable_length_quantity(track_data, t_offset)
            absolute_ticks += delta
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
                t_offset += meta_len
            elif status in (0xF0, 0xF7):
                sys_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += sys_len
            else:
                break
        
        # We want the loop to end where notes finish playing (excluding final end of track meta event)
        if absolute_ticks > max_ticks:
            max_ticks = absolute_ticks
            
    print(f"Max ticks of notes found: {max_ticks}")
    
    # Now rebuild Track 0, inserting '[' at tick 0 and ']' at max_ticks
    offset = 8 + header_length
    new_midi_data = bytearray(data[:offset])
    
    for t in range(num_tracks):
        track_id = data[offset:offset+4]
        track_len = struct.unpack('>I', data[offset+4:offset+8])[0]
        track_data = data[offset+8:offset+8+track_len]
        offset += 8 + track_len
        
        if t != 0:
            # Copy all note-containing tracks as is
            new_midi_data.extend(track_id)
            new_midi_data.extend(struct.pack('>I', track_len))
            new_midi_data.extend(track_data)
            continue
            
        # For Track 0, we rebuild it and insert the markers
        t_offset = 0
        running_status = None
        absolute_ticks = 0
        
        # Events will be stored as (absolute_ticks, raw_event_bytes)
        events = []
        
        while t_offset < len(track_data):
            delta, t_offset = parse_variable_length_quantity(track_data, t_offset)
            absolute_ticks += delta
            if t_offset >= len(track_data):
                break
                
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
            elif msg_type in (0xA0, 0xB0, 0xE0):
                t_offset += 2
            elif msg_type in (0xC0, 0xD0):
                t_offset += 1
            elif status == 0xFF:
                meta_type = track_data[t_offset]
                t_offset += 1
                meta_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += meta_len
            elif status in (0xF0, 0xF7):
                sys_len, t_offset = parse_variable_length_quantity(track_data, t_offset)
                t_offset += sys_len
            else:
                break
                
            # If the event is END OF TRACK (0xFF 0x2F), we skip it and append it at the very end
            if status == 0xFF and meta_type == 0x2F:
                continue
                
            event_bytes = track_data[event_start:t_offset]
            events.append((absolute_ticks, event_bytes))
            
        # Add loop markers
        loop_start_meta = b'\xFF\x06\x01['
        loop_end_meta = b'\xFF\x06\x01]'
        
        events.append((0, loop_start_meta))
        events.append((max_ticks, loop_end_meta))
        
        # Add END OF TRACK at the end
        events.append((max_ticks + 1, b'\xFF\x2F\x00'))
        
        # Sort events by absolute ticks
        events.sort(key=lambda x: x[0])
        
        # Re-encode Track 0
        rebuilt_track = bytearray()
        prev_ticks = 0
        for ev_ticks, ev_bytes in events:
            delta = ev_ticks - prev_ticks
            rebuilt_track.extend(write_variable_length_quantity(delta))
            rebuilt_track.extend(ev_bytes)
            prev_ticks = ev_ticks
            
        new_midi_data.extend(b'MTrk')
        new_midi_data.extend(struct.pack('>I', len(rebuilt_track)))
        new_midi_data.extend(rebuilt_track)
        
    with open(out_path, 'wb') as file:
        file.write(new_midi_data)
    print("Auto-looping complete.")

if __name__ == '__main__':
    auto_loop_midi(r"C:\Users\zscha\Downloads\Harmony.mid", "sound/songs/midi/mus_harmony.mid")
