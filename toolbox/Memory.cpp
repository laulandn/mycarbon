
#define DEBUG_OUT dBug
//#define ERR_OUT dBug
#define ERR_OUT std::cerr
//#define DEBUG_OUT *aNullStream
#define CONS_OUT std::cout
#define CONS_IN std::cin


#ifdef DEBUG_VERBOSE
//#undef DEBUG_VERBOSE
#endif


#include "../mycarbon_debug.h"


#include <iostream>


extern "C" {


// Only needed with some sets of mac headers...
//////#define false mac_false
//////#define true mac_true
#include <Types.h>
//////#undef false
//////#undef true

#include <Memory.h>
#include <Errors.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Memory
////////////////////////////////////////////////////////////////////////////////

void MaxApplZone(void) {
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'MaxApplZone()' not implemented!\n");
}


OSErr HandToHand(Handle *theHndl) {
  if(!theHndl) { carbon_warn_msg("*** mycarbon'HandToHand()' theHndl is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'HandToHand()' not implemented!\n");
  return memFullErr;
}


Handle NewHandle(Size byteCount)
{
  carbon_notimp_msg("*** NewHandle()' not implemented!\n");
  return NULL;
}


void BlockMove(const void *srcPtr, void *destPtr, Size byteCount)
{
  carbon_notimp_msg("*** BlockMove()' not implemented!\n");
}


void DisposeHandle(Handle h)
{
  carbon_notimp_msg("*** DisposeHandle()' not implemented!\n");
}


THz ApplicationZone(void) { carbon_notimp_msg("*** ApplicationZone()' not implemented!\n"); return NULL; }


void DisposePtr(Ptr p)
{
  carbon_notimp_msg("*** DisposePtr()' not implemented!\n");
}


Ptr GetApplLimit(void) { carbon_notimp_msg("*** GetApplLimit()' not implemented!\n"); return NULL; }


Size GetHandleSize(Handle h)
{
  carbon_notimp_msg("*** GetHandleSize()' not implemented!\n");
  return 0;
}


Ptr NewPtr(Size byteCount) { carbon_notimp_msg("*** NewPtr()' not implemented!\n"); return NULL; }


void PurgeSpace(long *total, long *contig) { carbon_notimp_msg("*** PurgeSpace()' not implemented!\n"); }


long FreeMem(void) { carbon_notimp_msg("*** FreeMem()' not implemented!\n"); return 0; }


THz GetZone(void) { carbon_notimp_msg("*** GetZone()' not implemented!\n"); return NULL; }


void HLock(Handle h)
{
  carbon_notimp_msg("*** HLock()' not implemented!\n");
}


void HUnlock(Handle h)
{
  carbon_notimp_msg("*** HUnlock()' not implemented!\n");
}


Size MaxMem(Size *grow) { carbon_notimp_msg("*** MaxMem()' not implemented!\n"); return 0; }


void SetZone(THz hz) { carbon_notimp_msg("*** SetZone()' not implemented!\n"); }


THz SystemZone(void) { carbon_notimp_msg("*** SystemZone()' not implemented!\n"); return NULL; }


OSErr MemError(void) { carbon_notimp_msg("*** MemError()' not implemented!\n"); return noErr; }


void SetHandleSize(Handle h, Size newSize)
{
  carbon_notimp_msg("*** SetHandleSize()' not implemented!\n");
}


void SetApplLimit(void *zoneLimit) { carbon_notimp_msg("*** SetApplLimit()' not implemented!\n"); }


}
