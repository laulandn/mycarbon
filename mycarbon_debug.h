#ifndef MYCARBON_DEBUG_H
#define MYCARBON_DEBUG_H


//#define MYCARBON_DEBUG 1
#define MYCARBON_WARN 1
#define MYCARBON_NOTIMP 1


#ifdef __cplusplus
extern "C" {
#include "../nlib/nlib.h"
#include "../nlib/nlibdbug.h"
};
#endif


#ifdef MYCARBON_WARN
void carbon_warn_msg(const char *s);
#else
#define carbon_warn_msg(x)
#endif


#ifdef MYCARBON_DEBUG
void carbon_debug_msg(const char *s);
#else
#define carbon_debug_msg(x)
#endif


#ifdef MYCARBON_NOTIMP
#define carbon_notimp_msg(x) debug_msg(x)
#else
#define carbon_notimp_msg(x)
#endif


#endif
