
# Makefile C4, 2020.07.03

# COMPILE OPTIONS
CXXFLAGS= -Wall -g --std=c++11
# LINK OPTIONS
LDFLAGS=

#############
# VARIABLES #            NO DEBES MODIFICARLAS
#############--------------------------------------------------------------
# SOURCES
SRCS=battlerobot.cc mainp2.cc noisesensor.cc robot.cc \
     cleaningrobot.cc basicrobot.cc

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
p1 : p1.o mainp1.o
	$(CXX) $^ -o $@ -lm

# OBJECTS
OBJS=robot.o basicrobot.o battlerobot.o cleaningrobot.o noisesensor.o mainp2.o#\
     #rubikscubesolver.o pressuresensor.o mainp2.o

p2 : $(OBJS)
	$(CXX) $^ -o $@

#--------------------------------------------------------------------------
tgz :
	rm -rf irp2-c4; mkdir irp2-c4
	cp *.cc irp2-c4
	cp pressuresensor.h rubikscubesolver.h irp2-c4
	tar cfz irp2-c4.tgz irp2-c4

#- DEPENDENCIES -----------------------------------------------------------
robot.o            : robot.h         sensor.h macros.h
basicrobot.o       : basicrobot.h    robot.h  macros.h
battlerobot.o      : battlerobot.h   robot.h  sensor.h macros.h
cleaningrobot.o    : cleaningrobot.h robot.h  sensor.h macros.h
noisesensor.o      : noisesensor.h   sensor.h macros.h
//rubikscubesolver.o : robot.h basicrobot.h rubikscubesolver.h
//pressuresensor.o   : pressuresensor.h sensor.h macros.h

#--------------------------------------------------------------------------
clean:
	rm -f *.o *~ p2 p1

.PHONY: clean run valgrind tgz
