#pragma once

#include <common.h>
#include <spm/effdrv.h>

CPP_WRAPPER(spm::eff_spm_confetti)

USING(spm::effdrv::EffEntry)

EffEntry * effSpmConfettiEntry(f32 x, f32 y, f32 z, s32 p4, s32 p5);

CPP_WRAPPER_END()
