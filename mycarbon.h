#ifndef MYCARBON_H
#define MYCARBON_H


#include "mycarbon_debug.h"


extern "C" {
#include "../nlib/nlib.h"
#include "../nlib/nlibdbug.h"
};

#include <MacTypes.h>


/* Do these defines  belong here? Where are they used? */

#define patXor 1
#define notSrcCopy 2


#define systemFont 0
#define applFont 1


typedef void * PaletteHandle;


/*
struct Point {
  short               v;
  short               h;
};
typedef struct Point                    Point;
typedef Point *                         PointPtr;
struct Rect {
  short               top;
  short               left;
  short               bottom;
  short               right;
};
typedef struct Rect                     Rect;
typedef Rect *                          RectPtr;
struct FixedPoint {
  Fixed               x;
  Fixed               y;
};
typedef struct FixedPoint               FixedPoint;
struct FixedRect {
  Fixed               left;
  Fixed               top;
  Fixed               right;
  Fixed               bottom;
};
typedef struct FixedRect                FixedRect;
*/


/* When are all these below used?  Are they?  Aren't they actually implemented? */
/*
void HideCursor(void);
void ShowCursor(void);
int GetCTSeed(void);
//
void SetPort(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void *GetWindowPort(void *ptr) { carbon_notimp_msg("not implemented\n"); return NULL; }
void ForeColor(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void blackColor() { carbon_notimp_msg("not implemented\n"); }
void BackColor(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void whiteColor() { carbon_notimp_msg("not implemented\n"); }
void *GetPortBitMapForCopyBits(void *ptr) { carbon_notimp_msg("not implemented\n"); return NULL; }
void CopyBits() { carbon_notimp_msg("not implemented\n"); }
void GetPortBounds(void *ptr,void *ptr2) { carbon_notimp_msg("not implemented\n"); }
void EraseRect(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void MoveTo(int x,int y) { carbon_notimp_msg("not implemented\n"); }
void LineTo(int x,int y) { carbon_notimp_msg("not implemented\n"); }
void Line(int x,int y) { carbon_notimp_msg("not implemented\n"); }
int GetPixel(int x,int y) { carbon_notimp_msg("not implemented\n"); return 0; }
void Index2Color(int i,void *ptr) { carbon_notimp_msg("not implemented\n"); }
void RGBForeColor(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void RGBBackColor(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void TextMode() { carbon_notimp_msg("not implemented\n"); }
void PenMode() { carbon_notimp_msg("not implemented\n"); }
//
void DrawText(const void *ptr,int i,int i2) { carbon_notimp_msg("not implemented\n"); }
int TextWidth(const void *ptr,int i,int i2) { carbon_notimp_msg("not implemented\n"); return 0; }
void TextFace(int i) { carbon_notimp_msg("not implemented\n"); }
void TextFont(int i) { carbon_notimp_msg("not implemented\n"); }
void TextSize(int i) { carbon_notimp_msg("not implemented\n"); }
void c2pstrcpy(void *ptr,const void *ptr2) { carbon_notimp_msg("not implemented\n"); }
void GetFNum(void *ptr,void *ptr2) { carbon_notimp_msg("not implemented\n"); }
void WaitNextEvent(int i,void *ptr,int i2,void *ptr2) { carbon_notimp_msg("not implemented\n"); }
void BeginUpdate(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void EndUpdate(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void DrawGrowIcon(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void *FrontWindow() { carbon_notimp_msg("not implemented\n"); return NULL; }
void SelectWindow(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void GlobalToLocal(void *ptr) { carbon_notimp_msg("not implemented\n"); }
int MenuKey(int i) { carbon_notimp_msg("not implemented\n"); return 0; }
int EventAvail(int i,void *ptr) { carbon_notimp_msg("not implemented\n"); return 0; }
int FindWindow(Point p,void *ptr2) { carbon_notimp_msg("not implemented\n"); return 0; }
int MenuSelect(Point p) { carbon_notimp_msg("not implemented\n"); return 0; }
void DragWindow(void *ptr,Point p,void *ptr3) { carbon_notimp_msg("not implemented\n"); }
void ShowWindow(void *ptr) { carbon_notimp_msg("not implemented\n"); }
int GrowWindow(void *ptr,Point p,void *ptr3) { carbon_notimp_msg("not implemented\n"); return 0; }
void SizeWindow(void *ptr,int i,int i2,int i3) { carbon_notimp_msg("not implemented\n"); }
int TrackBox(void *ptr,Point p,int i2) { carbon_notimp_msg("not implemented\n"); return 0; }
void ZoomWindow(void *ptr,int i,int i2) { carbon_notimp_msg("not implemented\n"); }
void InvalWindowRect(void *ptr,void *ptr2) { carbon_notimp_msg("not implemented\n"); }
int TrackGoAway(void *ptr,Point p) { carbon_notimp_msg("not implemented\n"); return 0; }
void SysBeep() { carbon_notimp_msg("not implemented\n"); }
void HiliteMenu() { carbon_notimp_msg("not implemented\n"); }

void *GetPort(void *ptr) { carbon_notimp_msg("not implemented\n"); return NULL; }
void ClearMenuBar() { carbon_notimp_msg("not implemented\n"); }
void *NewMenu(int i,void *ptr) { carbon_notimp_msg("not implemented\n"); return NULL; }
void InsertMenu(void *ptr,int i) { carbon_notimp_msg("not implemented\n"); }
void DrawMenuBar() { carbon_notimp_msg("not implemented\n"); }
void AppendMenu(void *ptr,void *ptr2) { carbon_notimp_msg("not implemented\n"); }
int GetMBarHeight() { carbon_notimp_msg("not implemented\n"); return NULL; }
void *GetCTable(int i) { carbon_notimp_msg("not implemented\n"); return NULL; }
void *GetGWorld(void *ptr,void *ptr2) { carbon_notimp_msg("not implemented\n"); return NULL; }
void *GetGDevice() { carbon_notimp_msg("not implemented\n"); return NULL; }
void RestoreDeviceClut(void *ptr) { carbon_notimp_msg("not implemented\n"); }
void *NewCWindow(void *ptr,void *ptr2,void *ptr3,int i,int i2,void *ptr4,int i3,int i4) { carbon_notimp_msg("not implemented\n"); return NULL; }
void *NewWindow() { carbon_notimp_msg("not implemented\n"); return NULL; }
void DisposeWindow(void *ptr) { carbon_notimp_msg("not implemented\n"); }
*/

#endif
