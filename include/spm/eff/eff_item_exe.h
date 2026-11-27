#include <common.h>
#include <spm/camdrv.h>
#include <spm/effdrv.h>
#include <wii/mtx.h>
#include <wii/gx.h>

CPP_WRAPPER(spm::item_exe)

USING(spm::camdrv::CameraId)
USING(spm::effdrv::EffEntry)
USING(spm::effdrv::EffTargetUnion)
USING(wii::mtx::Vec3)

struct EffItemExe {
/* 0x00 */ bool field0_0x0;
/* 0x01 */ u8 padding_0x1[0x4 - 0x1];
/* 0x04 */ s32 effSubDatId;
/* 0x08 */ s32 effSubDatId2;
/* 0x0C */ s32 numFrames;
/* 0x10 */ s32 scissorNo;
/* 0x14 */ s32 frmCtr;
/* 0x18 */ float scale;
/* 0x1C */ float zOffset;
/* 0x20 */ float zRotation1;
/* 0x24 */ float zRotation2;
/* 0x28 */ CameraId camId;
/* 0x2C */ Vec3 pos;
/* 0x38 */ Vec3 pos2;
/* 0x44 */ EffTargetUnion target;
};
SIZE_ASSERT(EffItemExe, 0x60)

// ...

EffEntry * effItemExeEntry(s32 variant);
void effItemExeSetTargetNPC(EffEntry * entry, s32 evtId, const char * name);

// ...

CPP_WRAPPER_END()
