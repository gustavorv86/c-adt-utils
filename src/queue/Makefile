SHELL:=/bin/bash

########## DIRECTORIES ##########

SRCDIR:=.

BUILDDIR:=../../build

DISTDIR:=../../dist

TARGET_LIB:=$(DISTDIR)/libqueue.so

TARGET_TEST:=$(DISTDIR)/queue_test_main

BUILDOBJS:=$(BUILDDIR)/queue.o

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

$(BUILDDIR)/queue.o: $(SRCDIR)/queue.h $(SRCDIR)/queue.c
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/queue.c -o $(BUILDDIR)/queue.o $(LDFLAGS) 

$(BUILDDIR)/queue_test_main.o: $(SRCDIR)/queue_test_main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/queue_test_main.c -o $(BUILDDIR)/queue_test_main.o $(LDFLAGS)

$(TARGET_LIB): $(BUILDDIR)/queue.o
	$(CC) -shared -o $(TARGET_LIB) $(BUILDDIR)/queue.o

$(TARGET_TEST): $(TARGET_LIB) $(BUILDDIR)/queue_test_main.o
	$(CC) $(CFLAGS) -L$(DISTDIR) $(BUILDDIR)/queue_test_main.o -o $(TARGET_TEST) $(LDFLAGS) -lqueue
	
end:
	@echo "Done..."
