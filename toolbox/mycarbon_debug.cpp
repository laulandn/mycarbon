
#include "../mycarbon_debug.h"


#ifdef MYCARBON_WARN
void carbon_warn_msg(const char *s)
{
  if(!n_base_was_open) open_nlibs(0,NULL);
  debug_msg(s);
}
#endif


#ifdef MYCARBON_DEBUG
void carbon_debug_msg(const char *s)
{
  if(!n_base_was_open) open_nlibs(0,NULL);
  debug_msg(s);
}
#endif
