
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


#include <Types.h>

#ifdef Status
#undef Status
#endif

#include <Devices.h>


////////////////////////////////////////////////////////////////////////////////
// Devices
////////////////////////////////////////////////////////////////////////////////


short OpenDeskAcc(ConstStr255Param deskAccName)
{
  carbon_notimp_msg("*** mycarbon'OpenDeskAcc()' not implemented!\n"); 
  if(!deskAccName) { carbon_warn_msg("*** mycarbon'OpenDeskAcc()' deskAccName is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


void CloseDeskAcc(short refNum)
{
  carbon_notimp_msg("*** mycarbon'CloseDeskAcc()' not implemented!\n"); 
}


}
