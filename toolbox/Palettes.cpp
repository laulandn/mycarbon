
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

#include <Palettes.h>


////////////////////////////////////////////////////////////////////////////////
// Palettes
////////////////////////////////////////////////////////////////////////////////

void RestoreDeviceClut(GDHandle gd) {
  carbon_notimp_msg("*** mycarbon'RestoreDeviceClut()' not implemented!\n");
  if(!gd) { carbon_warn_msg("*** mycarbon'RestoreDeviceClut()' gd is NULL!\n"); exit(EXIT_FAILURE); }
}


void AnimatePalette(WindowPtr dstWindow, CTabHandle srcCTab, short srcIndex, short dstEntry, short dstLength)
{
  carbon_notimp_msg("*** AnimatePalette()' not implemented!\n");
  if(!dstWindow) { carbon_warn_msg("*** mycarbon'AnimatePalette()' dstWindow is NULL!\n"); exit(EXIT_FAILURE); }
  if(!srcCTab) { carbon_warn_msg("*** mycarbon'AnimatePalette()' srcCTab is NULL!\n"); exit(EXIT_FAILURE); }
}


PaletteHandle GetPalette(WindowPtr srcWindow)
{
  carbon_notimp_msg("*** GetPalette()' not implemented!\n");
  if(!srcWindow) { carbon_warn_msg("*** mycarbon'GetPalette()' srcWindow is NULL!\n"); exit(EXIT_FAILURE); }
  return NULL;
}


void Palette2CTab(PaletteHandle srcPalette, CTabHandle dstCTab)
{
  carbon_notimp_msg("*** Palette2CTab()' not implemented!\n");
  if(!srcPalette) { carbon_warn_msg("*** mycarbon'Palette2CTab()' srcPalette is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstCTab) { carbon_warn_msg("*** mycarbon'Palette2CTab()' dstCTab is NULL!\n"); exit(EXIT_FAILURE); }
}


void PmForeColor(short dstEntry)
{
  carbon_notimp_msg("*** PmForeColor()' not implemented!\n");
}


void PmBackColor(short dstEntry)
{
  carbon_notimp_msg("*** PmBackColor()' not implemented!\n");
}
  
  
}
