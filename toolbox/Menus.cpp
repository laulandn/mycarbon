
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

#include <Menus.h>
#include <Errors.h>


#include "../../nlib/nlib.h"
#include "../../nlib/nlibdbug.h"


////////////////////////////////////////////////////////////////////////////////
// Menus
////////////////////////////////////////////////////////////////////////////////

void InitMenus() {
  open_nlibs(0,NULL);
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'InitMenus()' not implemented!\n");
}


void ClearMenuBar() {
  carbon_notimp_msg("*** mycarbon'ClearMenuBar()' not implemented!\n");
}


short GetMBarHeight() {
  // Not true, but good enough
  return 12;
}


void GetMenuItemText(MenuRef theMenu, short item, Str255 itemString) {
  carbon_notimp_msg("*** mycarbon'GetMenuItemText()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'GetMenuItemText()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


void HiliteMenu(short menuID) {
  //carbon_notimp_msg("*** mycarbon'HiliteMenu()' not implemented!\n");
}


long MenuKey(short ch) {
  carbon_notimp_msg("*** mycarbon'MenuKey()' not implemented!\n");
  return 0;
}


long MenuSelect(Point startPt) {
  carbon_notimp_msg("*** mycarbon'MenuSelect()' not implemented!\n");
  return 0;
}


MenuRef NewMenu(short menuID, ConstStr255Param menuTitle) {
  carbon_notimp_msg("*** mycarbon'NewMenu()' not implemented!\n");
  //return dsHMenuFindErr;
  return 0;
}


void InsertMenu(MenuRef theMenu, short beforeID) {
  carbon_notimp_msg("*** mycarbon'InsertMenu()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'InsertMenu()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


void DrawMenuBar() {
  // NOTE: Ok to skip...
  //carbon_notimp_msg("*** mycarbon'DrawMenuBar()' not implemented!\n");
}


void AppendMenu(MenuRef menu, ConstStr255Param data) {
  carbon_notimp_msg("*** mycarbon'AppendMenu()' not implemented!\n");
  if(!menu) { carbon_warn_msg("*** mycarbon'AppendMenu()' menu is NULL!\n"); exit(EXIT_FAILURE); }
}


void AppendResMenu(MenuRef theMenu, ResType theType) {
  carbon_notimp_msg("*** mycarbon'AppendResMenu()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'AppendResMenu()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


//void AddResMenu(MenuRef theMenu, ResType theTyp) {
  //carbon_notimp_msg("*** mycarbon'AddResMenu()' not implemented!\n");
//}


Boolean SystemEdit(short editCmd) {
  carbon_notimp_msg("*** mycarbon'SystemEdit()' not implemented!\n");
  return false;
}


void EnableItem(MenuRef theMenu, short item)
{
  carbon_notimp_msg("*** EnableItem()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'EnableItem()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


void CheckItem(MenuRef theMenu, short item, Boolean checked)
{
  carbon_notimp_msg("*** CheckItem()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'CheckItem()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


MenuRef GetMenu(short resourceID)
{
  carbon_notimp_msg("*** GetMenu()' not implemented!\n");
  return NULL;
}


MenuRef GetMenuHandle(short menuID)
{
  carbon_notimp_msg("*** GetMenuHandle()' not implemented!\n");
  return NULL;
}


Handle GetNewMBar(short menuBarID) { carbon_notimp_msg("*** GetNewMBar()' not implemented!\n"); return NULL; }


void DisableItem(MenuRef theMenu, short item)
{
  carbon_notimp_msg("*** DisableItem()' not implemented!\n");
  if(!theMenu) { carbon_warn_msg("*** mycarbon'DisableItem()' theMenu is NULL!\n"); exit(EXIT_FAILURE); }
}


void SetMenuBar(Handle menuList)
{
  carbon_notimp_msg("*** SetMenuBar()' not implemented!\n");
  if(!menuList) { carbon_warn_msg("*** mycarbon'SetMenuBar()' menuList is NULL!\n"); exit(EXIT_FAILURE); }
}


}
