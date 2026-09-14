
#define DEBUG_OUT dBug
//#define ERR_OUT dBug
#define ERR_OUT std::cerr
//#define DEBUG_OUT *aNullStream
#define CONS_OUT std::cout
#define CONS_IN std::cin


#ifdef DEBUG_VERBOSE
//#undef DEBUG_VERBOSE
#endif


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"

#include "mynotimplemented.h"

#include "mycarbon_debug.h"


#include <iostream>


extern "C" {


////////////////////////////////////////////////////////////////////////////////
// stubs for unimplemented funcs
////////////////////////////////////////////////////////////////////////////////


void SFGetFile() { carbon_debug_msg("*** SFGetFile()' not implemented!\n"); }

void ClrAppFiles() { carbon_debug_msg("*** ClrAppFiles()' not implemented!\n"); }
void CountAppFiles() { carbon_debug_msg("*** CountAppFiles()' not implemented!\n"); }
void GetAppFiles() { carbon_debug_msg("*** GetAppFiles()' not implemented!\n"); }

void DIBadMount() { carbon_debug_msg("*** DIBadMount()' not implemented!\n"); }

//void CloseDeskAcc() { carbon_debug_msg("*** CloseDeskAcc()' not implemented!\n"); }
//void OpenDeskAcc() { carbon_debug_msg("*** OpenDeskAcc()' not implemented!\n"); }

void GetIndString() { carbon_debug_msg("*** GetIndString()' not implemented!\n"); }
void NumToString() { carbon_debug_msg("*** NumToString()' not implemented!\n"); }
void p2cstr() { carbon_debug_msg("*** p2cstr()' not implemented!\n"); }
void P2CStr() { carbon_debug_msg("*** P2CStr()' not implemented!\n"); }
void ParamText() { carbon_debug_msg("*** ParamText()' not implemented!\n"); }

void InitPerf() { carbon_debug_msg("*** InitPerf()' not implemented!\n"); }
void PerfControl() { carbon_debug_msg("*** PerfControl()' not implemented!\n"); }
void PerfDump() { carbon_debug_msg("*** PerfDump()' not implemented!\n"); }
void TermPerf() { carbon_debug_msg("*** TermPerf()' not implemented!\n"); }

void InitCursorCtl() { carbon_debug_msg("*** InitCursorCtl()' not implemented!\n"); }
void SpinCursor() { carbon_debug_msg("*** SpinCursor()' not implemented!\n"); }
void GetCursor() { carbon_debug_msg("*** GetCursor()' not implemented!\n"); }
void SetCursor() { carbon_debug_msg("*** SetCursor()' not implemented!\n"); }
void TrackControl() { carbon_debug_msg("*** TrackControl()' not implemented!\n"); }

void SetClip() { carbon_debug_msg("*** SetClip()' not implemented!\n"); }
void GetClip() { carbon_debug_msg("*** GetClip()' not implemented!\n"); }
void UnloadScrap() { carbon_debug_msg("*** UnloadScrap()' not implemented!\n"); }
void ZeroScrap() { carbon_debug_msg("*** ZeroScrap()' not implemented!\n"); }
void GetScrap() { carbon_debug_msg("*** GetScrap()' not implemented!\n"); }

void MoveControl() { carbon_debug_msg("*** MoveControl()' not implemented!\n"); }
void DrawControls() { carbon_debug_msg("*** DrawControls()' not implemented!\n"); }
void FindControl() { carbon_debug_msg("*** FindControl()' not implemented!\n"); }
void GetControlMaximum() { carbon_debug_msg("*** GetControlMaximum()' not implemented!\n"); }
void GetControlValue() { carbon_debug_msg("*** GetControlValue()' not implemented!\n"); }
void GetNewControl() { carbon_debug_msg("*** GetNewControl()' not implemented!\n"); }
void HideControl() { carbon_debug_msg("*** HideControl()' not implemented!\n"); }
void SetControlMaximum() { carbon_debug_msg("*** SetControlMaximum()' not implemented!\n"); }
void SetControlValue() { carbon_debug_msg("*** SetControlValue()' not implemented!\n"); }
void ShowControl() { carbon_debug_msg("*** ShowControl()' not implemented!\n"); }
void SizeControl() { carbon_debug_msg("*** SizeControl()' not implemented!\n"); }

void AECountItems() { carbon_debug_msg("*** AECountItems()' not implemented!\n"); }
void AEDisposeDesc() { carbon_debug_msg("*** AEDisposeDesc()' not implemented!\n"); }
void AEGetNthPtr() { carbon_debug_msg("*** AEGetNthPtr()' not implemented!\n"); }
void AEGetParamDesc() { carbon_debug_msg("*** AEGetParamDesc()' not implemented!\n"); }
void AEInstallEventHandler() { carbon_debug_msg("*** AEInstallEventHandler()' not implemented!\n"); }
void AEProcessAppleEvent() { carbon_debug_msg("*** AEProcessAppleEvent()' not implemented!\n"); }

}
