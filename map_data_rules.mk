# Map JSON data

# Inputs
MAPS_DIR = $(DATA_ASM_SUBDIR)/maps
LAYOUTS_DIR = $(DATA_ASM_SUBDIR)/layouts

# Outputs
MAPS_OUTDIR := $(MAPS_DIR)
LAYOUTS_OUTDIR := $(LAYOUTS_DIR)
INCLUDECONSTS_OUTDIR := include/constants

AUTO_GEN_TARGETS += $(INCLUDECONSTS_OUTDIR)/map_groups.h
AUTO_GEN_TARGETS += $(INCLUDECONSTS_OUTDIR)/layouts.h
AUTO_GEN_TARGETS += $(INCLUDECONSTS_OUTDIR)/map_event_ids.h

MAP_DIRS := $(dir $(wildcard $(MAPS_DIR)/*/map.json))
MAP_CONNECTIONS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/connections.inc,$(MAP_DIRS))
MAP_EVENTS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/events.inc,$(MAP_DIRS))
MAP_HEADERS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/header.inc,$(MAP_DIRS))
MAP_JSONS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/map.json,$(MAP_DIRS))

$(DATA_ASM_BUILDDIR)/maps.o: $(DATA_ASM_SUBDIR)/maps.s $(LAYOUTS_DIR)/layouts.inc $(LAYOUTS_DIR)/layouts_table.inc $(MAPS_DIR)/headers.inc $(MAPS_DIR)/groups.inc $(MAPS_DIR)/connections.inc $(MAP_CONNECTIONS) $(MAP_HEADERS)
	$(PREPROC) $< charmap.txt | $(CPP) -I include - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@
$(DATA_ASM_BUILDDIR)/map_events.o: $(DATA_ASM_SUBDIR)/map_events.s $(MAPS_DIR)/events.inc $(MAP_EVENTS)
	$(PREPROC) $< charmap.txt | $(CPP) -I include - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@

$(MAPS_OUTDIR)/%/header.inc $(MAPS_OUTDIR)/%/events.inc $(MAPS_OUTDIR)/%/connections.inc: $(MAPS_DIR)/%/map.json $(INCLUDECONSTS_OUTDIR)/map_groups.h
	$(MAPJSON) map firered $< $(LAYOUTS_DIR)/layouts.json $(@D)

$(MAPS_OUTDIR)/connections.inc $(MAPS_OUTDIR)/groups.inc $(MAPS_OUTDIR)/events.inc $(MAPS_OUTDIR)/headers.inc $(INCLUDECONSTS_OUTDIR)/map_groups.h $(DATA_SRC_SUBDIR)/map_group_count.h: $(MAPS_DIR)/map_groups.json
	$(MAPJSON) groups firered $< $(MAPS_OUTDIR) $(INCLUDECONSTS_OUTDIR)

# Randomize which tall-grass metatile variant (if a tileset has more than
# one) is placed at each grass tile in a map's layout. Generated copies are
# keyed off the pristine, source-controlled map.bin, so a map only gets
# rerolled when its layout is actually edited, not on every build.
GRASS_RANDOMIZER := $(MISC_TOOL_DIR)/randomize_grass_tiles.py
GENERATED_LAYOUTS_DIR := $(BUILD_DIR)/generated/layouts
LAYOUT_NAMES := $(patsubst $(LAYOUTS_DIR)/%/,%,$(dir $(wildcard $(LAYOUTS_DIR)/*/map.bin)))
RANDOMIZED_MAPBINS := $(foreach name,$(LAYOUT_NAMES),$(GENERATED_LAYOUTS_DIR)/$(name)/map.bin)

$(GENERATED_LAYOUTS_DIR)/%/map.bin: $(LAYOUTS_DIR)/%/map.bin $(GRASS_RANDOMIZER) $(LAYOUTS_DIR)/layouts.json $(DATA_SRC_SUBDIR)/tilesets/metatiles.h
	@mkdir -p $(@D)
	python3 $(GRASS_RANDOMIZER) $* $< $@

$(LAYOUTS_OUTDIR)/layouts.inc $(LAYOUTS_OUTDIR)/layouts_table.inc $(INCLUDECONSTS_OUTDIR)/layouts.h: $(LAYOUTS_DIR)/layouts.json $(RANDOMIZED_MAPBINS)
	$(MAPJSON) layouts firered $< $(LAYOUTS_OUTDIR) $(INCLUDECONSTS_OUTDIR)
	sed -i 's#data/layouts/\([^"[:space:]]*\)/map\.bin#$(GENERATED_LAYOUTS_DIR)/\1/map.bin#g' $(LAYOUTS_OUTDIR)/layouts.inc

# Generate constants for map events, which depend on data that's distributed across the map.json files.
# There's a lot of map.json files, so we print an abbreviated output with echo.
$(INCLUDECONSTS_OUTDIR)/map_event_ids.h: $(MAP_JSONS)
	@$(MAPJSON) event_constants firered $^ $(INCLUDECONSTS_OUTDIR)/map_event_ids.h
	@echo "$(MAPJSON) event_constants firered <MAP_JSONS> $(INCLUDECONSTS_OUTDIR)/map_event_ids.h"
