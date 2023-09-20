#pragma once

#include <common.h>

CPP_WRAPPER(spm::evt_ac)

// evt_ac_entry(const char * name, s32 type)
EVT_DECLARE_USER_FUNC(evt_ac_entry, 2);

//evt_ac_name_to_ptr(const char * name, EvtVar storage)
EVT_DECLARE_USER_FUNC(evt_ac_name_to_ptr, 2)

//evt_ac_delete(const char * name)
EVT_DECLARE_USER_FUNC(evt_ac_delete, 1)

CPP_WRAPPER_END()
