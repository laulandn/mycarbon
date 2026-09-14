
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

#include <stdlib.h>


extern "C" {


// Only needed with some sets of mac headers...
//////#define false mac_false
//////#define true mac_true
#include <Types.h>
//////#undef false
//////#undef true

#include <OSUtils.h>
#include <Gestalt.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// OSUtils
////////////////////////////////////////////////////////////////////////////////

void SysBeep(short l) {
  carbon_debug_msg("(mycarbon SysBeep)\n");
}


OSErr SysEnvirons(short n, SysEnvRec *e) {
  carbon_debug_msg("(mycarbon SysEnvirons)\n");
  if(!e) { carbon_warn_msg("*** mycarbon'SysEnvirons()' e is NULL!\n"); exit(EXIT_FAILURE); }
  e->environsVersion=curSysEnvVers;
  e->machineType=envMachUnknown;
  e->systemVersion=0x0700;
  e->processor=envCPUUnknown;
  e->hasFPU=true;
  e->hasColorQD=true;
  e->keyBoardType=envUnknownKbd;
  e->atDrvrVersNum=0;
  e->sysVRefNum=0;
  return 0;
}


void GetDateTime(unsigned long *secs)
{
  carbon_debug_msg("(mycarbon GetDateTime)\n");
  if(!secs) { carbon_warn_msg("*** mycarbon'GetDateTime()' secs is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'GetDateTime()' not implemented!\n");
  *secs=rand();
}


extern pascal UniversalProcPtr GetToolTrapAddress(UInt16 trapNum)
//UniversalProcPtr GetToolTrapAddress(SInt16 trapNum)
{
  carbon_notimp_msg("*** mycarbon'GetToolTrapAddress()' not implemented!\n");
  return NULL;
}


UniversalProcPtr NGetTrapAddress(UInt16 trapNum, TrapType tTyp)
{
  carbon_notimp_msg("*** NGetTrapAddress()' not implemented!\n");
  return NULL;
}


}
