
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

#include <Resources.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Resources
////////////////////////////////////////////////////////////////////////////////

void CloseResFile(short refNum)
{
  carbon_notimp_msg("*** mycarbon'CloseResFile()' not implemented!\n");
}


short OpenResFile(ConstStr255Param fileName)
{
  carbon_notimp_msg("*** mycarbon'OpenResFile()' not implemented!\n");
  if(!fileName) { carbon_warn_msg("*** mycarbon'OpenResFile()' fileName is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


Handle GetResource(ResType theType, short theID)
{
  carbon_notimp_msg("*** GetResource()' not implemented!\n");
  return NULL;
}


void ChangedResource(Handle theResource)
{
  carbon_notimp_msg("*** ChangedResource()' not implemented!\n");
  if(!theResource) { carbon_warn_msg("*** mycarbon'ChangedResource()' theResource is NULL!\n"); exit(EXIT_FAILURE); }
}


void DetachResource(Handle theResource)
{
  carbon_notimp_msg("*** DetachResource()' not implemented!\n");
  if(!theResource) { carbon_warn_msg("*** mycarbon'DetachResource()' theResource is NULL!\n"); exit(EXIT_FAILURE); }
}


Handle GetIndResource(ResType theType, short index)
{
  carbon_notimp_msg("*** GetIndResource()' not implemented!\n");
  return NULL;
}


void ReleaseResource(Handle theResource)
{
  carbon_notimp_msg("*** ReleaseResource()' not implemented!\n");
  if(!theResource) { carbon_warn_msg("*** mycarbon'ReleaseResource()' theResource is NULL!\n"); exit(EXIT_FAILURE); }
}


void WriteResource(Handle theResource)
{
  carbon_notimp_msg("*** WriteResource()' not implemented!\n");
  if(!theResource) { carbon_warn_msg("*** mycarbon'WriteResource()' theResource is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetResLoad(Boolean load)
{
  carbon_notimp_msg("*** SetResLoad()' not implemented!\n");
}


}
