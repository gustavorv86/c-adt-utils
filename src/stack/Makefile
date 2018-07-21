SHELL:=/bin/bash

########## DIRECTORIES ##########

SRCDIR:=.

BUILDDIR:=../../build

DISTDIR:=../../dist

TARGET_LIB:=$(DISTDIR)/libstack.so

TARGET_TEST:=$(DISTDIR)/stack_test_main

BUILDOBJS:=$(BUILDDIR)/stack.o

########## COMPILER AND LINKER ############

CC:=/usr/bin/gcc

CFLAGS:=-ggdb -Wall -Wextra

LDFLAGS:=

########## RULES ##########

all: start make_dirs $(TARGET_LIB) $(TARGET_TEST) end

lib: start make_dirs $(TARGET_LIB) end

make_dirs:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(DISTDIR)

clean: 
	@echo "Cleaning..."
	@rm -f $(TARGET_LIB)
	@rm -f $(TARGET_TEST)
	@rm -f $(BUILDOBJS)
	@echo "Done"

start:
	@echo "Compiling..."

$(BUILDDIR)/stack.o: $(SRCDIR)/stack.h $(SRCDIR)/stack.c
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/stack.c -o $(BUILDDIR)/stack.o $(LDFLAGS) 

$(BUILDDIR)/stack_test_main.o: $(SRCDIR)/stack_test_main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/stack_test_main.c -o $(BUILDDIR)/stack_test_main.o $(LDFLAGS)

$(TARGET_LIB): $(BUILDDIR)/stack.o
	$(CC) -shared -o $(TARGET_LIB) $(BUILDDIR)/stack.o

$(TARGET_TEST): $(TARGET_LIB) $(BUILDDIR)/stack_test_main.o
	$(CC) $(CFLAGS) -L$(DISTDIR) $(BUILDDIR)/stack_test_main.o -o $(TARGET_TEST) $(LDFLAGS) -lstack
	
end:
	@echo "Done..."
