
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

#include <Quickdraw.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Timer
////////////////////////////////////////////////////////////////////////////////


UInt8 LMGetCPUFlag()
{
  carbon_notimp_msg("*** mycarbon'LMGetCPUFlag()' not implemented!\n");
  return 0;
}


SInt32 LMDefltStack()
{
  carbon_notimp_msg("*** mycarbon'LMDefltStack()' not implemented!\n");
  return 0;
}


RgnHandle LMGetGrayRgn()
{
  carbon_notimp_msg("*** mycarbon'LMGetGrayRgn()' not implemented!\n");
  return NULL;
}


}

