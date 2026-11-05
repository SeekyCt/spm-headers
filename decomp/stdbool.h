#pragma once

#include <common.h>

EXTERN_C()

#ifndef __cplusplus

#ifdef M2C
    #define bool char
#else
    #define bool _Bool
#endif

#define true 1
#define false 0

#endif

EXTERN_C_END()
