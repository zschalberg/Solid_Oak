# Solid-Oak: Act 1 Vanilla NPC Audit Report

> **Audit Target:** All maps and interiors across the complete Act 1 progression.
> **Omitted:** Pokémon Center maps (omitted as they will be removed/replaced in Solid-Oak).
> **Purpose:** Identify all remaining character objects (human NPCs, trainers, and overworld Pokémon) still executing original, unmodified FireRed scripts.

## Executive Summary

- **Total Maps Scanned in Act 1 Scope:** 54
- **Maps Containing Vanilla NPCs:** 33
- **Total Vanilla NPCs Remaining:** **98**

| Area / Route | Vanilla NPCs Remaining | Status |
| :--- | :---: | :--- |
| **S.S. Minnow / S.S. Anne** | 1 | ⚠️ 1 Vanilla NPCs |
| **Vermilion City** | 18 | ⚠️ 18 Vanilla NPCs |
| **Route 11** | 14 | ⚠️ 14 Vanilla NPCs |
| **Route 12** | 12 | ⚠️ 12 Vanilla NPCs |
| **Fishing Village** | 0 | ✅ Clean (0 Vanilla) |
| **Lavender Town** | 31 | ⚠️ 31 Vanilla NPCs |
| **Fuchsia City** | 22 | ⚠️ 22 Vanilla NPCs |

---

## S.S. Minnow / S.S. Anne

### Cabin 6 (Arbor's Quarters)

#### Map: `SSAnne_1F_Room6`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `WOMAN_2` | (11,11) | `SSAnne_1F_Room6_EventScript_Woman` | "You look tired. Would you like to" |

## Vermilion City

### Vermilion City (Overworld)

#### Map: `VermilionCity`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 4 | `Pokémon` | `MACHOP` | (41,11) | `VermilionCity_EventScript_Machop` | MACHOP cry | "MACHOP: Guoh! Gogogoh!" |
| 6 | `Human NPC` | `SAILOR` | (28,33) | `VermilionCity_EventScript_FerrySailor` | "Welcome to the S.S. ANNE!" |
| 7 | `Human NPC` | `SCIENTIST` | (40,14) | `VermilionCity_EventScript_OaksAide` | "Oh, hello, !" |

### Pokémon Fan Club

#### Map: `VermilionCity_PokemonFanClub`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `GENTLEMAN` | (5,4) | `VermilionCity_PokemonFanClub_EventScript_Chairman` | "I chair the POKéMON Fan Club!" |
| 2 | `Human NPC` | `WORKER_F` | (6,4) | `VermilionCity_PokemonFanClub_EventScript_WorkerF` | "Our CHAIRMAN is very vocal about" |
| 3 | `Pokémon` | `PIKACHU` | (7,6) | `VermilionCity_PokemonFanClub_EventScript_Pikachu` | PIKACHU cry | "PIKACHU: Chu! Pikachu!" |
| 4 | `Pokémon` | `SEEL` | (4,6) | `VermilionCity_PokemonFanClub_EventScript_Seel` | SEEL cry | "SEEL: Kyuoo!" |
| 5 | `Human NPC` | `WOMAN_1` | (4,5) | `VermilionCity_PokemonFanClub_EventScript_Woman` | "I just adore my SEEL!" |
| 6 | `Human NPC` | `FAT_MAN` | (7,5) | `VermilionCity_PokemonFanClub_EventScript_FatMan` | "Won't you admire my PIKACHU's" |

### House 1 (Fishing Guru)

#### Map: `VermilionCity_House1`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `FISHER` | (4,5) | `VermilionCity_House1_EventScript_FishingGuru` | "I'm the FISHING GURU!" |

### House 2 (Trade House)

#### Map: `VermilionCity_House2`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `LITTLE_GIRL` | (4,4) | `VermilionCity_House2_EventScript_Elyssa` | Script: VermilionCity_House2_EventScript_Elyssa |

### House 3 (Pidgey Mail)

