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

all: CDR_Alignment CDR_Allocator CDR_Basic_Types CDR_Growth CDR_Octet_Sequence CDR_Tc

REMAINING_TARGETS := $(filter-out all,$(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Alignment $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Allocator $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Basic_Types $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Growth $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Octet_Sequence $(@)
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Tc $(@)

.PHONY: CDR_Alignment
CDR_Alignment:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Alignment all

.PHONY: CDR_Allocator
CDR_Allocator:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Allocator all

.PHONY: CDR_Basic_Types
CDR_Basic_Types:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Basic_Types all

.PHONY: CDR_Growth
CDR_Growth:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Growth all

.PHONY: CDR_Octet_Sequence
CDR_Octet_Sequence:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Octet_Sequence all

.PHONY: CDR_Tc
CDR_Tc:
	$(KEEP_GOING)@$(MAKE) -f GNUmakefile.CDR_Tc all

project_name_list:
	@echo CDR_Alignment
	@echo CDR_Allocator
	@echo CDR_Basic_Types
	@echo CDR_Growth
	@echo CDR_Octet_Sequence
	@echo CDR_Tc
