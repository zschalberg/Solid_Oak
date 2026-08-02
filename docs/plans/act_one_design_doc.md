# Act One Design Document
## Pokémon Solid Oak — Opening Sequence

**Status:** Draft for review. No code has been written.  
**Branch:** `act-one-opening-sequence`  
**Bible version:** v2.6

Entries marked `[PROPOSED]` are creative decisions filling bible gaps. Each one is a specific proposal, not a placeholder — review and redirect as needed before implementation.

---

## Scene Coverage

1. [Arbor's Cabin — SS Minnow](#1-arbors-cabin--ss-minnow)
2. [Disembarkation — Vermillion Harbor](#2-disembarkation--vermillion-harbor)
3. [Vermillion City](#3-vermillion-city)
4. [Route 11 — East Corridor](#4-route-11--east-corridor)
5. [Route 12 — North Pass (First Trip)](#5-route-12--north-pass-first-trip)
6. [Lavender Town — Arrival](#6-lavender-town--arrival)
7. [Fuji Meeting — Krabby Quest](#7-fuji-meeting--krabby-quest)
8. [Route 12 South — Krabby Catching + Fishing Village](#8-route-12-south--krabby-catching--fishing-village)
9. [Fuchsia City — Reserve Introduction](#9-fuchsia-city--reserve-introduction)
10. [Zone 1 Trigger — Return North](#10-zone-1-trigger--return-north)
11. [Flags & Variables](#11-flags--variables)

---

## 1. Arbor's Cabin — SS Minnow

**Maps:** `SSMinnow_1F` (corridor) → `SSAnne_1F_Room6` (cabin)  
**What's already built:** Agatha corridor cutscene (walks player to Room 6), starter selection mechanics for all three Pokémon, Agatha's decline and exit. These work and don't need to be replaced — only the dialogue needs revision.

### [PROPOSED] Arbor's Characterization

The bible (v2.3) defines Arbor as a stats-focused, active battler whose specialty is IVs and EVs — a foil to Fuji. He recruited Oak and Agatha because their early values matched his own, and he genuinely approves of Oak's eventual path even though it diverges from his. He retires to Cinnabar during the time jump.

**Proposed take:** Arbor talks about Pokémon the way a good coach talks about athletes — with attention and respect, but always through the lens of what they're capable of. He notices things: the specific way a Growlithe holds its weight, what that implies about its speed ceiling. He doesn't do this coldly. He does it because it's a form of caring. His warmth is real; it just expresses itself through specificity rather than sentiment. He's old enough to have seen a lot, patient enough to explain it once, and privately certain that data doesn't lie.

He chose these three Pokémon deliberately. That should come through.

### Cabin Scene — Revised Dialogue

**Arbor intro** (replaces current bare-bones text):

> "Ah. There you both are."
>
> "We'll be in Vermillion Harbor inside the hour. I want you ready."
>
> "You've both read the reports, so I'll be brief. Kanto is seeing Pokémon — Johto species, Hoenn species — in locations they have no business being in. Migration patterns that don't match any model we have. Something is moving them."
>
> "Your assignment: find out what."
>
> "To do that, you'll need a partner Pokémon."
>
> "I've given this some thought. There are three on the table. I'll let you look them over before you decide — but Oak, the choice is yours first."

**When player approaches each Pokémon**, the existing `showmonpic` + `playmoncry` + `MSGBOX_YESNO` flow already works well. I'd add a short Arbor note per Pokémon, either as the `msgbox` text or as a preceding beat:

- **Growlithe:** `"Loyal, aggressive, and faster than it looks. Good for someone who likes to work up front."`
- **Nidoran (M):** `"Versatile. Moves it can learn now won't look like much — but watch what it becomes. If you're patient."`
- **Exeggcute:** `"Unusual choice. Needs more maintenance than the other two. But if you understand how to use it, you'll catch people off guard every time."`

These are not hard pushes — just Arbor briefly reading each one aloud as the player approaches. They characterize him without railroading the choice.

**After Oak confirms his pick:**

> "Good. Take care of it. Whatever you're planning to do out there, your partner's condition will matter more than you think."

This is Arbor: not "I'm so proud of you," not "What a wonderful Pokémon!" — just a specific, practical note of approval.

**Agatha's decline** (existing dialogue is solid, minor polish):

Current: *"Oh, no thanks, Professor. All of these ones look a bit too weak for me. I'll go out and get one for myself."*

This works. One optional addition — a beat where Arbor doesn't argue:

> **Arbor:** "Alright. Don't take too long."

A single line. He's not dismissing her; he's giving her the same latitude he'd give anyone he trusts. This is also better than him just staring as she leaves.

**Arbor — after Agatha exits:**

> "She'll be fine. She always is."
>
> "We'll be docking soon. Gather your things. I'll find you in the city once you're off the ship."

This sets up Arbor appearing briefly in Vermillion after disembarkation (a low-key establishing beat — not a major cutscene).

---

## 2. Disembarkation — Vermillion Harbor

**Map:** `SSAnne_Exterior` → `VermilionCity`  
**Trigger:** After `FLAG_SYS_POKEMON_GET` is set and the Room 6 scene ends

This should be brief. The player exits the ship, steps onto the dock, and the city opens up. No long cutscene — just enough to land the arrival.

**Disembark scene (VermilionCity ON_FRAME, state 0):**

Player walks down the gangway onto Vermillion dock. Arbor appears behind them on the dock — not yet warped away, just present for a short exchange.

> **Arbor:** "Vermillion. Hasn't changed much."
>
> *(beat — he looks at the half-finished building across the harbor)*
>
> "Head north when you're ready. I've arranged a room at the hotel — ask at the desk, they'll have it. I need to check in with the harbor office first."
>
> "Good luck, Oak."

He doesn't walk off dramatically. He just turns back toward the ship. That's it. The player now has the city.

`VAR_ACT1_VERMILLION` set to 1. Arbor is removed from the dock after this exchange (not seen again until Fuchsia, where he briefly appears to set up the research turn-in system with Fuji).

---

## 3. Vermillion City

**Map:** `VermilionCity`  
**Principle:** Every NPC expresses something about reconstruction-era Kanto through behavior and observation, never through direct statement. The war is felt in what's unfinished, what's missing, and what people choose to talk about instead.

### Hotel (Pokémon Center map, NPC-only change)

The heal desk NPC is a hotel clerk. Dialogue:

> "Professor Arbor's party? Yes, we have you in the book."
>
> "Your rooms are covered. Rest as long as you need."

Standard party heal happens. The building is still called a Pokémon Center internally; the NPC's words do the work.

A second NPC in the lobby (flavor):

> "Third week staying here. My building's still not done. At least the Machop crew's fast."
>
> "Or I thought they were. Now I hear they need more lumber. I've stopped asking."

### Street NPCs

**Near the harbor (south of city):**

**Dockworker (older man, facing the water):**
> "Second ship this month out of Johto. Used to be we'd see maybe two a year."
>
> *(pause)*
>
> "Strange time to be traveling, if you ask me. But I guess someone's got to."

He doesn't explain why it's strange. He just says it.

**Young sailor unloading cargo:**
> "You just get in? Nice ship. We came up from Fuschia last week — my first time north of Route 13."
>
> "Tell you what, there's something off about the water down there. Fish acting weird. My uncle says not to worry about it."

Foreshadowing the fishing village situation, via a character who explicitly says not to worry.

**Center of city:**

**Woman at a market stall (hand-painted sign, selling apricorns and basic goods):**
> "Fresh in. Lure Apricorns if you need them — not many people asking right now, but that's usually when it's worth having some."

She's all business. No drama. Optional purchase interaction.

**Construction worker on scaffolding (calling down):**
> "Watch where you're walking down there! We're behind schedule and I can't afford another incident."
>
> *(if talked to again)*
>
> "Building was half-done when we took it over. Previous crew left everything. Don't ask me why."

He doesn't say why the previous crew left. He doesn't need to.

**Child near the fountain:**
> "There's a Psyduck in there! See it? It's not supposed to be here — Daddy says Psyduck are from up north."
>
> "I named him Gerald."

[PROPOSED] This is the first time the player sees a displaced Pokémon before anyone explains the migration crisis. It's a child excited about a duck. The weight of what's happening is zero. That's the point.

**Near the Dojo (visible but gated until Zone 1):**

**Older trainer sitting on a crate outside:**
> "You thinking about going inside? Sensei Akio doesn't take just anyone."
>
> "Come back once you've seen some of what this region has going on. He says a trainer who hasn't been tested doesn't know what they need yet."

[PROPOSED] **Sensei Akio** is the Vermillion Dojo leader. Name only, not yet seen. His absence from the door communicates that the Dojo is present but not yet accessible — without a BLOCKED or LOCKED marker. The older trainer is the gate.

**Wandering NPC near Route 6 junction (north side of city):**
> "Saffron's been quieter than usual lately. They've got that big Silph building going up — takes half the workers from the other districts."
>
> "I'm not complaining. More work means more work."

Sets up Silph Co. in Saffron as a presence before the player can reach it.

### Signs

Existing signs (`VermilionCity_EventScript_CitySign`, `VermilionCity_EventScript_HarborSign`, `VermilionCity_EventScript_GymSign`) can stay; the gym sign references can be adjusted to Dojo during implementation. `VermilionCity_EventScript_SnorlaxNotice` — keep as-is (Route 12 Snorlax, lore-consistent).

---

## 4. Route 11 — East Corridor

**Map:** `Route11` (connects Vermillion east to Route 12)  
This is a short corridor. Two to three NPCs, lightly populated. Keep it brief — it's a transitional space.

**Young trainer on the path:**
> "You heading to Lavender? Keep an eye on the coast once you hit Route 12. Had a run-in with a Tentacool school yesterday that was way too big for this time of year."
>
> "Probably nothing. Still."

**Picnicker sitting on a rock:**
> "I used to come here to watch the Lickitung. Haven't seen one in weeks. My brother says they moved south."
>
> "Maybe the weather. Who knows."

**Route sign (bg_event):**  
`"Route 11 — Vermillion City is to the west. Lavender Town can be reached via Route 12 to the north."`

---

## 5. Route 12 — North Pass (First Trip)

**Map:** `Route12`  
**Player direction:** South from Route 11 entry point (Y≈60), then north to Lavender (Y≈0).

The existing map.json has several fishers (Ned at Y=30, Elliot at Y=64, Gia at Y=59, Chip at Y=96, Hank at Y=90) and a Camper and Rocker in the southern section. The northernmost trainers (Ned, Elliot, Gia) are accessible on the first pass north to Lavender.

### Existing Trainer Dialogue

Trainers Ned, Elliot, Gia, Luca, Justin, Hank, Chip, Andrew already exist in `map.json` with scripts assigned but no dialogue written. Their post-battle dialogue should carry the tone.

**Ned (Fisher, Y=30 — closest to Lavender on first pass):**
> *(Before battle)* "Hold up. Catch test. You want to pass through, you catch."
>
> *(Post-battle)* "Not bad. Hey, you notice the Krabby lately? They're coming up this far north when they shouldn't be. Used to be you'd only see them down near Route 13."

This plants the Krabby situation one location before it becomes a quest.

**Elliot (Fisher, Y=64 — around Route 11 junction):**
> *(Before battle)* "I'm not losing to someone who doesn't know how to use the current."
>
> *(Post-battle)* "Fine. Fine. Look, if you're heading north — it's open. But be back before dark if you can help it. The water's been strange."

**Gia (Beauty, Y=59):**
> "This part of the route used to have Goldeen everywhere. Now I barely see one."
>
> "Something's changed. I don't know what."

*(Not a trainer battle — standard MSGBOX_NPC)*

### Route 12 North Entrance Building

The entrance building (`MAP_ROUTE12_NORTH_ENTRANCE_1F`) is a small shelter. One NPC inside:

**Lookout (warden type):**
> "Lavender's up ahead. Town's been quiet — that researcher, Fuji, has been out at the waterline more than his office lately."
>
> "If you're looking for him, try the building on the south end of town."

Sets the expectation for where to find Fuji.

---

## 6. Lavender Town — Arrival

**Map:** `LavenderTown`  
**Tone:** Quiet, old, slightly somber. Not gothic or oppressive — just a town that's been here a long time and feels it. The Pokémon Tower is present and visible. The unusual Pokémon activity is subtle here.

### Town NPCs

**Woman near the north entrance:**
> "Researcher? If you mean Mr. Fuji, his office is south, near the base of the hill. He's been expecting someone from the mainland."

**Man near the Tower path:**
> "I'd stay away from the Tower for now if I were you. The Channelers say it's been unsettled lately. More than usual."
>
> "I used to think that was just something they said. Not anymore."

[PROPOSED] **Channeler NPC at Tower entrance (optional talk, not blocking):**
> "The spirits here are old. Most of them are at rest."
>
> *(pause)*
>
> "Most."

She doesn't explain further. She's not there to deliver plot — she's there to establish that the Tower has texture before the Gengar questline makes it relevant.

**Child (outside a house):**
> "Papa says there's a Gastly near the Tower. I want to see it but Mama says no."
>
> "Are you going to catch it?"

`[PROPOSED]` This is Agatha's Gastly — already there, already caught before Oak arrives. The child missed it. This is a tiny, unannounced confirmation that Agatha has been ahead of Oak the whole time.

**Shopkeeper (Mart):**
> "Research Balls? I carry them. Fuji order has us stocked."
>
> "He said someone would be coming through."

Research Balls available at Lavender Mart from the start. [PROPOSED] This is the first mart the player reaches — making Research Balls purchasable before the Krabby quest is assigned.

---

## 7. Fuji Meeting — Krabby Quest

**Map:** `LavenderTown_VolunteerPokemonHouse`  
**Characters present:** Oak, Fuji, Agatha (present, then departs immediately)

Fuji gifts Research Balls to both Oak and Agatha here. Agatha takes hers and leaves; Oak stays to hear the full explanation.

### Fuji Introduction Scene

[PROPOSED] **Fuji** is a careful, unhurried man. He doesn't perform concern — he just carries it. His connection to Pokémon is specific and personal, not abstract. He noticed the migration crisis because he pays attention to what he sees outside his window, not because he ran a model. His dialogue should feel like something a person says, not something a character delivers.

The Volunteer House's existing ambient NPCs (kids, Nidorino, Psyduck wandering freely) do Fuji's characterization silently before he speaks. This is a house full of Pokémon people left behind, looked after without fanfare. The player sees it before they hear anything.

**Scene trigger:** Player enters the Volunteer House for the first time. Agatha is already inside.

**Fuji:**

> "Good. You're both here."
>
> "I've been watching the waterline south of here for six months. Krabby coming up in numbers that don't belong this far north. Something is pushing them."
>
> "I need specimens to understand what."

He gives both Oak and Agatha 2 Research Balls each.

> "Catch two Krabby. Route 12 south of the junction, or Route 13 if you need more room. Don't worry about which ones — size, condition, none of that matters yet."
>
> "I'll be in Fuchsia when you're done. Meet me there."

**Agatha** (takes her balls, already half out the door):

> "I'll get a head start."

She's gone. No ceremony.

**Fuji** (watching her go, then back to Oak):

> "She came by two hours before you did. Already knew where the Krabby would be."

Not impressed, not dismissive. Just a fact.

> "There's something I can only show you in person. Don't take too long."

He doesn't follow Agatha out. He stays.

**If player talks to Fuji again before leaving:**
> "South end of Route 12, or Route 13. You'll find them."
>
> "I'll see you in Fuchsia."

**Ambient NPCs in the building** (existing objects, new dialogue):

**Little girl:**
> "Mr. Fuji lets us come visit the Pokémon. Mama says it's good for them to see people."

**Youngster:**
> "That Psyduck showed up last week. Mr. Fuji says it came from up north somewhere. He's keeping it until it's ready."

**Little boy:**
> "The Nidorino is my favorite. He doesn't like strangers but he likes me."

These replace the FireRed-specific lines (Poké Flute, FLAG_RESCUED_MR_FUJI) while keeping the same NPC objects.

---

## 8. Route 12 South — Krabby Catching + Fishing Village

**Map:** `Route12` (south of Route 11 junction, toward Route 13)  
**Player direction:** South from Route 11 entry point

The Krabby encounter area is south of the Route 11 connection — accessible once the player heads back from Lavender.

### Krabby Quest NPCs

The southern trainers (Chip, Hank, Andrew, Luca, Justin) are accessible on this return trip. Their battle dialogue is standard, but post-battle texts can layer in the fishing village tension:

**Chip (Fisher, Y=96):**
> *(Post-battle)* "You're heading south? Be careful near the village. The Tentacool have been biting the lines. Not biting — just... staying. Dozens of them. Just sitting there."

**Hank (Fisher, Y=90):**
> *(Post-battle)* "Haven't been able to cast past the Silence Bridge in three days. Too many of 'em."

**Andrew (Fisher, Y=108):**
> *(Post-battle)* "My family's been fishing this stretch since before I was born. I've never seen anything like this."

### Fishing Village (Route 12/13 area — pre-Zone 1)

The player passes through the village on their first southbound trip and again on the return to Fuchsia. At this point, Zone 1 has NOT triggered — the village is tense but intact.

**Village NPC 1 (dockside):**
> "You here to fish? Not the best time for it. The Tentacool have been thick all week."
>
> "It's not just the count — they're moving different. More... together."

**Village NPC 2 (woman drying nets):**
> "My husband says it'll pass. He said that last week too."

**Village NPC 3 (older man, watching the water):**
> "Seen rough seasons before. This isn't rough. This is something else."

He doesn't elaborate. He doesn't need to.

[PROPOSED] **The fishing village is a Helgen** — the player walks through it twice before it becomes a crisis. On the first pass going south (before catching Krabby), it's background. On the second pass going back north (after Fuchsia), it's noticeably worse. On the third pass — the return from Fuchsia — Zone 1 triggers. The player has already met these people. That's the point.

**Between first and second village visits** (after catching Krabby, before Fuchsia), the village NPCs should update slightly:

**Village NPC 1 (updated):**
> "It's getting worse. Last night we couldn't even get a boat out."

**Village NPC 3 (updated):**
> "I'm starting to think my husband's wrong."

This escalation doesn't need a flag per NPC — it can be triggered by `VAR_ACT1_FUCHSIA` (set when Oak arrives in Fuchsia). Before that var is set, version 1. After, version 2.

---

## 9. Fuchsia City — Reserve Introduction

**Map:** `FuchsiaCity` (Reserve entrance / Fuji's Fuchsia building)  
**Characters present:** Fuji, Agatha (waiting), Oak. Arbor is not present.

Agatha has her two Krabby already. She caught them off-screen. She's been here long enough to look slightly impatient.

### Scene

**Agatha (on Oak's arrival):**
> "You're slow, Sammy."

She holds up her Research Balls — both used.

> "I got mine on the way down."

**Fuji:**
> "Bring both sets over here."

He looks at all four Krabby. He points to two of them — one from Oak, one from Agatha.

> "See these two? Same species. Same location. One is noticeably larger than the other."
>
> "That difference isn't random. It affects how they move, how hard they hit, how fast they recover."
>
> "This is the first thing I need you to understand about what we're doing here. Individual differences in Pokémon are real and they matter."

[PROPOSED] **This is the height/weight system tutorial.** Fuji introduces it as a research lens, not a gameplay mechanic. He's explaining why documenting individuals matters, which sets up both the turn-in system and the IV Scanner (which Agatha develops later as the same principle taken further).

**Fuji, on the Reserve:**
> "This land behind us has been set aside — a conservation agreement I've been working on for years. The idea is simple: we document the Pokémon that are being displaced, and we give them somewhere to go."
>
> "It's not much yet. But it grows with what we contribute."
>
> "These four Krabby will be the first."

He accepts the Research Ball catches.

**Agatha:**
> "How do you know they'll stay?"

**Fuji:**
> "They won't all stay. That's not the point."
>
> "The point is to give them the choice."

[PROPOSED] **This exchange is the theme in miniature.** Agatha is asking a practical, reasonable question. Fuji's answer isn't sentimental — it's philosophical. He gives Agatha something she can't argue with, but also doesn't agree with. Neither of them is wrong here. The player should feel that.

**Fuji, ending the scene:**
> "There's something happening at the fishing village on your way back. I've had reports for three days. I didn't want to say anything before you'd seen this first."
>
> "Go back the way you came. You'll see it."

**Agatha:**
> "Finally."

She's already moving.

---

## 10. Zone 1 Trigger — Return North

**Map:** `Route12` / Route 12/13 area  
**Trigger:** Player re-enters the fishing village area after `VAR_ACT1_FUCHSIA` is set  
**What happens:** Zone 1 scripting begins. The Tentacruel boss emerges. Village NPCs shift to emergency mode. This document ends here — Zone 1 itself is out of scope.

**Last pre-Zone-1 beat:**

As the player enters the village area from the south, one of the village NPCs from earlier runs toward them:

> "You're back — something's in the water. A big one. We can't get to the boats."

Then: Zone 1 script triggers.

---

## 11. Flags & Variables

### New vars/flags needed

| Name | Type | Purpose |
|---|---|---|
| `VAR_ACT1_SHIP` | VAR | SS Minnow scene state (already exists: `VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR`) |
| `VAR_ACT1_VERMILLION` | VAR | Vermillion arrival/Arbor dock scene state |
| `VAR_ACT1_LAVENDER` | VAR | Fuji intro scene state |
| `VAR_ACT1_FUCHSIA` | VAR | Reserve intro scene state (also gates village NPC version 2) |
| `FLAG_KRABBY_QUEST_GIVEN` | FLAG | Fuji has given the quest |
| `FLAG_KRABBY_QUEST_COMPLETE` | FLAG | Both Krabby turned in at Fuchsia |
| `FLAG_MET_FUJI` | FLAG | First Fuji conversation complete |

### Existing vars/flags to reuse

- `VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR` — already tracking cabin scene state
- `FLAG_SYS_POKEMON_GET` — already set on starter selection
- `FLAG_AGATHA_AND_JOURNAL` — already set to hide Agatha in corridor after cutscene
- `FLAG_HIDE_ROUTE_12_SNORLAX` — check if set at game start; if not, add to `ON_TRANSITION` for Route 12 until Zone 1 is resolved

---

## Open Questions Before Implementation

**1. ~~Route 12 Snorlax~~** — Resolved: Snorlax removed. `FLAG_HIDE_ROUTE_12_SNORLAX` set permanently (or object removed from map.json). Full Route 12 south section accessible.

**2. ~~Fuji's building location~~** — Resolved: `MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE`.

**3. ~~Fuchsia arrival~~** — Resolved: Routes 13–15 are accessible in Act One. Player travels Lavender → Route 12 south → Route 13 → Route 14 → Route 15 → Fuchsia..

**4. ~~Arbor in Fuchsia~~** — Resolved: Arbor is not present for the Reserve intro.

**5. ~~Research Ball sourcing~~** — Resolved: Fuji gifts 2 Research Balls to both Oak and Agatha at the Volunteer House. Quest completion checks turn-in count, not ball provenance.

---

## What Is NOT in This Document

- Zone 1 battle scripts (Tentacruel boss, resolution)
- Route 13/14/15 content (out of scope for Act One)
- Fuchsia City full NPC layer (only the Reserve intro scene is covered here)
- Hotel fee implementation (user confirmed this is handled separately)
- Saffron City content (gated until after Zone 1)
- Any content on the Vermillion Dojo challenge (gated until after Zone 1)