#### Map: `VermilionCity_House3`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `BOY` | (7,4) | `VermilionCity_House3_EventScript_Boy` | "I'm getting my PIDGEY to fly a" |
| 2 | `Pokémon` | `PIDGEY` | (2,5) | `VermilionCity_House3_EventScript_Pidgey` | PIDGEY cry | "PIDGEY: Kurukkoo!" |
| 4 | `Human NPC` | `LASS` | (2,4) | `VermilionCity_House3_EventScript_Lass` | "I want to exchange MAIL with all" |

### Vermilion Mart

#### Map: `VermilionCity_Mart`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CLERK` | (2,3) | `VermilionCity_Mart_EventScript_Clerk` | Poké Mart shopkeeper | "Hi, there!" |
| 2 | `Human NPC` | `COOLTRAINER_F` | (4,2) | `VermilionCity_Mart_EventScript_CooltrainerF` | "I think POKéMON can be good or" |
| 3 | `Human NPC` | `BALDING_MAN` | (9,4) | `VermilionCity_Mart_EventScript_BaldingMan` | "There are wicked people who will" |

### Vermilion Gym

#### Map: `VermilionCity_Gym`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `GYM_GUY` | (4,12) | `VermilionCity_Gym_EventScript_GymGuy` | "Yo!" |

## Route 11

### Route 11 (Overworld)

#### Map: `Route11`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Trainer` | `YOUNGSTER` | (20,11) | `Route11_EventScript_Eddie` | Battle [YOUNGSTER_EDDIE]: "Let's go, but don't cheat!" |
| 2 | `Trainer` | `OLD_MAN_1` | (25,3) | `Route11_EventScript_Hugo` | Battle [GAMER_HUGO]: "Win, lose, or draw!" |
| 3 | `Trainer` | `YOUNGSTER` | (27,8) | `Route11_EventScript_Dillon` | Battle [YOUNGSTER_DILLON]: "I just became a TRAINER." |
| 4 | `Trainer` | `YOUNGSTER` | (35,6) | `Route11_EventScript_Dave` | Battle [YOUNGSTER_DAVE]: "I raised my POKéMON carefully." |
| 5 | `Trainer` | `OLD_MAN_1` | (41,12) | `Route11_EventScript_Jasper` | Battle [GAMER_JASPER]: "Competition!" |
| 6 | `Trainer` | `OLD_MAN_1` | (55,7) | `Route11_EventScript_Darian` | Battle [GAMER_DARIAN]: "I have never won before…" |
| 7 | `Trainer` | `BALDING_MAN` | (41,3) | `Route11_EventScript_Braxton` | Battle [ENGINEER_BRAXTON]: "Careful!" |
| 8 | `Trainer` | `YOUNGSTER` | (55,12) | `Route11_EventScript_Yasu` | Battle [YOUNGSTER_YASU]: "I'm the best in my class." |
| 9 | `Trainer` | `OLD_MAN_1` | (57,16) | `Route11_EventScript_Dirk` | Battle [GAMER_DIRK]: "Fwahaha!" |
| 10 | `Trainer` | `BALDING_MAN` | (31,17) | `Route11_EventScript_Bernie` | Battle [ENGINEER_BERNIE]: "Watch out for live wires!" |

### East Gatehouse

#### Floor: 1F (`Route11_EastEntrance_1F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `POLICEMAN` | (6,2) | `Route11_EastEntrance_1F_EventScript_TopGuard` | "Don't you think it's hard to think" |
| 2 | `Human NPC` | `POLICEMAN` | (4,10) | `Route11_EastEntrance_1F_EventScript_BottomGuard` | "If you're aiming to reach LAVENDER" |

#### Floor: 2F (`Route11_EastEntrance_2F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `YOUNGSTER` | (7,3) | `Route11_EastEntrance_2F_EventScript_Turner` | Script: Route11_EastEntrance_2F_EventScript_Turner |
| 2 | `Human NPC` | `SCIENTIST` | (2,6) | `Route11_EastEntrance_2F_EventScript_Aide` | "Hi! Remember me?" |

## Route 12

### Route 12 (Overworld)

