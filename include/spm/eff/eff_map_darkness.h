#pragma once

#include <common.h>
#include <evt_cmd.h>

#include <spm/effdrv.h>

CPP_WRAPPER(spm::eff_map_darkness)

USING(spm::effdrv::EffEntry)

typedef struct {
/* 0x000 */ u16 minGSW0;
/* 0x002 */ u16 chapterSizes[9];
} MapDarknessParamEntry;
SIZE_ASSERT(MapDarknessParamEntry, 0x14)

typedef struct {
/* 0x000 */ u32 field0_0x0;
/* 0x004 */ s32 field1_0x4;
/* 0x008 */ u8 unknown_0x8[0x930 - 0x8];
/* 0x930 */ bool shouldVoidGrow;
/* 0x931 */ u8 field2259_0x931;
/* 0x932 */ u8 field2260_0x932;
/* 0x933 */ u8 field2261_0x933;
/* 0x934 */ u8 field2262_0x934;
/* 0x935 */ u8 field2263_0x935;
/* 0x936 */ u8 field2264_0x936;
/* 0x937 */ u8 field2265_0x937;
/* 0x938 */ float field2266_0x938;
/* 0x93c */ float field2267_0x93c;
/* 0x940 */ float field2268_0x940;
} EffMapDarknessBg;
SIZE_ASSERT(EffMapDarknessBg, 0x944)

extern char * voidMaps[8];
extern MapDarknessParamEntry mapDarknessEntries[29];

EffEntry * voidInit(s32 forcePresent);
void voidMain(EffEntry * MapDarknessEffGp);
u8 getVoidLevel(s32 param_1);

EVT_DECLARE_USER_FUNC(evt_map_darkness_grow_void, 0)
EVT_DECLARE_USER_FUNC(evt_map_darkness_soft_delete, 0)

CPP_WRAPPER_END()
