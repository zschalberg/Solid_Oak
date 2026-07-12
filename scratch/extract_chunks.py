import json

transcript_path = r"C:\Users\zscha\.gemini\antigravity\brain\c00cc0a0-c1ee-4b38-8fae-cf5bb5041ca9\.system_generated\logs\transcript.jsonl"
out_path = r"c:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/extracted_chunks.txt"

with open(transcript_path, "r", encoding="utf-8") as f:
    for line in f:
        data = json.loads(line)
        if data.get("step_index") == 1015:
            for tc in data.get("tool_calls", []):
                if tc.get("name") == "multi_replace_file_content":
                    args = tc.get("args", {})
                    chunks = args["ReplacementChunks"]
                    
                    with open(out_path, "w", encoding="utf-8") as out_f:
                        if isinstance(chunks, str):
                            out_f.write(chunks)
                        else:
                            json.dump(chunks, out_f, indent=2)
                    print("Successfully wrote raw chunks to extracted_chunks.txt")
                    break