#### Map: `Route12`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Trainer` | `FISHER` | (16,30) | `Route12_EventScript_Ned` | Battle [FISHERMAN_NED]: "Yeah!" |
| 2 | `Trainer` | `FISHER` | (18,96) | `Route12_EventScript_Chip` | Battle [FISHERMAN_CHIP]: "Be patient." |
| 3 | `Trainer` | `FISHER` | (18,90) | `Route12_EventScript_Hank` | Battle [FISHERMAN_HANK]: "The FISHING FOOL versus POKéMON" |
| 4 | `Trainer` | `FISHER` | (17,64) | `Route12_EventScript_Elliot` | Battle [FISHERMAN_ELLIOT]: "I love fishing, don't get me wrong." |
| 5 | `Pokémon` | `SNORLAX` | (9,68) | `Route12_EventScript_Snorlax` | Script: Route12_EventScript_Snorlax |
| 6 | `Trainer` | `ROCKER` | (14,80) | `Route12_EventScript_Luca` | Battle [ROCKER_LUCA]: "Electricity is my specialty." |
| 7 | `Trainer` | `CAMPER` | (10,99) | `Route12_EventScript_Justin` | Battle [CAMPER_JUSTIN]: "I'm searching for a MOON STONE." |
| 8 | `Trainer` | `FISHER` | (18,108) | `Route12_EventScript_Andrew` | Battle [FISHERMAN_ANDREW]: "What's catching?" |
| 11 | `Trainer` | `BEAUTY` | (19,59) | `Route12_EventScript_Gia` | Battle [YOUNG_COUPLE_GIA_JES]: "GIA: Hey, JES…" |

### North Gatehouse

#### Floor: 1F (`Route12_NorthEntrance_1F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `POLICEMAN` | (1,5) | `Route12_NorthEntrance_1F_EventScript_Guard` | "There's a lookout spot upstairs." |

#### Floor: 2F (`Route12_NorthEntrance_2F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `LASS` | (7,5) | `Route12_NorthEntrance_2F_EventScript_Lass` | "received TM27" |

### Fishing House (Super Rod Guru)

#### Map: `Route12_FishingHouse`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `FISHER` | (4,4) | `Route12_FishingHouse_EventScript_FishingGuruBrother` | "I'm the FISHING GURU's younger" |

## Fishing Village

*All NPCs in this area have been replaced with custom Solid-Oak scripts or are clean.*

## Lavender Town

### House 1 (Cubone's House)

#### Map: `LavenderTown_House1`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `COOLTRAINER_F` | (4,4) | `LavenderTown_House1_EventScript_CooltrainerF` | "Those horrible ROCKETS!" |
| 2 | `Pokémon` | `CUBONE` | (8,6) | `LavenderTown_House1_EventScript_Cubone` | CUBONE cry | "CUBONE: Kyarugoo!" |

### House 2 (Name Rater)

#### Map: `LavenderTown_House2`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `GENTLEMAN` | (4,4) | `LavenderTown_House2_EventScript_NameRater` | "Hello, hello!" |

### Lavender Mart

#### Map: `LavenderTown_Mart`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CLERK` | (2,3) | `LavenderTown_Mart_EventScript_Clerk` | Poké Mart shopkeeper | "Hi, there!" |
| 2 | `Human NPC` | `BALDING_MAN` | (6,2) | `LavenderTown_Mart_EventScript_BaldingMan` | "I'm searching for items that raise" |
| 3 | `Human NPC` | `ROCKER` | (9,2) | `LavenderTown_Mart_EventScript_Rocker` | "Did you buy some REVIVES?" |
| 4 | `Human NPC` | `YOUNGSTER` | (9,5) | `LavenderTown_Mart_EventScript_Youngster` | "Sometimes, a TRAINER duo will" |

### Pokémon Tower

