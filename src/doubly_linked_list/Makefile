SHELL:=/bin/bash

########## DIRECTORIES ##########

SRCDIR:=.

BUILDDIR:=../../build

DISTDIR:=../../dist

TARGET_LIB:=$(DISTDIR)/libdoublylinkedlist.so

TARGET_TEST:=$(DISTDIR)/doubly_linked_list_test_main

BUILDOBJS:=$(BUILDDIR)/doubly_linked_list.o

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

$(BUILDDIR)/doubly_linked_list.o: $(SRCDIR)/doubly_linked_list.h $(SRCDIR)/doubly_linked_list.c
	$(CC) $(CFLAGS) -fPIC -c $(SRCDIR)/doubly_linked_list.c -o $(BUILDDIR)/doubly_linked_list.o $(LDFLAGS) 

$(BUILDDIR)/doubly_linked_list_test_main.o: $(SRCDIR)/doubly_linked_list_test_main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/doubly_linked_list_test_main.c -o $(BUILDDIR)/doubly_linked_list_test_main.o $(LDFLAGS)

$(TARGET_LIB): $(BUILDDIR)/doubly_linked_list.o
	$(CC) -shared -o $(TARGET_LIB) $(BUILDDIR)/doubly_linked_list.o

$(TARGET_TEST): $(TARGET_LIB) $(BUILDDIR)/doubly_linked_list_test_main.o
	$(CC) $(CFLAGS) -L$(DISTDIR) $(BUILDDIR)/doubly_linked_list_test_main.o -o $(TARGET_TEST) $(LDFLAGS) -ldoublylinkedlist
	
end:
	@echo "Done..."
