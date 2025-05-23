
# Makefile C3, 2021.05.31

# COMPILE OPTIONS
CXXFLAGS= -Wall -g --std=c++11
# LINK OPTIONS
LDFLAGS=

#############
# VARIABLES #            NO DEBES MODIFICARLAS
#############--------------------------------------------------------------
# SOURCES
P1SRCS=p1.cc mainp1.cc
P2SRCS=mainp2.cc

# OBJECTS
P1OBJS=p1.o mainp1.o
P2OBJS=mainp2.o
P2SRCS=mainp2.cc list.tcc node.tcc

# TAR FILE
TARF=$(shell basename "$$(pwd)")
#########------------------------------------------------------------------

#########
# RULES #
#########------------------------------------------------------------------
all : p1 p2

#--------------------------------------------------------------------------
runp1 : p1
	./p1

runp2 : p2
	./p2

#--------------------------------------------------------------------------
valgrindp1 : p1
	valgrind ./p1

valgrindp2 : p2
	valgrind ./p2

#- EXES -------------------------------------------------------------------
p1 : $(P1OBJS)
	$(CXX) $^ -o $@

p2 : $(P2SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#--------------------------------------------------------------------------
tgz :
	rm -rf irp2-c3; mkdir irp2-c3
	cp *.cc irp2-c3
	tar cfz irp2-c3.tgz irp2-c3

#- DEPENDENCIES -----------------------------------------------------------

#--------------------------------------------------------------------------
clean:
	rm -f *.o *~ p2 p1

.PHONY: clean run valgrind tgz