#### Floor: 1F (`PokemonTower_1F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `WORKER_F` | (18,13) | `PokemonTower_1F_EventScript_WorkerF` | "POKéMON TOWER was erected in the" |
| 2 | `Human NPC` | `CHANNELER` | (18,9) | `PokemonTower_1F_EventScript_Channeler` | "I am a CHANNELER." |
| 3 | `Human NPC` | `WOMAN_2` | (15,6) | `PokemonTower_1F_EventScript_Woman1` | "My GROWLITHE…" |
| 4 | `Human NPC` | `WOMAN_3` | (7,8) | `PokemonTower_1F_EventScript_Woman2` | "Did you come to pay respects?" |
| 5 | `Human NPC` | `BALDING_MAN` | (8,12) | `PokemonTower_1F_EventScript_BaldingMan` | "I came to pray for my dearly" |

#### Floor: 2F (`PokemonTower_2F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 2 | `Human NPC` | `CHANNELER` | (3,7) | `PokemonTower_2F_EventScript_Channeler` | "Even we could not identify the" |

#### Floor: 3F (`PokemonTower_3F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CHANNELER` | (10,14) | `PokemonTower_3F_EventScript_Patricia` | "The others above…" |
| 2 | `Human NPC` | `CHANNELER` | (9,9) | `PokemonTower_3F_EventScript_Carly` | "Sorry!" |
| 3 | `Human NPC` | `CHANNELER` | (12,4) | `PokemonTower_3F_EventScript_Hope` | "The ghosts can be identified by" |

#### Floor: 4F (`PokemonTower_4F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CHANNELER` | (17,7) | `PokemonTower_4F_EventScript_Laurel` | "We can't determine the identity of" |
| 2 | `Human NPC` | `CHANNELER` | (15,13) | `PokemonTower_4F_EventScript_Jody` | "May the departed POKéMON rest in" |
| 3 | `Human NPC` | `CHANNELER` | (4,12) | `PokemonTower_4F_EventScript_Paula` | "I must have been dreaming…" |

#### Floor: 5F (`PokemonTower_5F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CHANNELER` | (11,4) | `PokemonTower_5F_EventScript_Ruth` | "I was possessed." |
| 2 | `Human NPC` | `CHANNELER` | (19,7) | `PokemonTower_5F_EventScript_Tammy` | "I was under possession." |
| 3 | `Human NPC` | `CHANNELER` | (7,12) | `PokemonTower_5F_EventScript_Karina` | "I regained my senses." |
| 4 | `Human NPC` | `CHANNELER` | (11,16) | `PokemonTower_5F_EventScript_Janae` | "I fell to evil spirits despite my" |
| 5 | `Human NPC` | `CHANNELER` | (12,8) | `PokemonTower_5F_EventScript_Channeler` | "Come, child!" |

#### Floor: 6F (`PokemonTower_6F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CHANNELER` | (13,10) | `PokemonTower_6F_EventScript_Angelica` | "I feel anemic and weak…" |
| 2 | `Human NPC` | `CHANNELER` | (18,6) | `PokemonTower_6F_EventScript_Jennifer` | "What's going on here?" |
| 3 | `Human NPC` | `CHANNELER` | (9,6) | `PokemonTower_6F_EventScript_Emilia` | "My hair didn't fall out!" |

#### Floor: 7F (`PokemonTower_7F`)

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `MR_FUJI` | (11,4) | `PokemonTower_7F_EventScript_MrFuji` | "MR. FUJI: Heh?" |
| 2 | `Human NPC` | `ROCKET_M` | (9,10) | `PokemonTower_7F_EventScript_Grunt1` | "I'm not going to forget this!" |
| 3 | `Human NPC` | `ROCKET_M` | (13,8) | `PokemonTower_7F_EventScript_Grunt2` | "POKéMON are only good for making" |
| 4 | `Human NPC` | `ROCKET_M` | (9,6) | `PokemonTower_7F_EventScript_Grunt3` | "You're not getting away with this!" |

## Fuchsia City

### Fuchsia City (Overworld)

#### Map: `FuchsiaCity`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `OLD_MAN_1` | (36,20) | `FuchsiaCity_EventScript_OldMan` | "The SAFARI ZONE has a zoo in front" |

### House 1 (Bill's Grandfather)

