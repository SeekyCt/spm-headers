#include <common.h>
#include <spm/effdrv.h>
#include <wii/mtx.h>
#include <wii/gx.h>

CPP_WRAPPER(spm::eff_gonbaba)

USING(spm::effdrv::EffEntry)
USING(wii::mtx::Vec3)

// ...

typedef struct
{
/* 0x00 */ s32 type;
/* 0x04 */ Vec3 pos;
/* 0x10 */ u8 unknown_0x18[0x44 - 0x10];
/* 0x44 */ f32 direction;
/* 0x48 */ u8 unknown_0x48[0x58 - 0x48];
} EffGonbabaBreath;
SIZE_ASSERT(EffGonbabaBreath, 0x58)

EffEntry * effGonbabaEntry(f32 x, f32 y, f32 z, f32 scale, s32 type, s32 duration);

// ...

CPP_WRAPPER_END()
