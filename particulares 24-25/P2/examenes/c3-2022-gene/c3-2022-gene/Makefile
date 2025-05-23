
# Makefile C3, 2022.06.09

# COMPILE OPTIONS
CXXFLAGS= -Wall -g --std=c++17
# LINK OPTIONS
LDFLAGS=

#############
# VARIABLES #            NO DEBES MODIFICARLAS
#############--------------------------------------------------------------
TARFILE=irp2-c3
# SOURCES
P1SRCS=mainp1.cc gene.cc mutablegene.cc chromosome.cc

# OBJECTS
P1OBJS=mainp1.o gene.o mutablegene.o chromosome.o

# TAR FILE
TARF=$(shell basename "$$(pwd)")
#########------------------------------------------------------------------

#########
# RULES #
#########------------------------------------------------------------------
all : p1

#--------------------------------------------------------------------------
runp1 : p1
	./p1

#--------------------------------------------------------------------------
valgrindp1 : p1
	valgrind ./p1

#- EXES -------------------------------------------------------------------
p1 : $(P1OBJS)
	$(CXX) $^ -o $@

#--------------------------------------------------------------------------
tgz :
	@rm -rf $(TARFILE); mkdir $(TARFILE)
	@cp *.cc $(TARFILE)
	@tar cfz $(TARFILE).tgz $(TARFILE)
	@rm -rf $(TARFILE)

#- DEPENDENCIES -----------------------------------------------------------

#--------------------------------------------------------------------------
clean:
	rm -f *.o *~ p1 $(TARFILE).tgz

.PHONY: clean run valgrind tgz
