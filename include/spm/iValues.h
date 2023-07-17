#include <spm/evtmgr.h>
#include <common.h>

namespace spm::iValues {

extern "C" {

extern const spm::evtmgr::EvtScriptCode theParentOfBeginRPG;
extern const spm::evtmgr::EvtScriptCode * finalRpgChild;
extern const spm::evtmgr::EvtScriptCode * underchompAttack1;
extern const spm::evtmgr::EvtScriptCode * underchompAttack2;
extern const spm::evtmgr::EvtScriptCode * underchompAttack3;
extern const spm::evtmgr::EvtScriptCode * checkWinOrContinue;
extern const spm::evtmgr::EvtScriptCode * attacking;
extern const spm::evtmgr::EvtScriptCode * usePixls;
extern const spm::evtmgr::EvtScriptCode * useItems;
extern const spm::evtmgr::EvtScriptCode * runningAway;

extern spm::evtmgr::EvtScriptCode * techChild1;
extern spm::evtmgr::EvtScriptCode * techChild2;
void techtext1();
void techtext2();
void rpgTribePatch1();
void rpgTribePatch2();
void underchompRepeatPatch();

}
}
