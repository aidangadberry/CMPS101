##===============================================##
##  Name:        Aidan Gadberry                  ##
##  User ID:     agadberr                        ##
##  Date:        5/28/2015                       ##
##  Program:     Programming Assignment 3        ##
##===============================================##

CC     = gcc
CFLAGS = -g -Wall -O0

intList.o:		intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

loadGraph.o:	loadGraph.c loadGraph.h intList.h
	${CC}  -c  ${CFLAGS}  loadGraph.c

dfsTrace1.o:	dfsTrace1.c dfsTrace1.h intList.h
	${CC}  -c  ${CFLAGS}  dfsTrace1.c

dfsPhase2.o:	dfsPhase2.c dfsPhase2.h intList.h
	${CC}  -c  ${CFLAGS}  dfsPhase2.c

scc03.o:		scc03.c  dfsTrace1.h dfsPhase2.h loadGraph.h intList.h
	${CC}  -c  ${CFLAGS}  scc03.c

scc03:			scc03.o  dfsTrace1.o dfsPhase2.o loadGraph.o intList.o 
	${CC}  -o  scc03  scc03.o dfsTrace1.o dfsPhase2.o loadGraph.o intList.o
