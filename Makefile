# Makefile that will prdouce the executable for the third Prgram!
# By: Ari Sherman
# Class: CS5201 HW #3
# Date: 2.26.18

CXX = /usr/bin/g++
CXXFLAGS = -g -Wpedantic -Wall -Wextra -Wfloat-conversion -Werror -std=c++11

OBJECTS =  main.o


.SUFFIXES: .cpp

.cpp.o: $<
	${CXX} -c ${CXXFLAGS} $< -o $@

default: all

all: driver

driver: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o $@

clean:
	-@rm -f core > /dev/null 2>&1
	-@rm -f driver > /dev/null 2>&1
	-@rm -f ${OBJECTS} > /dev/null 2>&1

# The Dependency lists!
main.o:	newton.h myArray.h
