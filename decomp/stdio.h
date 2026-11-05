/*
    Codewarrior's standard library stdio functions
*/
#pragma once

#include <common.h>
#include <stdarg.h>

EXTERN_C()

int vsprintf(char * s, const char * format, va_list arg);

int ATTRIBUTE_FORMAT(printf, 3, 4) snprintf(char * dest, size_t n, const char * format, ...);
int ATTRIBUTE_FORMAT(printf, 2, 3) sprintf(char * dest, const char * format, ...);
int ATTRIBUTE_FORMAT(scanf, 2, 3) sscanf(const char * str, const char * format, ...);

EXTERN_C_END()
