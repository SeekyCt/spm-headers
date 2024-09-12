#pragma once

#include <common.h>

CPP_WRAPPER(spm::mario_status)

typedef enum MarioStatusType {
    STATUS_POISION=1,
    STATUS_SLOW=2,
    STATUS_NO_SKILLS=4,
    STATUS_NO_JUMP=8,
    STATUS_FLIPPED_CONTROLS=16,
    STATUS_HALF_DAMAGE=32,
    STATUS_DOUBLE_ATTACK=64,
    STATUS_ELECTRIFIED=128,
    STATUS_HP_REGEN=256,
    STATUS_BARRIER=512,
    STATUS_FAST_FLOWER=1024,
    STATUS_SLOW_FLOWER=2048,
    STATUS_COIN_FLOWER=4096,
    STATUS_PAL_PILLS=16384,
    STATUS_GHOST_SHROOM=32768,
    STATUS_DANGEROUS_DELIGHT=65536
} MarioStatusType;

void marioStatusApplyStatuses(MarioStatusType status, int lv);

CPP_WRAPPER_END()
