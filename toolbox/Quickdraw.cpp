
#define DEBUG_OUT dBug
//#define ERR_OUT dBug
#define ERR_OUT std::cerr
//#define DEBUG_OUT *aNullStream
#define CONS_OUT std::cout
#define CONS_IN std::cin


#ifdef DEBUG_VERBOSE
//#undef DEBUG_VERBOSE
#endif


// NOTE: Doesn't work yet
#define REAL_QD_GLOBALS 1


#include "../mycarbon_debug.h"


#include <iostream>

#include <stdlib.h>


extern "C" {


// Only needed with some sets of mac headers...
//////#define false mac_false
//////#define true mac_true
#include <Types.h>
//////#undef false
//////#undef true

#include <Quickdraw.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// globals
////////////////////////////////////////////////////////////////////////////////

extern n_display *the_n_display;
// Only one window for now...
extern n_window *the_n_window;

unsigned int curX=0,curY=0;

short qderror=0;

GDevice theMacGDevice;
GDevice *theMacGDevicePtr=NULL;
BOOL theMacGDeviceInited=FALSE;


#ifdef REAL_QD_GLOBALS
// Quickdraw globals
// Privates...
long fontAdj=0;
Point patAlign;
short polyMax=0;
PolyHandle thePoly=NULL;
short playIndex=0;
PicHandle playPic=NULL;
short rgnMax=0;
short rgnIndex=0;
Handle rgnBuf=NULL;
mycarbonRegion wideData;
RgnPtr wideMaster=NULL;
RgnHandle wideOpen=NULL;
//
// Publics...
long randSeed=0;
BitMap screenBits;
mycarbonCursor arrow;
Pattern dkGray;
Pattern ltGray;
Pattern gray;
Pattern black;
Pattern white;
GrafPtr thePort=NULL;
#endif

QDGlobals qd;
BOOL qdInited=FALSE;


void myCarbon_printrect(const char *label,const Rect *r);
void myCarbon_rectSetDefault(Rect *r);

void myCarbon_initPixMap(PixMap *pm);
void myCarbon_initGDevice(GDevice *gd);
void myCarbon_initGrafPort(GrafPort *gp);
void myCarbon_initCGrafPort(CGrafPort *cgp);
PixMapPtr myCarbon_newPixMap(const Rect *r,unsigned int d);
bool myCarbon_isPixMap(const BitMap *bm);
bool myCarbon_isCGrafPort(const GrafPort *gp);

#ifdef REAL_QD_GLOBALS
void myCarbon_syncQDGlobals(QDGlobals *qdGlobals);
#endif

void myCarbon_syncGrafPortAndCGrafPort(CGrafPort *cgp);


////////////////////////////////////////////////////////////////////////////////
// my Quickdraw internals
////////////////////////////////////////////////////////////////////////////////

bool myCarbon_isPixMap(const BitMap *bm)
{
  bool ret=true;
  printf("rowBytes is %x\n",bm->rowBytes);
  if(bm->rowBytes&0xa000) ret=false;
  PixMap *pm=(PixMap *)bm;
  printf("pmVersion is %x\n",pm->pmVersion);
  printf("pmReserved is %lx\n",pm->pmReserved);
  if(!ret) printf("Not a PixMap...\n");
  return ret;
}


bool myCarbon_isCGrafPort(const GrafPort *gp)
{
  bool ret=true;
  CGrafPort *cgp=(CGrafPort *)cgp;
  printf("portVersion is %x\n",cgp->portVersion);
  if(cgp->portVersion<0x3ffe) ret=false;
  if(!ret) printf("Not a CGrafPort...\n");
  return ret;
}


#ifdef REAL_QD_GLOBALS
void myCarbon_sync_QDGlobals(QDGlobals *qdGlobals)
{
  carbon_debug_msg("(mycarbon myCarbon_sync_QDGlobals)\n");
  if(!qdGlobals) { carbon_warn_msg("*** mycarbon'myCarbon_sync_QDGlobals()' qdGlobals is NULL!\n"); exit(EXIT_FAILURE); }
  qdGlobals->screenBits.bounds.top=screenBits.bounds.top;
  qdGlobals->screenBits.bounds.bottom=screenBits.bounds.bottom;
  qdGlobals->screenBits.bounds.left=screenBits.bounds.left;
  qdGlobals->screenBits.bounds.right=screenBits.bounds.right;
  // TODO: sync arrow
  // TODO: sync dkGray...
  // TODO: sync ltGray...
  // TODO: sync gray...
  // TODO: sync black...
  // TODO: sync white...
  //thePort=(GrafPort *)&theMacCGrafPort;
  //myCarbon_initGrafPort(thePort);
  qdGlobals->thePort=thePort;
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_sync_QDGlobals qd.screenbits.bounds",&qd.screenBits.bounds);
  myCarbon_printrect("myCarbon_sync_QDGlobals screenbits.bounds",&screenBits.bounds);
#endif
}
#endif


// NOTE: Only inits, does NOT fill in valid values!
// ...but for now, set to old classic mac screen size...
void myCarbon_init_QDGlobals(QDGlobals *qdGlobals)
{
  carbon_debug_msg("(mycarbon myCarbon_init_QDGlobals)\n");
  if(!qdGlobals) { carbon_warn_msg("*** mycarbon'myCarbon_init_s()' qdGlobals is NULL!\n"); exit(EXIT_FAILURE); }
  if(qdInited) {
    carbon_warn_msg("(mycarbon qdInited already set!)\n");
    return;
  }
  memset(qdGlobals,0,sizeof(QDGlobals));
#ifdef REAL_QD_GLOBALS
  carbon_debug_msg("(REAL_QD_GLOBALS is set)\n");
  fontAdj=0;
  //patAlign;
  polyMax=0;
  thePoly=NULL;
  playIndex=0;
  playPic=NULL;
  rgnMax=0;
  rgnIndex=0;
  rgnBuf=NULL;
  //wideData;
  wideMaster=NULL;
  wideOpen=NULL;
  //
  randSeed=0;
  //
  //arrow
	//dkGray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT;
	//ltGray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT;
	//gray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT
	//black={ 0,0,0,0,0,0,0,0 };
	//white={ 255,255,255,255,255,255,255,255 };
  thePort=NULL;
  //
  screenBits.bounds.top=0;
  screenBits.bounds.bottom=384;
  screenBits.bounds.left=512;
  screenBits.bounds.right=0;
  myCarbon_rectSetDefault(&screenBits.bounds);
  if(the_n_display) { screenBits.bounds.right=the_n_display->width; screenBits.bounds.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_init_QDGlobals screenbits.bounds",&screenBits.bounds);
#endif
  myCarbon_sync_QDGlobals(&qd);
#else
  carbon_debug_msg("(REAL_QD_GLOBALS is NOT set)\n");
  /*
  qd.fontAdj=0;
  //qd.patAlign;
  qd.polyMax=0;
  qd.thePoly=NULL;
  qd.playIndex=0;
  qd.playPic=NULL;
  qd.rgnMax=0;
  qd.rgnIndex=0;
  qd.rgnBuf=NULL;
  //qd.wideData;
  qd.wideMaster=NULL;
  qd.wideOpen=NULL;
  */
  //
  qd.randSeed=0;
  //
  //qd.arrow
	//qd.dkGray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT;
	//qd.ltGray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT;
	//qd.gray={ 128,128,128,128,128,128,128,128 };  // THIS ISN't RIGHT
	//qd.black={ 0,0,0,0,0,0,0,0 };
	//qd.white={ 255,255,255,255,255,255,255,255 };
  qd.thePort=NULL;
  //
  qd.screenBits.bounds.top=0;
  qd.screenBits.bounds.bottom=384;
  qd.screenBits.bounds.left=512;
  qd.screenBits.bounds.right=0;
  myCarbon_rectSetDefault(&qd.screenBits.bounds);
  if(the_n_display) { qd.screenBits.bounds.right=the_n_display->width; qd.screenBits.bounds.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
#endif
  qdInited=TRUE;
  carbon_debug_msg("(myCarbon_init_QDGlobals done)\n");
}


// NOTE: Only inits, does NOT fill in valid values!
// ...but for now, set to old classic mac screen size...
void myCarbon_initPixMap(PixMap *pm)
{
  carbon_debug_msg("(mycarbon myCarbon_initPixMap)\n");
  if(!pm) { carbon_warn_msg("*** mycarbon'myCarbon_initPixMap()' pm is NULL!\n"); exit(EXIT_FAILURE); }
  memset(pm,0,sizeof(PixMap));
  pm->baseAddr=0;
  pm->rowBytes=0;  // ???
  //
  pm->bounds.top=0;
  pm->bounds.left=0;
  pm->bounds.right=0;
  pm->bounds.bottom=0;
  myCarbon_rectSetDefault(&pm->bounds);
  if(the_n_display) { pm->bounds.right=the_n_display->width; pm->bounds.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
  if(the_n_window) { pm->bounds.right=the_n_window->width; pm->bounds.bottom=the_n_window->height; }
  else carbon_debug_msg("no the_n_window, so used display?\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_initPixMap pm->bounds",&pm->bounds);
#endif
  //
  pm->pmVersion=1; // ???
  pm->packType=0;
  pm->packSize=0;
  pm->hRes=75;
  pm->vRes=75;
  pm->pixelType=1; // ???
  pm->pixelSize=1; // ???
  pm->cmpCount=4; // ???
  pm->cmpSize=1; // ???
  pm->planeBytes=0;
  pm->pmTable=NULL;
  pm->pmReserved=0;
  if(the_n_display) { pm->pixelSize=the_n_display->depth; }
  else carbon_debug_msg("no the_n_display!!!!\n");
}


// TODO: This init's it, not sync's it, needs to be done
void myCarbon_syncGrafPortAndCGrafPort(CGrafPort *cgp)
{
  carbon_debug_msg("(mycarbon myCarbon_syncGrafPortAndCGrafPort)\n");
  if(!cgp) { carbon_warn_msg("*** mycarbon'myCarbon_syncGrafPortAndCGrafPort()' gp is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_debug_msg("(mycarbon myCarbon_initGrafPort)\n");
  GrafPort *gp=(GrafPort *)cgp;
	gp->device=0;
  gp->portBits.baseAddr=0;
  gp->portBits.rowBytes=0;
  //
  gp->portBits.bounds.top=0;
  gp->portBits.bounds.left=0;
  gp->portBits.bounds.right=0;
  gp->portBits.bounds.bottom=0;
  myCarbon_rectSetDefault(&gp->portBits.bounds);
  if(the_n_display) { gp->portBits.bounds.right=the_n_display->width; gp->portBits.bounds.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
  if(the_n_window) { gp->portBits.bounds.right=the_n_window->width; gp->portBits.bounds.bottom=the_n_window->height; }
  else carbon_debug_msg("no the_n_window, so used display?\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_initGrafPort gp->portBits.bounds",&gp->portBits.bounds);
#endif
  //
	gp->visRgn=NULL;
	gp->clipRgn=NULL;
  unsigned int t=0;
  for(t=0;t<8;t++) gp->bkPat.pat[t]=0;
  for(t=0;t<8;t++) gp->fillPat.pat[t]=0;
  gp->pnLoc.h=0; gp->pnLoc.v=0;
	gp->pnSize.h=32; gp->pnSize.v=32;
	gp->pnMode=1; // ???
#ifdef __LATITUDE_LONG_ALIGNED__
  gp->filler1=0;
#endif
  for(t=0;t<8;t++) gp->pnPat.pat[t]=0;
	gp->pnVis=1;
	gp->txFont=1; // ???
	gp->txFace=1; // ???
	//gp->filler=0;
	gp->txMode=1; // ???
	gp->txSize=12;
	gp->spExtra=0;
	gp->fgColor=0;
	gp->bkColor=1;
	gp->colrBit=0; // ???
	gp->patStretch=0;
	gp->picSave=NULL;
	gp->rgnSave=NULL;
	gp->polySave=NULL;
	gp->grafProcs=NULL;
 
}


// NOTE: Only inits, does NOT fill in valid values!
// ...but for now, set to old classic mac screen size...
void myCarbon_initGrafPort(GrafPort *gp)
{
  carbon_debug_msg("(mycarbon myCarbon_initGrafPort)\n");
  if(!gp) { carbon_warn_msg("*** mycarbon'myCarbon_initGrafPort()' gp is NULL!\n"); exit(EXIT_FAILURE); }
  memset(gp,0,sizeof(GrafPort));
	gp->device=0;
  gp->portBits.baseAddr=0;
  gp->portBits.rowBytes=0;
  //
  gp->portBits.bounds.top=0;
  gp->portBits.bounds.left=0;
  gp->portBits.bounds.right=0;
  gp->portBits.bounds.bottom=0;
  myCarbon_rectSetDefault(&gp->portBits.bounds);
  if(the_n_display) { gp->portBits.bounds.right=the_n_display->width; gp->portBits.bounds.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
  if(the_n_window) { gp->portBits.bounds.right=the_n_window->width; gp->portBits.bounds.bottom=the_n_window->height; }
  else carbon_debug_msg("no the_n_window, so used display?\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_initGrafPort gp->portBits.bounds",&gp->portBits.bounds);
#endif
  //
	gp->visRgn=NULL;
	gp->clipRgn=NULL;
  unsigned int t=0;
  for(t=0;t<8;t++) gp->bkPat.pat[t]=0;
  for(t=0;t<8;t++) gp->fillPat.pat[t]=0;
  gp->pnLoc.h=0; gp->pnLoc.v=0;
	gp->pnSize.h=32; gp->pnSize.v=32;
	gp->pnMode=1; // ???
#ifdef __LATITUDE_LONG_ALIGNED__
  gp->filler1=0;
#endif
  for(t=0;t<8;t++) gp->pnPat.pat[t]=0;
	gp->pnVis=1;
	gp->txFont=1; // ???
	gp->txFace=1; // ???
	//gp->filler=0;
	gp->txMode=1; // ???
	gp->txSize=12;
	gp->spExtra=0;
	gp->fgColor=0;
	gp->bkColor=1;
	gp->colrBit=0; // ???
	gp->patStretch=0;
	gp->picSave=NULL;
	gp->rgnSave=NULL;
	gp->polySave=NULL;
	gp->grafProcs=NULL;
}


// NOTE: Only inits, does NOT fill in valid values!
// ...but for now, set to old classic mac screen size...
void myCarbon_initCGrafPort(CGrafPort *cgp)
{
  carbon_debug_msg("(mycarbon myCarbon_initCGrafPort)\n");
  if(!cgp) { carbon_warn_msg("*** mycarbon'myCarbon_initCGrafPort()' cgp is NULL!\n"); exit(EXIT_FAILURE); }
  memset(cgp,0,sizeof(CGrafPort));
  cgp->device=0;
  cgp->portPixMap=NULL;
  cgp->grafVars=NULL;
	cgp->portVersion=0xa000;
	cgp->chExtra=0;
	cgp->pnLocHFrac=0;
  //
  cgp->portRect.top=0;
  cgp->portRect.left=0;
  cgp->portRect.right=0;
  cgp->portRect.bottom=0;
  myCarbon_rectSetDefault(&cgp->portRect);
  if(the_n_display) { cgp->portRect.right=the_n_display->width; cgp->portRect.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
  if(the_n_window) { cgp->portRect.right=the_n_window->width; cgp->portRect.bottom=the_n_window->height; }
  else carbon_debug_msg("no the_n_window, so used display?\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_initCGrafPort cgp->portRect",&cgp->portRect);
#endif
  //
	cgp->bkPixPat=NULL;
  cgp->rgbFgColor.red=0x0000;  cgp->rgbFgColor.green=0x0000;  cgp->rgbFgColor.blue=0x0000;
  cgp->rgbBkColor.red=0xffff;  cgp->rgbBkColor.green=0xffff;  cgp->rgbBkColor.blue=0xffff;
	cgp->visRgn=NULL;
	cgp->clipRgn=NULL;
  cgp->pnLoc.h=0; cgp->pnLoc.v=0;
	cgp->pnSize.h=32; cgp->pnSize.v=32;
	cgp->pnMode=1;
	cgp->pnPixPat=NULL;
	cgp->fillPixPat=NULL;
	cgp->pnVis=1;
	cgp->txFont=1;
	cgp->txFace=1;
	//cgp->filler=0;
	cgp->txMode=1;
	cgp->txSize=12;
	cgp->spExtra=0;
	cgp->fgColor=0;
	cgp->bkColor=1;
	cgp->colrBit=0;
	cgp->patStretch=0;
	cgp->picSave=NULL;
	cgp->rgnSave=NULL;
	cgp->polySave=NULL;
	cgp->grafProcs=NULL;
  // So the struct is a both a lgeal GrafPort AND CGrafPort
  //myCarbon_initGrafPort((GrafPort *)cgp);
}


// NOTE: Only inits, does NOT fill in valid values!
// ...but for now, set to old classic mac screen size...
void myCarbon_initGDevice(GDevice *gd)
{
  carbon_debug_msg("(mycarbon myCarbon_initGDevice)\n");
  if(!gd) { carbon_warn_msg("*** mycarbon'myCarbon_initGDevice()' gd is NULL!\n"); exit(EXIT_FAILURE); }
  if(theMacGDeviceInited) {
    carbon_warn_msg("(mycarbon theMacGDeviceInited already set!)\n");
    return;
  }
  memset(gd,0,sizeof(GDevice));
  gd->gdRefNum=1;
  gd->gdID=1;
  gd->gdType=0; // is this index vs direct?
  gd->gdITable=NULL;
  gd->gdResPref=1; // ???
  gd->gdSearchProc=NULL;
  gd->gdCompProc=NULL;
  gd->gdFlags=1; // is this index vs direct?
  gd->gdRefCon=0;
  gd->gdNextGD=NULL;
  //
  gd->gdRect.top=0;
  gd->gdRect.left=0;
  gd->gdRect.right=0;
  gd->gdRect.bottom=0;
  myCarbon_rectSetDefault(&gd->gdRect);
  if(the_n_display) { gd->gdRect.right=the_n_display->width; gd->gdRect.bottom=the_n_display->height; }
  else carbon_debug_msg("no the_n_display!!!!\n");
  if(the_n_window) { gd->gdRect.right=the_n_window->width; gd->gdRect.bottom=the_n_window->height; }
  else carbon_debug_msg("no the_n_window, so used display?\n");
#ifdef MYCARBON_DEBUG
  myCarbon_printrect("myCarbon_initGDevice gd->gdRect",&gd->gdRect);
#endif
  unsigned int d=32;  // BAD BAD BAD BAD
  /*
  PixMapPtr *pm=(PixMapPtr *)malloc(sizeof(PixMapPtr));  
  *pm=myCarbon_newPixMap(boundsRect,PixelDepth);
  gd->gdPMap=pm;
  */
  gd->gdPMap=NULL;
  //
  gd->gdMode=1; // is this index vs direct?
  gd->gdCCBytes=0;
  gd->gdCCDepth=0;
  gd->gdCCXData=NULL;
  gd->gdCCXMask=NULL;
  gd->gdReserved=0;
  theMacGDeviceInited=TRUE;
}


void myCarbon_printrect(const char *label,const Rect *r)
{
//#ifdef MYCARBON_DEBUG
  //carbon_debug_msg("(mycarbon myCarbon_printrect)\n");
  if(!label) { carbon_warn_msg("*** myCarbon_printrect label is NULL!\n"); exit(EXIT_FAILURE); }
  if(!r) { carbon_warn_msg("*** myCarbon_printrect r is NULL!\n"); exit(EXIT_FAILURE); }
  debug_msg(label);
  debug_msg(" Rect is t,b,l,r ");
  debug_wxyz(r->top,r->bottom,r->left,r->right);
  debug_msg("\n");
//#endif
}


// Set some random rect to sane values...
void myCarbon_rectSetDefault(Rect *r)
{
  //carbon_debug_msg("(mycarbon mycarbon_rectSetDefault)\n");
  if(!r) { carbon_warn_msg("*** mycarbon_rectSetDefault r is NULL!\n"); exit(EXIT_FAILURE); }
  r->top=0;
  r->bottom=0;
  //if(the_n_window) r->bottom=the_n_window->height; else r->bottom=384;
  r->left=0;
  //if(the_n_window) r->right=the_n_window->width; else r->right=512;
  r->right=0;
  ////myCarbon_printrect("mycarbon_rectSetDefault r",r);
}


PixMapPtr myCarbon_newPixMap(const Rect *r,unsigned int d)
{
  if(!r) { carbon_warn_msg("*** myCarbon_newPixMap r is NULL!\n"); exit(EXIT_FAILURE); }
  PixMapPtr p=(PixMapPtr)malloc(sizeof(PixMap));
  if(!p) { carbon_warn_msg("*** myCarbon_newPixMap p is NULL!\n"); exit(EXIT_FAILURE); }
  myCarbon_initPixMap(p);
  p->bounds.left=r->left;
  p->bounds.right=r->right;
  p->bounds.top=r->top;
  p->bounds.bottom=r->bottom;
  unsigned int w=r->right-r->left;
  unsigned int h=r->bottom-r->top;
  //
  // TODO: Much more to be filled in here...
  //
  p->pixelSize=d;
  switch(d) {
    case 1: p->rowBytes=w/8; break;
    case 2: p->rowBytes=w/4; break;
    case 4: p->rowBytes=w/2; break;
    case 8: p->rowBytes=w; break;
    case 16: p->rowBytes=w*1; break;
    case 24: p->rowBytes=w*3; break;
    default:
      carbon_warn_msg("*** myCarbon_newPixMap bad d!\n"); 
      exit(EXIT_FAILURE);
      break;
  }
  unsigned int s=p->rowBytes*h;
  p->packSize=s;
  p->baseAddr=(Ptr)malloc(s);
  if(!p->baseAddr) { carbon_warn_msg("*** myCarbon_newPixMap p->baseAddr is NULL!\n"); exit(EXIT_FAILURE); }
  return p;
}


////////////////////////////////////////////////////////////////////////////////
// Quickdraw
////////////////////////////////////////////////////////////////////////////////

void InitGraf(void *globalPtr)
{
  carbon_debug_msg("(mycarbon InitGraf)\n");
  if(!globalPtr) { carbon_warn_msg("*** mycarbon'InitGraf()' globalPtr is NULL!\n"); exit(EXIT_FAILURE); }
  open_nlibs(0,NULL);
  if(!the_n_display) the_n_display=open_display(NULL,0,0,0);
  if(the_n_display) {
    myCarbon_init_QDGlobals(&qd);
    //ERR_OUT<<"display "<<the_n_display->width<<"x"<<the_n_display->height<<"\n");
    //
    qd.screenBits.bounds.top=0;
    qd.screenBits.bounds.bottom=the_n_display->height;
    qd.screenBits.bounds.left=0;
    qd.screenBits.bounds.right=the_n_display->width;
    //
    //myCarbon_printrect("InitGraf screenbits",&qd.screenBits.bounds);
  }
  thePort=(GrafPtr)malloc(sizeof(CGrafPort));
  myCarbon_initCGrafPort((CGrafPtr)thePort);
  qd.thePort=(GrafPtr)thePort;
  if(!qd.thePort) { carbon_warn_msg("*** mycarbon'InitGraf()' thePort is NULL!\n"); exit(EXIT_FAILURE); }
  //
#ifdef REAL_QD_GLOBALS
  // TODO: Fill out ALL globals...
  myCarbon_sync_QDGlobals(&qd);
#endif
}


void InitCursor()
{
  open_nlibs(0,NULL);
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'InitCursor()' not implemented!\n");
}


short QDError()
{
  carbon_debug_msg("(mycarbon QDError)\n");
  return qderror;
}


// NOTE: This probably isn't right...is color really an rgb?
void BackColor(long color)
{
  carbon_debug_msg("(mycarbon BackColor)\n");
  //carbon_debug_msg("*** mycarbon'BackColor()' color is "<<color<<".\n");
  set_backgroundc(the_n_window,color);
}


void CopyBits(const BitMap *srcBits, const BitMap *dstBits, const Rect *srcRect, const Rect *dstRect, short mode, RgnHandle maskRgn)
{
  carbon_debug_msg("(mycarbon CopyBits)\n");
  if(!srcBits) { carbon_warn_msg("*** mycarbon'CopyBits()' srcBits is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstBits) { carbon_warn_msg("*** mycarbon'CopyBits()' dstBits is NULL!\n"); exit(EXIT_FAILURE); }
  if(!srcRect) { carbon_warn_msg("*** mycarbon'CopyBits()' srcRect is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstRect) { carbon_warn_msg("*** mycarbon'CopyBits()' dstRect is NULL!\n"); exit(EXIT_FAILURE); }
  PixMap *sp=NULL;
  if(myCarbon_isPixMap(srcBits)) sp=(PixMap *)srcBits;
  else {
    if(myCarbon_isCGrafPort((GrafPort *)srcBits)) {
    }
  }
  if(!sp) { carbon_warn_msg("*** mycarbon'CopyBits()' sp is NULL!\n"); exit(EXIT_FAILURE); }
  /*
  long srev=((PixMapPtr)srcBits)->pmReserved;
  n_image *src=(n_image *)srev;
  if(!src) { carbon_warn_msg("*** mycarbon'CopyBits()' src n_image is NULL!\n"); return; }
  dump_image(src);
  */
}


void DisposeRgn(RgnHandle rgn)
{
  if(!rgn) { carbon_warn_msg("*** mycarbon'DisposeRgn()' rgn is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'DisposeRgn()' not implemented!\n");
}


void DrawText(const void *textBuf, short firstByte, short byteCount)
{
  if(!textBuf) { carbon_warn_msg("*** mycarbon'DrawText()' textBuf is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_debug_msg("(mycarbon DrawText)\n");
  if(!textBuf) { carbon_warn_msg("*** mycarbon'DrawText()' textBuf is NULL!\n"); exit(EXIT_FAILURE); }
  draw_text(the_n_window,curX,curY,(char *)textBuf);
}


void EraseRect(const Rect *r)
{
  if(!r) { carbon_warn_msg("*** mycarbon'EraseRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'EraseRect()' not implemented!\n");
}


void InvertRect(const Rect *r)
{
  if(!r) { carbon_warn_msg("*** mycarbon'InvertRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'InvertRect()' not implemented!\n");
}


void OffsetRect(Rect *r, short dh, short dv)
{
  if(!r) { carbon_warn_msg("*** mycarbon'OffsetRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'OffsetRect()' not implemented!\n");
}


void PaintRect(const Rect *r)
{
  if(!r) { carbon_warn_msg("*** mycarbon'PaintRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'PaintRect()' not implemented!\n");
}


// NOTE: This probably isn't right...is color really an rgb?
void ForeColor(long color)
{
  carbon_debug_msg("(mycarbon ForeColor)\n");
  //carbon_debug_msg("*** mycarbon'ForeColor()' color is "<<color<<".\n");
  set_foregroundc(the_n_window,color);
}


GDHandle GetGDevice()
{
  carbon_debug_msg("(mycarbon GetGDevice)\n");
  if(!the_n_display) the_n_display=open_display(NULL,0,0,0);
  if(!the_n_display) { carbon_warn_msg("*** mycarbon In GetGDevice, open_display failed!\n"); exit(EXIT_FAILURE); }
  if(!theMacGDevicePtr) {
    theMacGDevicePtr=&theMacGDevice;
    myCarbon_initGDevice(&theMacGDevice);
    //
    unsigned int np=the_n_display->nPlanes;
    unsigned int d=the_n_display->depth;
    unsigned int rowBytes=0;
    if(np>1) rowBytes=the_n_display->width/8;
    else {
      rowBytes=the_n_display->width*d;
    }
    unsigned int planeSize=rowBytes*the_n_display->height;
    //
    theMacGDevice.gdRect.right=the_n_display->width;
    theMacGDevice.gdRect.bottom=the_n_display->height;
    //
    //ERR_OUT<<"d is "<<d<<"\n";
    if(d>8) theMacGDevice.gdMode=0x80;
    else theMacGDevice.gdMode=0;  // ???
    PixMapPtr *pm=(PixMapPtr *)malloc(sizeof(PixMapPtr));  
    *pm=myCarbon_newPixMap(&theMacGDevice.gdRect,d);
    theMacGDevicePtr->gdPMap=pm;
 }
  return &theMacGDevicePtr;
}


void GlobalToLocal(Point *pt)
{
  carbon_debug_msg("(mycarbon GlobalToLocal)\n");
  if(!pt) { carbon_warn_msg("*** mycarbon'GlobalToLocal()' pt is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'GlobalToLocal()' not implemented!\n");
}


void Index2Color(long index, RGBColor *aColor)
{
  if(aColor) { carbon_warn_msg("*** mycarbon'Index2Color()' aColor is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'Index2Color()' not implemented!\n");
  exit(EXIT_FAILURE);
}


// How is this different from Line?
void LineTo(short h, short v)
{
  carbon_debug_msg("(mycarbon LineTo)\n");
  //carbon_debug_msg("*** mycarbon'LineTo()' line will be "<<curX<<","<<curY<<" to "<<h<<","<<v<<".\n");
  //ERR_OUT<<"lineTo "<<curX<<","<<curY<<" "<<h<<","<<v<<"\n");
  draw_line(the_n_window,curX,curY,h,v);
  curX=h; curY=v;
}


void MoveTo(short h, short v)
{
  carbon_debug_msg("(mycarbon MoveTo)\n");
  //carbon_debug_msg("*** mycarbon'MoveTo()' h,v is "<<h<<","<<v<<".\n");
  curX=h; curY=v;
}


RgnHandle NewRgn()
{
  carbon_notimp_msg("*** mycarbon'NewRgn()' not implemented!\n"); 
  return NULL;
}


void PenMode(short mode)
{
  carbon_notimp_msg("*** mycarbon'PenMode()' not implemented!\n");
}


void RGBBackColor(const RGBColor *color)
{
  carbon_debug_msg("(mycarbon RGBBackColor)\n");
  if(!color) { carbon_warn_msg("*** mycarbon'RGBBackColor()' color is NULL!\n"); exit(EXIT_FAILURE); }
  unsigned int red=(color->red)>>8;
  unsigned int green=(color->green)>>8;
  unsigned int blue=(color->blue)>>8;
  unsigned long theColor=(red<<16)+(blue<<8)+green;
  //carbon_debug_msg("*** mycarbon'RGBBackColor()' rgb is "<<red<<","<<green<<","<<blue<<".\n");
  //carbon_debug_msg("*** mycarbon'RGBBackColor()' theColor is "<<theColor<<".\n");
  //carbon_debug_msg("theColor is "); debug_hexl(theColor); debug_nl();
  //set_background(the_n_window,red,green,blue);
  set_backgroundc(the_n_window,theColor);
}


void RGBForeColor(const RGBColor *color)
{
  carbon_debug_msg("(mycarbon RGBForeColor)\n");
  if(!color) { carbon_warn_msg("*** mycarbon'RGBForeColor()' color is NULL!\n"); exit(EXIT_FAILURE); }
  unsigned int red=(color->red)>>8;
  unsigned int green=(color->green)>>8;
  unsigned int blue=(color->blue)>>8;
  //unsigned long theColor=(red<<16)+(blue<<8)+green;
  //carbon_debug_msg("*** mycarbon'RGBForeColor()' rgb is "<<red<<","<<green<<","<<blue<<".\n");
  //carbon_debug_msg("*** mycarbon'RGBForeColor()' theColor is "<<theColor<<".\n");
  //carbon_debug_msg("theColor is "); debug_hexl(theColor); debug_nl();
  set_foreground(the_n_window,red,green,blue);
  //set_foregroundc(the_n_window,theColor);
}


void ScrollRect(const Rect *r, short dh, short dv, RgnHandle updateRgn)
{
  carbon_debug_msg("(mycarbon ScrollRect)\n");
  if(!r) { carbon_warn_msg("*** mycarbon'ScrollRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  //myCarbon_printrect("ScrollRect",r);
  carbon_notimp_msg("*** mycarbon'ScrollRect()' not implemented!\n");
}


void SetEntries(short start, short count, CSpecArray aTable)
{
  carbon_notimp_msg("*** mycarbon'SetEntries()' not implemented!\n");
}


// We only support a single port...
void SetPort(GrafPtr port)
{
  carbon_debug_msg("(mycarbon SetPort)\n");
  if(!port) { carbon_warn_msg("*** mycarbon'SetPort()' port is NULL!\n"); exit(EXIT_FAILURE); }
#ifdef REAL_QD_GLOBALS
  qd.thePort=port;
#else
  thePort=port;
#endif
}


void SetRect(Rect *r, short left, short top, short right, short bottom)
{
  carbon_debug_msg("(mycarbon SetRect)\n");
  if(!r) { carbon_warn_msg("*** mycarbon'SetRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  //carbon_debug_msg("*** mycarbon'SetRect()' left,top,right,bottom is "<<left<<","<<top<<","<<right<<","<<bottom<<".\n");
  r->left=left; r->top=top; r->right=right; r->bottom=bottom;
  ////myCarbon_printrect("SetRect",r);
}


void TextFont(short font)
{
  carbon_debug_msg("(mycarbon TextFont)\n");
#ifdef REAL_QD_GLOBALS
  qd.thePort->txFont=font;
#else
  thePort->txFont=font;
#endif
}


void TextMode(short mode)
{
  carbon_debug_msg("(mycarbon TextMode)\n");
#ifdef REAL_QD_GLOBALS
  qd.thePort->txMode=mode;
#else
  thePort->txMode=mode;
#endif
}


void TextSize(short size)
{
  carbon_debug_msg("(mycarbon TextSize)\n");
#ifdef REAL_QD_GLOBALS
  qd.thePort->txSize=size;
#else
  thePort->txSize=size;
#endif
}


short TextWidth(const void *textBuf, short firstByte, short byteCount)
{
  carbon_debug_msg("(mycarbon TextWidth)\n");
  if(!textBuf) { carbon_warn_msg("*** mycarbon'TextWidth()' textBuf is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'TextWidth()' not implemented!\n");
  return 0;
}


void GetPort(GrafPtr *port)
{
  if(!port) { carbon_warn_msg("*** mycarbon'GetPort()' port is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'GetPort()' not implemented!\n");
}


long GetCTSeed(void)
{
  carbon_debug_msg("(mycarbon GetCTSeed)\n");
  // TODO: Is this good enough?
  return rand();
}


PicHandle GetPicture(short pictureID)
{
  carbon_notimp_msg("*** mycarbon'GetPicture()' not implemented!\n");
  return 0;
}


CTabHandle GetCTable(short ctID)
{
  carbon_notimp_msg("*** mycarbon'GetCTable()' not implemented!\n");
  return 0;
}


// How is this different from LineTo?
void Line(short dh, short dv)
{
  carbon_debug_msg("(mycarbon Line)\n");
  //ERR_OUT<<"line "<<curX<<","<<curY<<" "<<dh<<","<<dv<<"\n");
  draw_line(the_n_window,curX,curY,dh,dv);
  curX=dh; curY=dv;
}


void PenPat(const Pattern *pat)
{
  carbon_debug_msg("(mycarbon PenPat)\n");
  if(!pat) { carbon_warn_msg("*** mycarbon'PenPat()' pat is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'PenPat()' not implemented!\n");
}


void ShowCursor(void)
{
  carbon_debug_msg("(mycarbon ShowCursor)\n");
  // do nothing...
}


void HideCursor(void)
{
  carbon_debug_msg("(mycarbon HideCursor)\n");
  // do nothing...
}


void BackPat(const Pattern *pat)
{
  carbon_debug_msg("(mycarbon BackPat)\n");
  if(!pat) { carbon_warn_msg("*** mycarbon'BackPat()' pat is NULL!\n"); exit(EXIT_FAILURE); }
  carbon_notimp_msg("*** mycarbon'BackPat()' not implemented!\n");
}


Boolean GetPixel(short h, short v)
{
  carbon_notimp_msg("*** mycarbon'GetPixel()' not implemented!\n");
  return FALSE;
}


void DisposeCTable(CTabHandle cTable)
{
  carbon_notimp_msg("*** mycarbon'DisposeCTable()' not implemented!\n");
}


// I think this is right...
void InsetRect(Rect *r, short dh, short dv)
{
  carbon_debug_msg("(mycarbon InsetRect)\n");
  if(!r) { carbon_warn_msg("*** mycarbon'InsetRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  //myCarbon_printrect("InsetRect pre",r);
  r->top=r->top+dh;
  r->bottom=r->bottom-dh;
  r->left=r->left+dv;
  r->right=r->right-dv;
  //carbon_debug_msg("*** mycarbon'InsetRect()' h,v is "<<dh<<","<<dv<<".\n");
  //myCarbon_printrect("InsetRect post",r);
}


short Random(void)
{
  carbon_debug_msg("(mycarbon Random)\n");
  int t=rand();
  // TODO: Don't know if this is right...
  t=t&0xffff;
  t=t-32767;
  return t;
}


// TODO: Just a circle for now...this should be an oval and should be filled
void PaintOval(const Rect *r)
{
  carbon_debug_msg("(mycarbon PaintOval)\n");
  //ERR_OUT<<"PaintOval()...\n");
  if(!r) { carbon_warn_msg("*** mycarbon'PaintOval()' r is NULL!\n"); exit(EXIT_FAILURE); }
  unsigned int radius=r->right-r->left;
  unsigned int x=r->left+(radius/2);
  unsigned int y=r->top+(radius/2);
  /*
  draw_line(the_n_window,r->left,r->top,r->right,r->top);
  draw_line(the_n_window,r->right,r->top,r->right,r->bottom);
  draw_line(the_n_window,r->right,r->bottom,r->left,r->bottom);
  draw_line(the_n_window,r->left,r->bottom,r->left,r->top);
  */
  draw_circle(the_n_window,x,y,radius);
  curX=r->left; curY=r->top;  //  Is this right or should it be the center?
}


// Is this right?
void InvertColor(RGBColor *myColor)
{
  carbon_debug_msg("(mycarbon InvertColor)\n");
  if(!myColor) { carbon_warn_msg("*** mycarbon'InvertColor()' myColor is NULL!\n"); exit(EXIT_FAILURE); }
  myColor->red=65535-myColor->red;
  myColor->green=65535-myColor->green;
  myColor->blue=65535-myColor->blue;
}


void DrawString(ConstStr255Param s)
{
  carbon_debug_msg("(mycarbon DrawString)\n");
  // TODO: Process s in case it really is a pascal string!
  draw_text(the_n_window,curX,curY,(const char *)s+1);
}


void GetGWorld(CGrafPtr *port, GDHandle *gdh)
{
  carbon_debug_msg("(mycarbon GetGWorld)\n");
  if(!port) { carbon_warn_msg("*** mycarbon'GetGWorld()' port is NULL!\n"); exit(EXIT_FAILURE); }
  if(!gdh) { carbon_warn_msg("*** mycarbon'GetGWorld()' gdh is NULL!\n"); exit(EXIT_FAILURE); }
  if(!theMacGDevicePtr) {
    theMacGDevicePtr=&theMacGDevice;
    myCarbon_initGDevice(&theMacGDevice);
    GetGDevice();
  }
  *gdh=&theMacGDevicePtr;
  *port=(CGrafPtr)thePort;
}


void InvalRgn() 
{ 
  carbon_notimp_msg("*** InvalRgn()' not implemented!\n"); 
}


Ptr GetPixBaseAddr(PixMapHandle pm) 
{ 
  carbon_debug_msg("(mycarbon GetGWorld)\n");
  // TODO: Does this work?  Is it valid?  Do we actually care?
  return (*pm)->baseAddr;
}


void InvalRect() 
{ 
  carbon_notimp_msg("*** InvalRect()' not implemented!\n"); 
}


Boolean LockPixels(PixMapHandle pm) 
{ 
  carbon_notimp_msg("*** LockPixels()' not implemented!\n");
  return true;
}


void UnlockPixels(PixMapHandle pm) 
{ 
  carbon_notimp_msg("*** UnlockPixels()' not implemented!\n");
}


void PenNormal() 
{ 
  carbon_notimp_msg("*** PenNormal()' not implemented!\n"); 
}


void ValidRect() 
{ 
  carbon_notimp_msg("*** ValidRect()' not implemented!\n"); 
}


void LocalToGlobal(Point *pt) 
{ 
  carbon_notimp_msg("*** LocalToGlobal()' not implemented!\n"); 
  if(!pt) { carbon_warn_msg("*** mycarbon'LocalToGlobal()' pt is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean PtInRect(Point pt, const Rect *r) 
{ 
  carbon_notimp_msg("*** PtInRect()' not implemented!\n"); 
  if(!r) { carbon_warn_msg("*** mycarbon'PtInRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE; 
}


void OffsetRgn(RgnHandle rgn, short dh, short dv) 
{ 
  carbon_notimp_msg("*** OffsetRgn()' not implemented!\n"); 
  if(!rgn) { carbon_warn_msg("*** mycarbon'OffsetRgn()' port is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean SectRect(const Rect *src1, const Rect *src2, Rect *dstRect) 
{
  carbon_notimp_msg("*** SectRect()' not implemented!\n"); 
  if(!src1) { carbon_warn_msg("*** mycarbon'SectRect()' src1 is NULL!\n"); exit(EXIT_FAILURE); }
  if(!src2) { carbon_warn_msg("*** mycarbon'SectRect()' src2 is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstRect) { carbon_warn_msg("*** mycarbon'SectRect()' dstRect is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE; 
}


void ClipRect(const Rect *r) 
{ 
  carbon_notimp_msg("*** ClipRect()' not implemented!\n"); 
  if(!r) { carbon_warn_msg("*** mycarbon'ClipRect()' r is NULL!\n"); exit(EXIT_FAILURE); }
}


void CopyRgn(RgnHandle srcRgn, RgnHandle dstRgn) 
{
  carbon_notimp_msg("*** CopyRgn()' not implemented!\n"); 
  if(!srcRgn) { carbon_warn_msg("*** mycarbon'CopyRgn()' srcRgn is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstRgn) { carbon_warn_msg("*** mycarbon'CopyRgn()' dstRgn is NULL!\n"); exit(EXIT_FAILURE); }
}


void DiffRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn) 
{ 
  carbon_notimp_msg("*** DiffRgn()' not implemented!\n"); 
  if(!srcRgnA) { carbon_warn_msg("*** mycarbon'DiffRgn()' srcRgnA is NULL!\n"); exit(EXIT_FAILURE); }
  if(!srcRgnB) { carbon_warn_msg("*** mycarbon'DiffRgn()' srcRgnB is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstRgn) { carbon_warn_msg("*** mycarbon'DiffRgn()' dstRgn is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean EmptyRgn(RgnHandle rgn) 
{ 
  carbon_notimp_msg("*** EmptyRgn()' not implemented!\n"); 
  if(!rgn) { carbon_warn_msg("*** mycarbon'EmptyRgn()' rgn is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE; 
}


Boolean PtInRgn(Point pt, RgnHandle rgn) 
{ 
  carbon_notimp_msg("*** PtInRgn()' not implemented!\n"); 
  if(!rgn) { carbon_warn_msg("*** mycarbon'PtInRgn()' rgn is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE; 
}


void RectRgn(RgnHandle rgn, const Rect *r)
{
  carbon_notimp_msg("*** RectRgn()' not implemented!\n");
  if(!rgn) { carbon_warn_msg("*** mycarbon'RectRgn()' rgn is NULL!\n"); exit(EXIT_FAILURE); }
  if(!r) { carbon_warn_msg("*** mycarbon'RectRgn()' r is NULL!\n"); exit(EXIT_FAILURE); }
}


void SectRgn(RgnHandle srcRgnA, RgnHandle srcRgnB, RgnHandle dstRgn)
{
  carbon_notimp_msg("*** SectRgn()' not implemented!\n");
  if(!srcRgnA) { carbon_warn_msg("*** mycarbon'SectRgn()' port is NULL!\n"); exit(EXIT_FAILURE); }
  if(!srcRgnB) { carbon_warn_msg("*** mycarbon'SectRgn()' srcRgnB is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstRgn) { carbon_warn_msg("*** mycarbon'SectRgn()' dstRgn is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetOrigin(short h, short v) 
{
  carbon_notimp_msg("*** SetOrigin()' not implemented!\n"); 
}


void SetPt(Point *pt, short h, short v) 
{
  carbon_notimp_msg("*** SetPt()' not implemented!\n"); 
  if(!pt) { carbon_warn_msg("*** mycarbon'SetPt()' pt is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetRectRgn(RgnHandle rgn, short left, short top, short right, short bottom) 
{
  carbon_notimp_msg("*** SetRectRgn()' not implemented!\n"); 
  if(!rgn) { carbon_warn_msg("*** mycarbon'SetRectRgn()' rgn is NULL!\n"); exit(EXIT_FAILURE); }
}


void FrameOval(const Rect *r) 
{
  carbon_notimp_msg("*** FrameOval()' not implemented!\n");
  if(!r) { carbon_warn_msg("*** mycarbon'FrameOval()' r is NULL!\n"); exit(EXIT_FAILURE); }
}


void OpenPort(GrafPtr port) 
{
  carbon_notimp_msg("*** OpenPort()' not implemented!\n"); 
  if(!port) { carbon_warn_msg("*** mycarbon'OpenPort()' port is NULL!\n"); exit(EXIT_FAILURE); }
}


void ClosePort(GrafPtr port) 
{
  carbon_notimp_msg("*** ClosePort()' not implemented!\n"); 
  if(!port) { carbon_warn_msg("*** mycarbon'ClosePort()' port is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetPortBits(const BitMap *bm) 
{
  carbon_notimp_msg("*** SetPortBits()' not implemented!\n"); 
  if(!bm) { carbon_warn_msg("*** mycarbon'SetPortBits()' bm is NULL!\n"); exit(EXIT_FAILURE); }
}


void SaveEntries(CTabHandle srcTable, CTabHandle resultTable, ReqListRec *selection) 
{
  carbon_notimp_msg("*** SaveEntries()' not implemented!\n"); 
  if(!srcTable) { carbon_warn_msg("*** mycarbon'SaveEntries()' srcTable is NULL!\n"); exit(EXIT_FAILURE); }
  if(!resultTable) { carbon_warn_msg("*** mycarbon'SaveEntries()' resultTable is NULL!\n"); exit(EXIT_FAILURE); }
  if(!selection) { carbon_warn_msg("*** mycarbon'SaveEntries()' selection is NULL!\n"); exit(EXIT_FAILURE); }
}


void RestoreEntries(CTabHandle srcTable, CTabHandle dstTable, ReqListRec *selection)
{
  carbon_notimp_msg("*** RestoreEntries()' not implemented!\n"); 
  if(!srcTable) { carbon_warn_msg("*** mycarbon'RestoreEntries()' srcTable is NULL!\n"); exit(EXIT_FAILURE); }
  if(!dstTable) { carbon_warn_msg("*** mycarbon'RestoreEntries()' dstTable is NULL!\n"); exit(EXIT_FAILURE); }
  if(!selection) { carbon_warn_msg("*** mycarbon'RestoreEntries()' selection is NULL!\n"); exit(EXIT_FAILURE); }
}


GDevice** GetDeviceList()
{
  carbon_notimp_msg("*** GetDeviceList()' not implemented!\n"); 
  return NULL;
}


GDevice** GetMainDevice()
{
  carbon_notimp_msg("*** GetMainDevice()' not implemented!\n"); 
  return NULL;
}


GDHandle GetNextDevice(GDHandle curDevice)
{
  carbon_notimp_msg("*** GetNextDevice()' not implemented!\n"); 
  if(!curDevice) { carbon_warn_msg("*** mycarbon'GetNextDevice()' curDevice is NULL!\n"); exit(EXIT_FAILURE); }
  return NULL;
}


void SetGDevice(GDHandle gd)
{
  carbon_notimp_msg("*** SetGDevice()' not implemented!\n"); 
  if(!gd) { carbon_warn_msg("*** mycarbon'SetGDevice()' gd is NULL!\n"); exit(EXIT_FAILURE); }
}


void CTabChanged(CTabHandle ctab)
{
  carbon_notimp_msg("*** mycarbon'CTabChanged()' not implemented!\n");
  if(!ctab) { carbon_warn_msg("*** mycarbon'CTabChanged()' ctab is NULL!\n"); exit(EXIT_FAILURE); }
}


}  // extern "C"
