
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
#include <Windows.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// globals
////////////////////////////////////////////////////////////////////////////////

n_display *the_n_display=NULL;
// Only one window for now...
n_window *the_n_window=NULL;


// Only a single one for now...
WindowRef theMacCWindowRef=NULL;
CWindowRecord theMacCWindow;
BOOL theMacCWindowInited=FALSE;

extern void myCarbon_initPixMap(PixMap *pm);
//extern void myCarbon_initGrafPort(GrafPort *gp);
extern void myCarbon_initCGrafPort(CGrafPort *cgp);
extern void myCarbon_initGDevice(GDevice *gd);
extern void myCarbon_printrect(const char *label,const Rect *r);


////////////////////////////////////////////////////////////////////////////////
// my Windows internals
////////////////////////////////////////////////////////////////////////////////

// NOTE: Only inits, does NOT fill in valid values!
void myCarbon_initCWindowRecord(CWindowRecord *cwr)
{
  carbon_debug_msg("(mycarbon myCarbon_initCWindowRecord)\n");
  if(theMacCWindowInited) {
    carbon_warn_msg("(mycarbon myCarbon_initCWindowRecord already set!)\n");
    return;
  }
  memset(cwr,0,sizeof(CWindowRecord));
	myCarbon_initCGrafPort(&cwr->port);
	cwr->windowKind=0;
	cwr->visible=true;
	cwr->hilited=true;
	cwr->goAwayFlag=true;
	cwr->spareFlag=false;
	cwr->strucRgn=NULL;
	cwr->contRgn=NULL;
	cwr->updateRgn=NULL;
	cwr->windowDefProc=NULL;
	cwr->dataHandle=NULL;
	cwr->titleHandle=NULL;
	cwr->titleWidth=0;
	cwr->controlList=NULL;
	cwr->nextWindow=NULL;
	cwr->windowPic=NULL;
	cwr->refCon=0;
  theMacCWindowInited=TRUE;
}


////////////////////////////////////////////////////////////////////////////////
// Windows
////////////////////////////////////////////////////////////////////////////////

void InitWindows() {
  carbon_debug_msg("(mycarbon InitWindows)\n");
  open_nlibs(0,NULL);
}


WindowRef NewWindow(void *wStorage, const Rect *boundsRect, ConstStr255Param title, Boolean visible, short theProc, WindowRef behind, Boolean goAwayFlag, long refCon)
{
  carbon_debug_msg("(mycarbon NewWindow)\n");
  if(!boundsRect) { carbon_warn_msg("*** mycarbon'NewWindow()' boundsRect is NULL!\n"); exit(EXIT_FAILURE); }
  unsigned int w,h;
  open_nlibs(0,NULL);
  //
  myCarbon_printrect("boundsRect",boundsRect);
  w=boundsRect->right-boundsRect->left;
  if(!w) w=the_n_display->width;
  h=boundsRect->bottom-boundsRect->top;
  if(!h) w=the_n_display->height;
  //
  the_n_window=open_window(the_n_display,(const char *)title+1,w,h);
  if(!the_n_window) { carbon_warn_msg("*** mycarbon In NewWindow, open_window failed!\n"); exit(EXIT_FAILURE); }
  the_n_display=the_n_window->parent;
  //
  myCarbon_initCWindowRecord(&theMacCWindow);
  theMacCWindowRef=(WindowRef)&theMacCWindow;  // Is this type coercion ok?
  //
  unsigned int np=the_n_display->nPlanes;
  unsigned int d=the_n_display->depth;
  unsigned int rowBytes=0;
  if(np>1) rowBytes=the_n_window->width/8;
  else {
    rowBytes=the_n_window->width*d;
  }
  unsigned int planeSize=rowBytes*the_n_window->height;
  //
  CGrafPort *theWinPort=&theMacCWindow.port;
  theWinPort->portRect.right=the_n_window->width;
  theWinPort->portRect.bottom=the_n_window->height;
  myCarbon_printrect("theMacCWindow.port.portRect",&theWinPort->portRect);
  PixMapPtr mypmp=NULL;
  if(theMacCWindow.port.portPixMap) {
    mypmp=*theMacCWindow.port.portPixMap;
    mypmp->bounds.right=the_n_window->width;
    mypmp->bounds.bottom=the_n_window->height;
    mypmp->rowBytes=rowBytes;
    mypmp->planeBytes=planeSize;
    mypmp->pixelSize=d;
    myCarbon_printrect("mypmp->bounds",&mypmp->bounds);
  }
  //
  carbon_debug_msg("*** mycarbon NewWindow done.\n");
  return theMacCWindowRef;
}


