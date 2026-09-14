
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

#include <stdlib.h>


extern "C" {


// Only needed with some sets of mac headers...
//////#define false mac_false
//////#define true mac_true
#include <Types.h>
//////#undef false
//////#undef true

#include <Events.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// globals
////////////////////////////////////////////////////////////////////////////////

extern n_window *the_n_window;


////////////////////////////////////////////////////////////////////////////////
// my Event internals
////////////////////////////////////////////////////////////////////////////////

void mynlib2mac_event(n_event *nlibEvent, EventRecord *macEvent) {
  carbon_debug_msg("(mycarbon SysEnvirons)\n");
  if(!nlibEvent) { carbon_warn_msg("*** mycarbon'mynlib2mac_event()' nlibEvent is NULL!\n"); exit(EXIT_FAILURE); }
  if(!macEvent) { carbon_warn_msg("*** mycarbon'mynlib2mac_event()' macEvent is NULL!\n"); exit(EXIT_FAILURE); }
  switch(nlibEvent->type) {
    case N_EVENT_NONE:
      macEvent->what=nullEvent;
      break;
    case N_EVENT_UNKNOWN:
      macEvent->what=nullEvent;
      break;
    case N_EVENT_CLICK:
      macEvent->what=mouseUp;
      // TODO: Doesn't set x,y, etc!
      break;
    case N_EVENT_KEYPRESS:
      macEvent->what=keyUp;
      // TODO: Doesn't set code, etc!
      break;
    case N_EVENT_MOVED:
      macEvent->what=updateEvt;
      break;
    case N_EVENT_REDRAW:
      macEvent->what=updateEvt;
      break;
    case N_EVENT_FOCUS:
      // NOTE: Need to set something to say this is an activate (not a deactivate)
      macEvent->what=activateEvt;
      // TODO: Update thw window rect?
      break;
    case N_EVENT_UNFOCUS:
      // NOTE: Need to set something to say this is an deactivate (not a activate)
      macEvent->what=activateEvt;
      break;
    case N_EVENT_RESIZE:
      macEvent->what=updateEvt;
      // TODO: Update thw window rect!
      break;
    default:
      carbon_warn_msg("*** mycarbon'WaitNextEvent()' unhandled event type!\n");
      dump_event(nlibEvent);
      break;
  }
  macEvent->message=0;
  macEvent->when=0;
  macEvent->where.h=nlibEvent->x;  macEvent->where.v=nlibEvent->y;
  macEvent->modifiers=0;
}


////////////////////////////////////////////////////////////////////////////////
// Events
////////////////////////////////////////////////////////////////////////////////


// NOTE: eventMask is ignored...
Boolean GetNextEvent(EventMask eventMask, EventRecord *theEvent)
{
  carbon_debug_msg("(mycarbon GetNextEvent)\n");
  if(!the_n_window) {
    carbon_warn_msg("*** mycarbon'GetNextEvent()' the_n_window is NULL!\n");
    return false;
    //exit(EXIT_FAILURE);
  }
  if(!theEvent) { carbon_warn_msg("*** mycarbon'GetNextEvent()' theEvent is NULL!\n"); exit(EXIT_FAILURE); }
  n_event *myEvent=get_next_event(the_n_window);
  if(myEvent) {
    mynlib2mac_event(myEvent,theEvent);
    return true;
  }
  return false;
}


// NOTE: eventMask is ignored...
Boolean WaitNextEvent(EventMask eventMask, EventRecord *theEvent, UInt32 sleep, RgnHandle mouseRgn)
{
  carbon_debug_msg("(mycarbon WaitNextEvent)\n");
  if(!the_n_window) { carbon_warn_msg("*** mycarbon'WaitNextEvent()' the_n_window is NULL!\n"); exit(EXIT_FAILURE); }
  if(!theEvent) { carbon_warn_msg("*** mycarbon'WaitNextEvent()' theEvent is NULL!\n"); exit(EXIT_FAILURE); }
  struct n_event *myevent=NULL;
  myevent=wait_event(the_n_window);
  mynlib2mac_event(myevent,theEvent);
  return false;
}


// NOTE: eventMask is ignored...
Boolean EventAvail(EventMask eventMask, EventRecord *theEvent)
{
  carbon_debug_msg("(mycarbon EventAvail)\n");
  if(!theEvent) { carbon_warn_msg("*** mycarbon'EventAvail()' theEvent is NULL!\n"); exit(EXIT_FAILURE); }
  theEvent->what=0;
  theEvent->message=0;
  theEvent->when=0;
  theEvent->where.h=0;  theEvent->where.v=0;
  theEvent->modifiers=0;
  carbon_notimp_msg("*** mycarbon'EventAvail()' not implemented!\n");
  //exit(EXIT_FAILURE);
  return false;
}


UInt32 TickCount()
{
  carbon_notimp_msg("*** mycarbon'TickCount()' not implemented!\n");
  return rand();
}


void FlushEvents(EventMask whichMask, EventMask stopMask)
{
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'FlushEvents()' not implemented!\n");
}


void SetEventMask(EventMask value)
{
  carbon_notimp_msg("*** mycarbon'SetEventMask()' not implemented!\n");
}


void SystemTask(void)
{
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'SystemTask()' not implemented!\n");
}


Boolean Button(void)
{
  carbon_debug_msg("(mycarbon Button)\n");
  struct n_event *myevent;
  int isThereAnEvent=check_event(the_n_window);
  if(isThereAnEvent) {
    myevent=wait_event(the_n_window);
    // TODO: don't ignore other important events!
    switch(myevent->type) {
      case N_EVENT_CLICK:
        return true;
        break;
      default:
        return false;
        break;
    }
  }
  return false;
}


Boolean OSEventAvail(EventMask mask, EventRecord *theEvent)
{
  carbon_notimp_msg("*** OSEventAvail()' not implemented!\n");
  return FALSE;
}


void SystemClick(const EventRecord *theEvent, WindowRef theWindow)
{
  carbon_notimp_msg("*** SystemClick()' not implemented!\n");
  if(!theEvent) { carbon_warn_msg("*** mycarbon'SystemClick()' theEvent is NULL!\n"); exit(EXIT_FAILURE); }
  if(!theWindow) { carbon_warn_msg("*** mycarbon'SystemClick()' theWindow is NULL!\n"); exit(EXIT_FAILURE); }
}


Boolean GetOSEvent(EventMask mask, EventRecord *theEvent)
{
  carbon_notimp_msg("*** GetOSEvent()' not implemented!\n");
  if(!theEvent) { carbon_warn_msg("*** mycarbon'GetOSEvent()' theEvent is NULL!\n"); exit(EXIT_FAILURE); }
  return FALSE;
}


}
