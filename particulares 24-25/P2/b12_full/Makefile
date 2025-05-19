# Copyright (C) Programacion-II, DLSI, UA 2025

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

###################################
# ACTUALIZA EL NUMERO DE PRACTICA #
###################################
PR=3



#############
# VARIABLES #                     PUEDES CAMBIARLAS
#############--------------------------------------------------------------

# COMPILE OPTIONS
CXXFLAGS= -Wall -Wpedantic -Wextra -Wconversion -fsanitize=undefined -g --std=c++17
# LINK OPTIONS
LDFLAGS= -fsanitize=undefined


######################
# COMPUTED VARIABLES #            NO DEBES MODIFICARLAS
######################-----------------------------------------------------
# SOURCES
SRCS=$(wildcard *.cc)
# OBJETCS
OBJS=$(patsubst %.cc, %.o, $(SRCS))
# TAR FILE
TARF=$(shell basename "$$(pwd)")
#########------------------------------------------------------------------


#########
# RULES #                         NO DEBES MODIFICARLAS
#########------------------------------------------------------------------
all : p$(PR)

########
# CODE #
########
p$(PR) : $(OBJS)
	@echo '[7m[1m'Enlazando practica...'[0m'
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

#################
# Documentation #
#################
Doxyfile:
	@echo '[7m[1m'Generando Doxyfile...'[0m'
	@doxygen -g

#################
# PHONY TARGETS #
#################
run: p$(PR)
	@echo '[7m[1m'Ejecutando practica...'[0m'
	./p$(PR)

runv: p$(PR)
	@echo '[7m[1m'Ejecutando practica desde valgrind...'[0m'
	@valgrind --leak-check=full ./p$(PR)

vstats: p$(PR)
	@echo '[7m[1m'Estadisticas de valgrind...'[0m'
	@valgrind --leak-check=full ./p$(PR) 2>&1 | grep "lost\|reachable" ; true

debug: p$(PR)
	@echo '[7m[1m'Depurando practica...'[0m'
	@gdb --tui p$(PR)

tgz: clean
	@echo '[7m[1mCreando archivo: irp2-p3.tgz ...[0m'
	@cd ..; tar cfz irp2-p3.tgz irp2-p3; mv irp2-p3.tgz irp2-p3; cd irp2-p3


clean:
	@echo '[7m[1m'Limpiando...'[0m'
	@rm -r -f *~ p$(PR) *.o *.tgz *.bak doc

doc: Doxyfile
	@echo '[7m[1m'Generando documentacion...'[0m'
	@doxygen


###########################
# BINARIOS DE TEST (bXX) #
###########################
BINSRC := $(wildcard b12_[0-9][0-9].cc)
BINS := $(patsubst %.cc,%,$(BINSRC))

# Regla para compilar todos
b12: $(BINS)

# Compilación de cada uno con su main y p3.o
$(BINS): %: %.cc p3.o
	@echo '[7m[1m'Compilando $@ con p3.o...'[0m'
	$(CXX) $(CXXFLAGS) $< p3.o -o $@

# Regla para compilar p3.o (si tienes p3.cc)
p3.o: p3.cc p3.h
	$(CXX) $(CXXFLAGS) -c p3.cc -o p3.o

valgrind_b12: $(BINS)
	@echo '[7m[1m'Comprobando binarios con Valgrind...'[0m'
	@for bin in $(BINS); do \
		echo '[7m[1m'Analizando $$bin...'[0m'; \
		valgrind --leak-check=full --error-exitcode=1 ./$$bin 2>&1 | grep "lost\|reachable" || true; \
	done


##############################
# TEST DE SALIDA AUTOMÁTICO #
##############################

test_b12: $(BINS)
	@echo '[7m[1m'Ejecutando pruebas de salida para binarios b12_XX...'[0m'
	@total=0; passed=0; \
	for bin in $(BINS); do \
		txt=$${bin}.txt; \
		if [ -f "$$txt" ]; then \
			echo '[7m[1m'Probando $$bin...'[0m'; \
			./$$bin > .out.$$bin.tmp; \
			if diff -q .out.$$bin.tmp $$txt > /dev/null; then \
				echo "✅ $$bin: OK"; \
				passed=$$((passed+1)); \
			else \
				echo "❌ $$bin: FALLA (diferencias con $$txt)"; \
				diff .out.$$bin.tmp $$txt; \
			fi; \
			rm -f .out.$$bin.tmp; \
			total=$$((total+1)); \
		else \
			echo "⚠️  $$txt no encontrado, se omite $$bin"; \
		fi; \
	done; \
	echo '[7m[1m'Pruebas pasadas: $$passed / $$total'[0m'



.PHONY: clean tgz run debug doc all
#########------------------------------------------------------------------