#### Map: `FuchsiaCity_House1`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `OLD_MAN_1` | (7,4) | `FuchsiaCity_House1_EventScript_OldMan` | "Hmm?" |
| 2 | `Human NPC` | `WOMAN_2` | (1,2) | `FuchsiaCity_House1_EventScript_Woman` | "The SAFARI ZONE's WARDEN is old," |
| 3 | `Human NPC` | `LITTLE_BOY` | (2,5) | `FuchsiaCity_House1_EventScript_LittleBoy` | "BILL files his own POKéMON data on" |

### House 3 (Move Deleter)

#### Map: `FuchsiaCity_House3`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `BALDING_MAN` | (4,4) | `FuchsiaCity_House3_EventScript_MoveDeleter` | "Uh…" |

### Fuchsia Mart

#### Map: `FuchsiaCity_Mart`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `CLERK` | (2,3) | `FuchsiaCity_Mart_EventScript_Clerk` | Poké Mart shopkeeper | "Hi, there!" |
| 2 | `Human NPC` | `GENTLEMAN` | (6,3) | `FuchsiaCity_Mart_EventScript_Gentleman` | "Don't they have any pennants" |
| 3 | `Human NPC` | `COOLTRAINER_F` | (9,5) | `FuchsiaCity_Mart_EventScript_CooltrainerF` | "Did you try X SPEED?" |

### Fuchsia Gym

#### Map: `FuchsiaCity_Gym`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `ROCKER` | (12,16) | `FuchsiaCity_Gym_EventScript_Kayden` | "So, you mix brawn with brains?" |
| 2 | `Human NPC` | `ROCKER` | (2,9) | `FuchsiaCity_Gym_EventScript_Shawn` | "Where there is light, there is" |
| 3 | `Human NPC` | `ROCKER` | (11,11) | `FuchsiaCity_Gym_EventScript_Kirk` | "Even though I've lost, I will keep" |
| 4 | `Human NPC` | `MAN` | (13,4) | `FuchsiaCity_Gym_EventScript_Edgar` | "I still have much to learn." |
| 5 | `Human NPC` | `MAN` | (4,6) | `FuchsiaCity_Gym_EventScript_Phil` | "You impressed me!" |
| 6 | `Human NPC` | `ROCKER` | (2,16) | `FuchsiaCity_Gym_EventScript_Nate` | "I like poison and sleep techniques," |
| 7 | `Human NPC` | `KOGA` | (7,13) | `FuchsiaCity_Gym_EventScript_Koga` | "When afflicted by TOXIC, a POKéMON" |
| 8 | `Human NPC` | `GYM_GUY` | (11,19) | `FuchsiaCity_Gym_EventScript_GymGuy` | "Yo!" |

### Warden's House

#### Map: `FuchsiaCity_WardensHouse`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `OLD_MAN_2` | (3,5) | `FuchsiaCity_WardensHouse_EventScript_Warden` | "WARDEN: Hif fuff hefifoo!" |

### Safari Zone Entrance

#### Map: `FuchsiaCity_SafariZone_Entrance`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 2 | `Human NPC` | `WORKER_M` | (1,6) | `FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant` | "Hi! Is it your first time here at" |

### Safari Zone Office

#### Map: `FuchsiaCity_SafariZone_Office`

| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |
| :-: | :---: | :--- | :-: | :--- | :--- |
| 1 | `Human NPC` | `WORKER_M` | (2,2) | `FuchsiaCity_SafariZone_Office_EventScript_Worker2` | "WARDEN SLOWPOKE is very" |
| 2 | `Human NPC` | `WORKER_M` | (12,3) | `FuchsiaCity_SafariZone_Office_EventScript_Worker3` | "WARDEN SLOWPOKE came in, but" |
| 3 | `Human NPC` | `WORKER_M` | (6,4) | `FuchsiaCity_SafariZone_Office_EventScript_Worker1` | "We nicknamed the WARDEN" |
| 4 | `Human NPC` | `WORKER_M` | (10,8) | `FuchsiaCity_SafariZone_Office_EventScript_Worker4` | "WARDEN SLOWPOKE is running a" |
