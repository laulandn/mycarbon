
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

#include <Gestalt.h>
#include <Errors.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Gestalt
////////////////////////////////////////////////////////////////////////////////

OSErr Gestalt(OSType selector, long *response)
{
  carbon_debug_msg("(mycarbon Gestalt)\n");
  if(!response) { carbon_warn_msg("*** mycarbon'Gestalt()' response is NULL!\n"); exit(EXIT_FAILURE); }
  OSErr ret=gestaltUndefSelectorErr;  // gestaltUnknownErr or gestaltUndefSelectorErr?
  char s[5];
  BOOL done=FALSE;
  s[0]=(selector>>24)&0xff;
  s[1]=(selector>>16)&0xff;
  s[2]=(selector>>8)&0xff;
  s[3]=selector&0xff;
  s[4]=0;
  // TODO: Handle here...
  if(!done) {
    carbon_debug_msg("Gestalt \"");
    carbon_debug_msg(s);
    carbon_debug_msg("\" called...");
    carbon_debug_msg("ignoring.\n");
    *response=0;
  }
  return ret;
}


OSErr NewGestalt(OSType selector, SelectorFunctionUPP gestaltFunction)
{
  OSErr ret=gestaltUnknownErr;
  carbon_notimp_msg("*** NewGestalt()' not implemented!\n"); 
  return ret;
}


OSErr ReplaceGestalt(OSType selector, SelectorFunctionUPP gestaltFunction, SelectorFunctionUPP *oldGestaltFunction)
{
  OSErr ret=gestaltUnknownErr;
  carbon_notimp_msg("*** ReplaceGestalt()' not implemented!\n"); 
  return ret;
}


}
