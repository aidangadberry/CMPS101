##===============================================##
##  Name:        Aidan Gadberry                  ##
##  User ID:     agadberr                        ##
##  Date:        6/3/2015                        ##
##  Program:     Programming Assignment 4        ##
##===============================================##

CC     = gcc
CFLAGS = -g -Wall -O0

edgeList.o:		edgeList.c  edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

minPQ.o:		minPQ.c  minPQ.h
	${CC}  -c  ${CFLAGS}  minPQ.c	

loadWgtGraph.o:	loadWgtGraph.c  loadWgtGraph.h  minPQ.h  edgeList.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c

graph04.o:		graph04.c  loadWgtGraph.h  minPQ.h  edgeList.h
	${CC}  -c  ${CFLAGS}  graph04.c

graph04:		graph04.o  loadWgtGraph.o  minPQ.o  edgeList.o 
	${CC}  -o  graph04  graph04.o  loadWgtGraph.o  minPQ.o  edgeList.o
