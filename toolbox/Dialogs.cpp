
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
////////#define false mac_false
////////#define true mac_true
#include <MacTypes.h>
////////#undef false
////////#undef true

#include <Dialogs.h>

#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Dialogs
////////////////////////////////////////////////////////////////////////////////

void InitDialogs(void *ignored) {
  open_nlibs(0,NULL);
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'InitDialogs()' not implemented!\n");
}


void DialogCopy(DialogRef theDialog) {
  carbon_notimp_msg("*** mycarbon'DialogCopy()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'DialogCopy()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


void DialogCut(DialogRef theDialog) {
  carbon_notimp_msg("*** mycarbon'DialogCut()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'DialogCut()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


void DialogDelete(DialogRef theDialog) {
  carbon_notimp_msg("*** mycarbon'DialogDelete()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'DialogDelete()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


void DialogPaste(DialogRef theDialog) {
  carbon_notimp_msg("*** mycarbon'DialogPaste()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'DialogPaste()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


void SelectDialogItemText(DialogRef theDialog, short itemNo, short strtSel, short endSel) {
  carbon_notimp_msg("*** mycarbon'SelectDialogItemText()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'SelectDialogItemText()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


void DisposeDialog(DialogRef theDialog)
{
  carbon_notimp_msg("*** mycarbon'DisposeDialog()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'DisposeDialog()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


DialogRef GetNewDialog(short dialogID, void *dStorage, WindowRef behind)
{
  carbon_notimp_msg("*** mycarbon'GetNewDialog()' not implemented!\n");
  return 0;
}


short Alert(short alertID, ModalFilterUPP modalFilter)
{
  carbon_notimp_msg("*** Alert()' not implemented!\n");
  return 0;
}


void ModalDialog(ModalFilterUPP modalFilter, short *itemHit)
{
  carbon_notimp_msg("*** ModalDialog()' not implemented!\n");
}


Boolean DialogSelect(const EventRecord *theEvent, DialogRef *theDialog, short *itemHit)
{
  carbon_notimp_msg("*** DialogSelect()' not implemented!\n");
  return FALSE;
}


void GetDialogItem(DialogRef theDialog, short itemNo, short *itemType, Handle *item, Rect *box)
{
  carbon_notimp_msg("*** GetDialogItem()' not implemented!\n");
  if(!theDialog) { carbon_warn_msg("*** mycarbon'GetDialogItem()' theDialog is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean IsDialogEvent(const EventRecord *e)
{
  carbon_notimp_msg("*** IsDialogEvent()' not implemented!\n");
  if(!e) { carbon_warn_msg("*** mycarbon'IsDialogEvent()' e is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE;
}


}
