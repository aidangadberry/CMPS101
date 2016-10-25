##===============================================##
##  Name:        Aidan Gadberry					 ##
##  User ID:     agadberr						 ##
##  Date:        5/6/2015						 ##
##  Program:     Programming Assignment 2		 ##
##===============================================##

CC     = gcc
CFLAGS = -g -Wall -O0

intList.o:	intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

graph02.o:	graph02.c  intList.h
	${CC}  -c  ${CFLAGS}  graph02.c

graph02:	graph02.o  intList.o
	${CC}  -o  graph02  graph02.o intList.o