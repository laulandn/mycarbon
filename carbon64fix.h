#ifndef MYCARBON64_H
#define MYCARBON64_H


// NOTE: This is NOT part of "mycarbon", but a separate project and doesn't belong here!


#include "../nlib/nlib.h"
#include "../nlib/nlibdbug.h"


//#include <MacTypes.h>


#define patXor 1
#define notSrcCopy 2


#define systemFont 0
#define applFont 1


#define whiteColor 30
#define blackColor 33


typedef void * PaletteHandle;


#if 0
void HideCursor(void);
void ShowCursor(void);
int GetCTSeed(void);
void SetPort(void *ptr);
void *GetWindowPort(void *ptr);
void ForeColor(void *ptr);
void blackColor(void);
void BackColor(void *ptr);
void whiteColor(void);
void *GetPortBitMapForCopyBits(void *ptr);
void CopyBits(void *ptr,void *ptr2,void *ptr3,void *ptr4,int i,void *ptr5);
void GetPortBounds(void *ptr,void *ptr2);
void EraseRect(void *ptr);
void MoveTo(int x,int y);
void LineTo(int x,int y);
void Line(int x,int y);
int GetPixel(int x,int y);
void Index2Color(int i,void *ptr);
void RGBForeColor(void *ptr);
void RGBBackColor(void *ptr);
void TextMode(int i);
void PenMode(int i);
void DrawText(const void *ptr,int i,int i2);
int TextWidth(const void *ptr,int i,int i2);
void TextFace(int i);
void TextFont(int i);
void TextSize(int i);
void c2pstrcpy(void *ptr,const void *ptr2);
void GetFNum(void *ptr,void *ptr2);
void WaitNextEvent(int i,void *ptr,int i2,void *ptr2);
void BeginUpdate(void *ptr);
void EndUpdate(void *ptr);
void DrawGrowIcon(void *ptr);
void *FrontWindow(void);
void SelectWindow(void *ptr);
void GlobalToLocal(void *ptr);
int MenuKey(int i);
int EventAvail(int i,void *ptr);
int FindWindow(Point p,void *ptr2);
int MenuSelect(Point p);
void DragWindow(void *ptr,Point p,void *ptr3);
void ShowWindow(void *ptr);
int GrowWindow(void *ptr,Point p,void *ptr3);
void SizeWindow(void *ptr,int i,int i2,int i3);
int TrackBox(void *ptr,Point p,int i2);
void ZoomWindow(void *ptr,int i,int i2);
void InvalWindowRect(void *ptr,void *ptr2);
int TrackGoAway(void *ptr,Point p);
void SysBeep(int i);
void HiliteMenu(int i);
void *GetPort(void *ptr);
void ClearMenuBar(void);
void *NewMenu(int i,void *ptr);
void InsertMenu(void *ptr,int i);
void DrawMenuBar(void);
void AppendMenu(void *ptr,void *ptr2);
int GetMBarHeight(void);
void *GetCTable(int i);
void *GetGWorld(void *ptr,void *ptr2);
void *GetGDevice(void);
void RestoreDeviceClut(void *ptr);
void *NewCWindow(void *ptr,void *ptr2,const void *ptr3,int i,int i2,void *ptr4,int i3,int i4);
void *NewWindow(void *ptr,void *ptr2,const void *ptr3,int i,int i2,void *ptr4,int i3,int i4);
void DisposeWindow(void *ptr);
#endif


#endif
