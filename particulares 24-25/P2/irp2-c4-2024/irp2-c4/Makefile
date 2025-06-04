
# Makefile C3, 2024.06.11

# COMPILE OPTIONS
CXXFLAGS= -Wall -g --std=c++17
# LINK OPTIONS
LDFLAGS=

#############
# VARIABLES #            NO DEBES MODIFICARLAS
#############--------------------------------------------------------------
# TAR FILE
TARFILE=irp2-c4

# SOURCES
P1SRCS=mainp1.cc matrix2d.cc
P2SRCS=mainp2.cc
# OBJETCS
P1OBJS=mainp1.o matrix2d.o
P2OBJS=mainp2.o

#########------------------------------------------------------------------

#########
# RULES #
#########------------------------------------------------------------------
all : p1 p2

#--------------------------------------------------------------------------
mainp1.o: $(P1SRCS)
mainp2.o: $(P2SRCS)

#--------------------------------------------------------------------------
run: runp1 runp2

runp1 : p1
	@echo
	@echo Running p1
	./p1

runp2 : p2
	@echo
	@echo Running p2
	./p2

#--------------------------------------------------------------------------
runv: valgrindp1 valgrindp2

valgrindp1 : p1
	@echo
	@echo Running p1 with valgrind
	valgrind ./p1

valgrindp2 : p2
	@echo
	@echo Running p2 with valgrind
	valgrind ./p2

#- EXES -------------------------------------------------------------------
p1 : $(P1OBJS)
	$(CXX) $^ -o $@

p2 : $(P2OBJS)
	$(CXX) $^ -o $@

#--------------------------------------------------------------------------
tgz : clean
	@rm -rf $(TARFILE); mkdir $(TARFILE)
	@cp matrix2d.* $(TARFILE)
	@tar cfz $(TARFILE).tgz --exclude=mainp*.cc $(TARFILE)
	@rm -rf $(TARFILE)

#--------------------------------------------------------------------------
clean:
	@rm -f *.o *~ p1 p2 $(TARFILE).tgz

.PHONY: clean all run runv runp1 valgrindp1 runp2 valgrindp2 tgz