WindowRef NewCWindow(void *wStorage, const Rect *boundsRect, ConstStr255Param title, Boolean visible, short procID, WindowRef behind, Boolean goAwayFlag, long refCon)
{
  carbon_debug_msg("(mycarbon NewCWindow)\n");
  // NOTE: Mixing procID and theProc...
  return NewWindow(wStorage,boundsRect,title,visible,procID,behind,goAwayFlag,refCon);
}


void DisposeWindow(WindowRef theWindow)
{
  carbon_notimp_msg("*** mycarbon'DisposeWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'DisposeWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void DragWindow(WindowRef theWindow, Point startPt, const Rect *boundsRect)
{
  carbon_notimp_msg("*** mycarbon'DragWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'DragWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


short FindWindow(Point thePoint, WindowRef *theWindow)
{
  carbon_notimp_msg("*** mycarbon'FindWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'FindWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


WindowRef FrontWindow()
{
  carbon_notimp_msg("*** mycarbon'FrontWindow()' not implemented!\n");
  return 0;
}


long GrowWindow(WindowRef theWindow, Point startPt, const Rect *bBox)
{
  carbon_notimp_msg("*** mycarbon'GrowWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'GrowWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
  return 0;
}


void MoveWindow(WindowRef theWindow, short hGlobal, short vGlobal, Boolean front)
{
  carbon_notimp_msg("*** mycarbon'MoveWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'MoveWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void SelectWindow(WindowRef theWindow)
{
  carbon_notimp_msg("*** mycarbon'SelectWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'SelectWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void ShowWindow(WindowRef theWindow)
{
  //carbon_notimp_msg("*** mycarbon'ShowWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'ShowWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void SizeWindow(WindowRef theWindow, short w, short h, Boolean fUpdate)
{
  carbon_notimp_msg("*** mycarbon'SizeWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'SizeWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void ZoomWindow(WindowRef theWindow, short partCode, Boolean front)
{
  carbon_notimp_msg("*** mycarbon'ZoomWindow()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'ZoomWindow()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void BeginUpdate(WindowRef theWindow)
{
  carbon_notimp_msg("*** BeginUpdate()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'BeginUpdate()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


void DrawGrowIcon(WindowRef theWindow)
{
  //carbon_notimp_msg("*** DrawGrowIcon()' not implemented!\n");
  // ok to skip
}


void EndUpdate(WindowRef theWindow)
{
  carbon_notimp_msg("*** EndUpdate()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'EndUpdate()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean TrackBox(WindowRef theWindow, Point thePt, short partCode)
{
  carbon_notimp_msg("*** TrackBox()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'TrackBox()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE;
}


Boolean TrackGoAway(WindowRef theWindow, Point thePt)
{
  carbon_notimp_msg("*** TrackGoAway()' not implemented!\n");
  if(!theWindow) { carbon_warn_msg("*** mycarbon'TrackGoAway()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE;
}


WindowRef GetNewCWindow(short windowID, void *wStorage, WindowRef behind)
{
  carbon_notimp_msg("*** GetNewCWindow()' not implemented!\n");
  return NULL;
}


WindowRef GetNewWindow(short windowID, void *wStorage, WindowRef behind)
{
  carbon_notimp_msg("*** GetNewWindow()' not implemented!\n");
  return NULL;
}


void CloseWindow(WindowRef theWindow)
{
  carbon_notimp_msg("*** CloseWindow()' not implemented!\n");
}


UInt32 GetCaretTime(void)
{
  carbon_notimp_msg("*** GetCaretTime()' not implemented!\n");
  return 0;
}


}
