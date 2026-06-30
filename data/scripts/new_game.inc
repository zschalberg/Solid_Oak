EventScript_ResetAllBerries::
	@ setberrytree BERRY_TREE_XXX_ORAN,  BERRY_ID_ORAN,  BERRY_STAGE_BERRIES
	return

EventScript_ResetAllMapFlags::
	setflag FLAG_0x02B
	setflag FLAG_0x02C
	setflag FLAG_0x033
	setflag FLAG_0x092
	setflag FLAG_0x035
	setflag FLAG_0x036
	setflag FLAG_0x037
	setflag FLAG_0x03C
	setflag FLAG_0x03D
	setflag FLAG_0x0A1
	setflag FLAG_0x03F
	setflag FLAG_0x04F
	setflag FLAG_0x05A
	setflag FLAG_0x0A3
	setflag FLAG_0x0A4
	setflag FLAG_0x062
	setflag FLAG_0x06B
	setflag FLAG_0x0A2
	setflag FLAG_0x08C
	setflag FLAG_0x06C
	setflag FLAG_0x06D
	setflag FLAG_0x06E
	setflag FLAG_0x06F
	setflag FLAG_0x075
	setflag FLAG_0x074
	setflag FLAG_0x07B
	setflag FLAG_0x07C
	setflag FLAG_0x07D
	setflag FLAG_0x076
	setflag FLAG_0x091
	setflag FLAG_0x097
	setflag FLAG_0x090
	setflag FLAG_0x094
	setflag FLAG_0x095
	setflag FLAG_0x096
	setflag FLAG_0x099
	setflag FLAG_0x0A5
	setflag FLAG_0x0A6
	setflag FLAG_0x0A7
	setflag FLAG_0x0A8
	setflag FLAG_0x0A9
	setflag FLAG_0x0AA
	setflag FLAG_0x0AB
	setflag FLAG_0x0AC
	setflag FLAG_0x09D
	setflag FLAG_0x09E
	setflag FLAG_0x09F
	setflag FLAG_0x0A0
	setflag FLAG_0x0AE
	setvar VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	call EventScript_ResetAllBerries
	end
