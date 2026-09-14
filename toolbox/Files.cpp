
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

#include <Files.h>
#include <Errors.h>




#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Files
////////////////////////////////////////////////////////////////////////////////

OSErr OpenWD(short vRefNum, long dirID, long procID, short *wdRefNum) {
  if(!wdRefNum) { carbon_warn_msg("*** mycarbon'OpenWD()' wdRefNum is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'OpenWD()' not implemented!\n");
  return fnOpnErr;
}


OSErr CloseWD(short wdRefNum) {
  carbon_notimp_msg("*** mycarbon'CloseWD()' not implemented!\n");
  return fnOpnErr;
}


void GetFNum()
{
  carbon_notimp_msg("*** GetFNum()' not implemented!\n");
}


OSErr SetVol(ConstStr63Param volName, short vRefNum)
{
  carbon_notimp_msg("*** SetVol()' not implemented!\n");
  return noErr;
}


OSErr PBHGetVInfoSync(HParmBlkPtr paramBlock)
{
  carbon_notimp_msg("*** PBHGetVInfoSync()' not implemented!\n");
  if(!paramBlock) { carbon_warn_msg("*** mycarbon'PBHGetVInfoSync()' paramBlock is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}


OSErr PBGetFInfoSync(ParmBlkPtr paramBlock)
{
  carbon_notimp_msg("*** PBGetFInfoSync()' not implemented!\n");
  if(!paramBlock) { carbon_warn_msg("*** mycarbon'PBGetFInfoSync()' paramBlock is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}


OSErr PBGetVInfoSync(ParmBlkPtr paramBlock)
{
  carbon_notimp_msg("*** PBGetVInfoSync()' not implemented!\n");
  if(!paramBlock) { carbon_warn_msg("*** mycarbon'PBGetVInfoSync()' paramBlock is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}


OSErr PBWriteASync(ParmBlkPtr paramBlock)
{
  carbon_notimp_msg("*** PBWriteASync()' not implemented!\n");
  if(!paramBlock) { carbon_warn_msg("*** mycarbon'PBWriteASync()' paramBlock is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}


OSErr FSOpen(ConstStr255Param n, short int i, short int *i2)
{
  carbon_notimp_msg("*** FSOpen()' not implemented!\n");
  if(!n) { carbon_warn_msg("*** mycarbon'FSOpen()' n is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}


OSErr FSClose(short refNum)
{
  carbon_notimp_msg("*** FSClose()' not implemented!\n");
  return noErr;
}


OSErr FSRead(short refNum, long *count, void *buffPtr)
{
  carbon_notimp_msg("*** FSRead()' not implemented!\n");
  if(!count) { carbon_warn_msg("*** mycarbon'FSRead()' count is NULL!\n"); exit(EXIT_FAILURE); }
  if(!buffPtr) { carbon_warn_msg("*** mycarbon'FSRead()' buffPtr is NULL!\n"); exit(EXIT_FAILURE); }
  return noErr;
}



}
