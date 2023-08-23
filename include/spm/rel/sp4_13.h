#pragma once

#include <common.h>
#include <spm/evtmgr.h>
#include <spm/npcdrv.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::sp4_13)

char * returnCharAnimPos(char *param_1);
char * func_80c5c304(char *param_1);
EVT_DECLARE_USER_FUNC(func_80c5c36c, 0);

extern spm::npcdrv::NPCTribeAnimDef mrLTribeAnimDefs[10];
extern spm::npcdrv::NPCTribeAnimDef mrLTauntTribeAnimDefs[6];
extern spm::npcdrv::NPCTribeAnimDef theGreenThunderTribeAnimDefs[10];

EVT_DECLARE(mr_l_appear);
EVT_DECLARE(brobot_appear);
// more

CPP_WRAPPER_END()
