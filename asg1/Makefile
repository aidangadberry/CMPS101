##===============================================##
##  Name:        Aidan Gadberry					 ##
##  User ID:     agadberr						 ##
##  Date:        4/15/2015						 ##
##  Program:     Programming Assignment 1		 ##
##===============================================##

CC     = gcc
CFLAGS = -g -Wall -O0

intList.o:	intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

graph01.o:	graph01.c  intList.h
	${CC}  -c  ${CFLAGS}  graph01.c

graph01:	graph01.o  intList.o
	${CC}  -o  graph01  graph01.o intList.o