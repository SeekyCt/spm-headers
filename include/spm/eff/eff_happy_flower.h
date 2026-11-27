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

typedef struct EffItemExe {
    bool field0_0x0;
    u8 padding_0x1[0x4 - 0x1];
    s32 effSubDatId;
    s32 effSubDatId2;
    s32 numFrames;
    s32 scissorNo;
    s32 frmCtr;
    float scale;
    float zOffset;
    float zRotation1;
    float zRotation2;
    CameraId camId;
    Vec3 pos;
    Vec3 pos2;
    EffTargetUnion target;
};
SIZE_ASSERT(EffItemExe, 0x60)

// ...

EffEntry * effItemExeEntry(s32 variant);
void effItemExeSetTargetNPC(EffEntry * entry, s32 evtId, const char * name);

// ...

CPP_WRAPPER_END()
