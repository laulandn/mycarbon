
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


#include "mycarbon_debug.h"

#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


#include <Quickdraw.h>
#include <QDOffscreen.h>


void myCarbon_initCGrafPort(CGrafPort *cgp);
PixMapPtr myCarbon_newPixMap(const Rect *r,unsigned int d);


////////////////////////////////////////////////////////////////////////////////
// QDOffscreen
////////////////////////////////////////////////////////////////////////////////


void DisposeGWorld(GWorldPtr offscreenGWorld)
{ 
  if(!offscreenGWorld) { carbon_warn_msg("*** mycarbon'DisposeGWorld()' offscreenGWorld is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** DisposeGWorld()' not implemented!\n"); 
}


PixMapHandle GetGWorldPixMap(GWorldPtr offscreenGWorld)
{
  if(!offscreenGWorld) { carbon_warn_msg("*** mycarbon'GetGWorldPixMap()' offscreenGWorld is NULL!\n"); exit(EXIT_FAILURE); }
  //carbon_notimp_msg("*** GetGWorldPixMap()' not implemented!\n"); 
  CGrafPtr cgp=(CGrafPtr)offscreenGWorld;
  return cgp->portPixMap; 
}


QDErr NewGWorld(GWorldPtr *gw, short PixelDepth, const Rect *boundsRect, CTabHandle cTable, GDHandle aGDevice, GWorldFlags flags) 
{ 
  if(!gw) { carbon_warn_msg("*** mycarbon'NewGWorld()' gw is NULL!\n"); exit(EXIT_FAILURE); }
  if(!boundsRect) { carbon_warn_msg("*** mycarbon'NewGWorld()' boundsRect is NULL!\n"); exit(EXIT_FAILURE); }
  if(!PixelDepth) { carbon_warn_msg("*** mycarbon'NewGWorld()' PixelDepth is 0!\n"); exit(EXIT_FAILURE); }
  //carbon_notimp_msg("*** NewGWorld()' not implemented!\n"); 
  *gw=(GWorldPtr)malloc(sizeof(CGrafPort));
  myCarbon_initCGrafPort(*gw);
  (*gw)->portRect.left=boundsRect->left;
  (*gw)->portRect.right=boundsRect->right;
  (*gw)->portRect.top=boundsRect->top;
  (*gw)->portRect.bottom=boundsRect->bottom;
  PixMapPtr *pm=(PixMapPtr *)malloc(sizeof(PixMapPtr));
  *pm=myCarbon_newPixMap(boundsRect,PixelDepth);
  (*gw)->portPixMap=pm;
  return noErr; 
}


void SetGWorld(CGrafPtr port, GDHandle gdh)
{
  if(!port) { carbon_warn_msg("*** mycarbon'SetGWorld()' port is NULL!\n"); exit(EXIT_FAILURE); }
  if(!gdh) { carbon_warn_msg("*** mycarbon'SetGWorld()' gdh is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** SetGWorld()' not implemented!\n"); 
}


GWorldFlags UpdateGWorld(GWorldPtr *offscreenGWorld, short pixelDepth, const Rect *boundsRect, CTabHandle cTable, GDHandle aGDevice, GWorldFlags flags)
{ 
  if(!offscreenGWorld) { carbon_warn_msg("*** mycarbon'UpdateGWorld()' color is NULL!\n"); exit(EXIT_FAILURE); }
  if(!boundsRect) { carbon_warn_msg("*** mycarbon'UpdateGWorld()' boundsRect is NULL!\n"); exit(EXIT_FAILURE); }
  if(!pixelDepth) { carbon_warn_msg("*** mycarbon'UpdateGWorld()' pixelDepth is 0!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** UpdateGWorld()' not implemented!\n"); 
  return noErr; 
}


}
