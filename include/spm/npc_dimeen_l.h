#pragma once

#include <common.h>
#include <spm/npcdrv.h>

CPP_WRAPPER(spm::npc_dimeen_l)

USING(spm::npcdrv::NPCDefense)

extern NPCDefense superDimentioHeadDefenses;
extern NPCDefense superDimentioBodyDefenses;

EVT_DECLARE(dimen_unk_fight_script_1)
EVT_DECLARE(dimen_unk_fight_script_2)
EVT_DECLARE(dimen_unk_fight_script_3)

CPP_WRAPPER_END()
