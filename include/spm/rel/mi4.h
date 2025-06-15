#pragma once

#include <common.h>
#include <spm/evtmgr.h>
#include <wii/gx.h>

CPP_WRAPPER(spm::mi4)

USING(wii::gx::GXTexObj)

void mi4MimiHolographicEffect(GXTexObj * tex, spm::evtmgr::EvtEntry * evtEntry);
// more

CPP_WRAPPER_END()