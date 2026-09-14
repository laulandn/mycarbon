
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

#include <Sound.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

NumVersion myVersion;


////////////////////////////////////////////////////////////////////////////////
// Sound
////////////////////////////////////////////////////////////////////////////////

NumVersion SndSoundManagerVersion()
{
//#ifdef _LATITUDE_
//  myVersion=0;
//#else
/*
  myVersion.majorRev=0;
  myVersion.minorAndBugRev=0;
  myVersion.stage=0;
  myVersion.nonRelRev=0;
*/
//#endif
  return myVersion;
}


OSErr SndNewChannel(SndChannelPtr *chan, short synth, long init, SndCallBackUPP userRoutine)
{
  if(!chan) { carbon_warn_msg("*** mycarbon'SndNewChannel()' chan is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'SndNewChannel()' not implemented!\n");
  return 0;
}


OSErr SndDoImmediate(SndChannelPtr chan, const SndCommand *cmd)
{
  carbon_notimp_msg("*** mycarbon'SndDoImmediate()' not implemented!\n");
  if(!chan) { carbon_warn_msg("*** mycarbon'SndDoImmediate()' chan is NULL!\n"); exit(EXIT_FAILURE); }
  if(!cmd) { carbon_warn_msg("*** mycarbon'SndDoImmediate()' cmd is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


OSErr SndDisposeChannel(SndChannelPtr chan, Boolean quietNow)
{
  carbon_notimp_msg("*** mycarbon'SndDisposeChannel()' not implemented!\n");
  if(!chan) { carbon_warn_msg("*** mycarbon'SndDisposeChannel()' chan is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


OSErr SndDoCommand(SndChannelPtr chan, const SndCommand *cmd, Boolean noWait)
{
  if(!cmd) { carbon_warn_msg("*** mycarbon'SndDoCommand()' cmd is NULL!\n"); exit(EXIT_FAILURE); }
  if(!chan) { carbon_warn_msg("*** mycarbon'SndDoCommand()' chan is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'SndDoCommand()' not implemented!\n");
  return 0;
}


OSErr SndPlayDoubleBuffer(SndChannelPtr chan, SndDoubleBufferHeaderPtr theParams)
{
  carbon_notimp_msg("*** mycarbon'SndPlayDoubleBuffer()' not implemented!\n");
  if(!chan) { carbon_warn_msg("*** mycarbon'SndPlayDoubleBuffer()' chan is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


void GetSoundVol(short *level)
{
  carbon_notimp_msg("*** mycarbon'GetSoundVol()' not implemented!\n");
  if(!level) { carbon_warn_msg("*** mycarbon'GetSoundVol()' level is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetSoundVol(short level)
{
  carbon_notimp_msg("*** mycarbon'SetSoundVol()' not implemented!\n");
}


}


