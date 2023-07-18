#pragma once

#include <common.h>
#include <spm/evtmgr.h>
#include <evt_cmd.h>

CPP_WRAPPER(spm::an2_08)

EVT_DECLARE(theParentOfBeginRPG);

EVT_DECLARE(finalRpgChild);
EVT_DECLARE(underchompAttack1);
EVT_DECLARE(underchompAttack2);
EVT_DECLARE(underchompAttack3);
EVT_DECLARE(checkWinOrContinue);
EVT_DECLARE(attacking);
EVT_DECLARE(usePixls);
EVT_DECLARE(useItems);
EVT_DECLARE(runningAway);

EVT_DECLARE(techChild1);
EVT_DECLARE(techChild2);

EVT_DECLARE_USER_FUNC(evt_unknown_pointer_change, 1);

CPP_WRAPPER_END()
