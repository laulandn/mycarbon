
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
#include <ToolUtils.h>


////////////////////////////////////////////////////////////////////////////////
// ToolUtils
////////////////////////////////////////////////////////////////////////////////


Boolean BitTst(const void *bytePtr, long bitNum)
{
  carbon_notimp_msg("*** BitTst()' not implemented!\n");
  if(!bytePtr) { carbon_warn_msg("*** mycarbon'BitTst()' bytePtr is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE;
}


void BitClr(void *bytePtr, long bitNum)
{
  carbon_notimp_msg("*** BitClr()' not implemented!\n");
  if(!bytePtr) { carbon_warn_msg("*** mycarbon'BitClr()' bytePtr is NULL!\n"); exit(EXIT_FAILURE); }
}


void BitSet(void *bytePtr, long bitNum)
{
  carbon_notimp_msg("*** BitSet()' not implemented!\n");
  if(!bytePtr) { carbon_warn_msg("*** mycarbon'BitSet()' bytePtr is NULL!\n"); exit(EXIT_FAILURE); }
}


}
