
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

#include <MixedMode.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// MixedMode
////////////////////////////////////////////////////////////////////////////////

/*
UniversalProcPtr NewRoutineDescriptor(ProcPtr theProc, ProcInfoType theProcInfo, ISAType theISA)
{
  if(!theProc) { carbon_warn_msg("*** mycarbon'NewRoutineDescriptor()' theProc is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'NewRoutineDescriptor()' not implemented!\n");
  return NULL;
}
*/

}
