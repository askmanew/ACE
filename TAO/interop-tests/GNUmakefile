# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 94635 2011-10-06 12:59:23Z johnnyw $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /home/build/DOC_ROOT/stage-644/ACE_wrappers/bin/mwc.pl -type gnuace -exclude "TAO/TAO_*.mwc,TAO/CIAO/CIAO_*.mwc" -workers 10 -recurse -hierarchy -relative ACE_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers -relative TAO_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO -relative CIAO_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO/CIAO -relative DANCE_ROOT=/home/build/DOC_ROOT/stage-644/ACE_wrappers/TAO/DAnCE
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: Demo_Idl Demo_Server Demo_Client interop_wchar_IDL Interop_Wchar_Client Interop_Wchar_Server

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Idl $(@)
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Server $(@)
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Client $(@)
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.interop_wchar_IDL $(@)
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.Interop_Wchar_Client $(@)
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.Interop_Wchar_Server $(@)

.PHONY: Demo_Idl
Demo_Idl:
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Idl all

.PHONY: Demo_Server
Demo_Server: Demo_Idl
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Server all

.PHONY: Demo_Client
Demo_Client: Demo_Idl Demo_Server
	$(KEEP_GOING)@cd AnyTypeCode/tao && $(MAKE) -f GNUmakefile.Demo_Client all

.PHONY: interop_wchar_IDL
interop_wchar_IDL:
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.interop_wchar_IDL all

.PHONY: Interop_Wchar_Client
Interop_Wchar_Client: interop_wchar_IDL
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.Interop_Wchar_Client all

.PHONY: Interop_Wchar_Server
Interop_Wchar_Server: interop_wchar_IDL Interop_Wchar_Client
	$(KEEP_GOING)@cd wchar && $(MAKE) -f GNUmakefile.Interop_Wchar_Server all

project_name_list:
	@echo Demo_Client
	@echo Demo_Idl
	@echo Demo_Server
	@echo Interop_Wchar_Client
	@echo Interop_Wchar_Server
	@echo interop_wchar_IDL
