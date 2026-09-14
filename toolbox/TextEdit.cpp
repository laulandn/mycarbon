
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

#include <TextEdit.h>


////////////////////////////////////////////////////////////////////////////////
// TextEdit
////////////////////////////////////////////////////////////////////////////////

void TEInit() {
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'TEInit()' not implemented!\n");
}


void TEActivate(TEHandle hTE) { carbon_notimp_msg("*** TEActivate()' not implemented!\n"); }


void TEClick(Point pt, Boolean fExtend, TEHandle h) { carbon_notimp_msg("*** TEClick()' not implemented!\n"); }


void TECopy(TEHandle hTE) { carbon_notimp_msg("*** TECopy()' not implemented!\n"); }


void TECut(TEHandle hTE) { carbon_notimp_msg("*** TECut()' not implemented!\n"); }


void TEDeactivate(TEHandle hTE) { carbon_notimp_msg("*** TEDeactivate()' not implemented!\n"); }


void TEDelete(TEHandle hTE) { carbon_notimp_msg("*** TEDelete()' not implemented!\n"); }


void TEIdle(TEHandle hTE) { carbon_notimp_msg("*** TEIdle()' not implemented!\n"); }


void TEKey(short key, TEHandle hTE) { carbon_notimp_msg("*** TEKey()' not implemented!\n"); }


TEHandle TENew(const Rect *destRect, const Rect *viewRect) { carbon_notimp_msg("*** TENew()' not implemented!\n"); return NULL; }


void TEPaste(TEHandle hTE) { carbon_notimp_msg("*** TEPaste()' not implemented!\n"); }


void TEUpdate(const Rect *rUpdate, TEHandle hTE) { carbon_notimp_msg("*** TEUpdate()' not implemented!\n"); }


void TEAutoView(Boolean fAuto, TEHandle hTE) { carbon_notimp_msg("*** TEAutoView()' not implemented!\n"); }


void TEDispose(TEHandle hTE) { carbon_notimp_msg("*** TEDispose()' not implemented!\n"); }


OSErr TEFromScrap(void) { carbon_notimp_msg("*** TEFromScrap()' not implemented!\n"); return noErr; }


OSErr TEToScrap(void) { carbon_notimp_msg("*** TEToScrap()' not implemented!\n"); return noErr; }


long TEGetScrapLength(void) { carbon_notimp_msg("*** TEGetScrapLength()' not implemented!\n"); return 0; }


CharsHandle TEGetText(TEHandle hTE) { carbon_notimp_msg("*** TEGetText()' not implemented!\n"); return NULL; }


void TEScroll(short dh, short dv, TEHandle hTE) { carbon_notimp_msg("*** TEScroll()' not implemented!\n"); }


}
