
LIBNAME=$(shell basename $(shell pwd))
LDNAME=lib$(LIBNAME)_static.a

####################################################################
# Makefile
####################################################################

PATH_TO_BASE=.

include $(PATH_TO_BASE)/../Makefile.target
include $(PATH_TO_BASE)/../Makefile.common

#EXTRA_FLAGS=-I$(PATH_TO_BASE) -I$(PATH_TO_BASE)/CIncludes -D_LATITUDE_=1 -DNSYS_X11=1 -D_MACH_=1 -DTARGET_API_MAC_CARBON=1
EXTRA_FLAGS=-I$(PATH_TO_BASE) -I$(PATH_TO_BASE)/CIncludes -D_LATITUDE_=1 -DNSYS_X11=1 -DASYS_X11=1 -I/opt/local/include

EXTRA_LDFLAGS=-L$(PATH_TO_BASE) -L/opt/local/lib -lX11
#EXTRA_LIBS=$(NLIB_L)


####################################################################
# Our objects 
####################################################################

DIRS=$(wildcard */)
OBJS=$(subst .cpp,.$(OFILE),$(wildcard */*.cpp))


####################################################################
# The libraries and programs 
####################################################################

PROGRAMS1=SillyBalls
PROGRAMS2=Count EditCdev LinesSilly MPWTest MWSillyBalls Memory Sample TESample TestPerf TubeTest maclines
PROGRAMS=$(PROGRAMS1) $(PROGRAMS2)


PATH_TO_CPP=.
PATH_TO_SRC=.


PATH_TO_NLIB=../../more_src/nlib
#
NLIB_NAME=nlib_static
NLIB_L=-L$(PATH_TO_NLIB) -l$(NLIB_NAME)
NLIB_LIB=lib$(NLIB_NAME).$(AFILE)
NLIB_PATH=$(PATH_TO_NLIB)/$(NLIB_LIB)
#
NLIB_PATHS=$(NLIB_PATH)
NLIBLS=$(NLIB_L)


CPP_PATHS=$(NLIB_PATH)
CPP_LS=$(NLIB_L)


ifeq ($(MSVC),yes)
	NLIB_L=$(NLIB_PATH)
endif


####################################################################
# The targets 
####################################################################

all:
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) all;)
	$(MAKE) $(LDNAME)
	$(MAKE) -i $(PROGRAMS)


all_libs: base_libs


base_libs:


$(LDNAME):	$(OBJS)
	$(AR_CMD) $(OBJS)
	$(RANLIB_CMD) $(LDNAME) 


clean:
	rm -rf $(PROGRAMS) $(PROGRAMS2)
	rm -rf *.$(OFILE) *.$(AFILE) *.s *.bak *.log map.f build *Data *.pdb $(PROGRAMS) *.exe *.exe.so *68k *.SYM .DS_Store *.ilk .gdb_history .nautilus-metafile.xml resource.frk RESOURCE.FRK finder.dat FINDER.DAT ._* */._* */*/._* */*/*/._* *~ */*~ */*/*~ */*/*/*~ *.class *.javap *.java.* *.h.? tmp/*
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) clean;)


fix: fix_perm fix_type
# Libraries...
	$(foreach DIR,$(DIRS),$(MAKE) -i -C $(DIR) fix;)


# The different Libraries and Programs...


maclines: base_libs maclines.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o maclines maclines.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
SillyBalls: base_libs SillyBalls.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o SillyBalls SillyBalls.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
MWSillyBalls: base_libs MWSillyBalls.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o MWSillyBalls MWSillyBalls.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
LinesSilly: base_libs LinesSilly.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o LinesSilly LinesSilly.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
Count: base_libs Count.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o Count Count.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
EditCdev: base_libs EditCdev.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o EditCdev EditCdev.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
Memory: base_libs Memory.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o Memory Memory.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
Sample: base_libs Sample.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o Sample Sample.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
TESample: base_libs TESample.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o TESample TESample.$(OFILE) AsmClikLoop.o $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
TestPerf: base_libs TestPerf.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o TestPerf TestPerf.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
TubeTest: base_libs TubeTest.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o TubeTest TubeTest.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
MPWTest: base_libs MPWTest.$(OFILE) $(NLIB_PATH)
	$(CLXX) -o MPWTest MPWTest.$(OFILE) $(LDNAME) -L$(PATH_TO_NLIB) -lnlib_static $(LIBS) $(LDFLAGS)
	rm -rf $@.app
	#make $@.app
	
# dependencies
# NOTE: it's ok to see errors when running makedepend
depend:
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


# DO NOT DELETE
