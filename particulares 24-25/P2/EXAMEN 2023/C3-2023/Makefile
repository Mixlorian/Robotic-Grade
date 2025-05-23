
# Makefile C3, 2022.06.12

# COMPILE OPTIONS
CXXFLAGS= -Wall -g --std=c++17
# LINK OPTIONS
LDFLAGS=

#############
# VARIABLES #            NO DEBES MODIFICARLAS
#############--------------------------------------------------------------
# TAR FILE
TARFILE=irp2-c3

# OBJECTS
P1OBJS=mainp1.o
P2OBJS=mainp2.o vehicle.o gaspowered.o car.o

#########------------------------------------------------------------------

#########
# RULES #
#########------------------------------------------------------------------
all : p1 p2

#--------------------------------------------------------------------------
mainp1.o: mainp1.cc msort.cc

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

p2 : $(P2OBJS)
	$(CXX) $^ -o $@

#--------------------------------------------------------------------------
tgz : clean
	@rm -rf $(TARFILE); mkdir $(TARFILE)
	@cp *.cc *.h $(TARFILE)
	@tar cfz $(TARFILE).tgz --exclude=mainp?.cc --exclude=types.h --exclude=msort.h $(TARFILE)
	@rm -rf $(TARFILE)

#--------------------------------------------------------------------------
clean:
	@rm -f *.o *~ p1 p2 $(TARFILE).tgz

.PHONY: clean runp1 runp2 valgrindp1 valgrindp2 tgz
