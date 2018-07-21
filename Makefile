SHELL:=/bin/bash

########## DIRECTORIES ##########

SRCDIR:=src

BUILDDIR:=build

DISTDIR:=dist

TARGETDIRS:=$$(ls $(SRCDIR))

########## MAKE ############

MAKE:=/usr/bin/make

########## RULES ##########

all:
	@for dir in $(TARGETDIRS); do $(MAKE) -C $(SRCDIR)/$$dir; done

libs:
	@for dir in $(TARGETDIRS); do $(MAKE) -C $(SRCDIR)/$$dir lib; done

clean:
	@for dir in $(TARGETDIRS); do $(MAKE) -C $(SRCDIR)/$$dir clean; done
	@if [[ -d ${BUILDDIR} ]]; then rm -rf ${BUILDDIR}; fi
	@if [[ -d ${DISTDIR} ]]; then rm -rf ${DISTDIR}; fi
