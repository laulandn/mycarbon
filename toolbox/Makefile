
LIBNAME=$(shell basename $(shell pwd))
LDNAME=lib$(LIBNAME)_static.a

####################################################################
# Makefile
####################################################################

PATH_TO_BASE=..

include $(PATH_TO_BASE)/../Makefile.target
include $(PATH_TO_BASE)/../Makefile.common

EXTRA_INCS=-I$(PATH_TO_BASE) -I$(PATH_TO_BASE)/CIncludes -D_LATITUDE_=1 -DNSYS_X11=1 -D_MACH_=1 -DTARGET_API_MAC_CARBON=1
#EXTRA_INCS=-I$(PATH_TO_BASE) -I$(PATH_TO_BASE)/CIncludes -D_LATITUDE_=1 -DNSYS_POSIX=1

EXTRA_LIBS=-L$(PATH_TO_BASE)


###################################################################
# Our objects
###################################################################

PROGRAMS=
DIRS=$(wildcard */)
OBJS=$(subst .cpp,.$(OFILE),$(wildcard *.cpp))


####################################################################
# The libraries and programs 
####################################################################


####################################################################
# The targets 
####################################################################

all:	$(LDNAME)
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) all;)

$(LDNAME):	$(OBJS)
	$(AR_CMD) $(OBJS)
	$(RANLIB_CMD) $(LDNAME) 


clean:
	rm -rf *.o *.obj *.lib *.a *.s *.bak *.log map.f build *Data *.pdb *.lib $(PROGRAMS) *.html *.exe *.exe.so *68k *.SYM .DS_Store *.ilk *.app *.class .gdb_history .nautilus-metafile.xml */*Data */Debug */*.ncb */*/Debug Debug ._* */._* */*/._* */*/*/._* *~ */*~ */*/*~ */*/*/*~
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) clean;)


fix: fix_perm fix_type
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) fix;)


install: all
	#cp *.a /usr/local/lib
	#mkdir /usr/local/include/$(LIBNAME)
	#cp *.h /usr/local/include/$(LIBNAME)
	#$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) install;)


# The different Libraries and Programs...

# dependencies
# NOTE: its ok to see errors when running makedepend
depend: remove_depends
	makedepend $(DEPENDFLAGS) *.cpp
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) depend;)


remove_depends:
	rm -f Makefile.dep
	touch Makefile.dep
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -ik -C $(DIR) remove_depends;)


include $(PATH_TO_BASE)/Makefile.tail

include Makefile.dep


