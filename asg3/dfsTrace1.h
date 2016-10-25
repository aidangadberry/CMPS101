//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include "intList.h"

// Pre: non-null arrays and variables
// Post: DFS is run and array values are set, then printed
void dfsTrace1(IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack);

// recursive DFS function that sets discover time, goes as deep as it can until there are 
// no more children, then sets the finish time and parent
//
// Pre: non-null arrays and variables
// Post: returns the timer of the current visit call, adds discover times, finish times
//       and parents accordingly
int visitTrace1(int i, int * color, IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int timer);

// formats and prints the arrays to the console, then sets the stack 
// for use in the Phase2 call of the SCC algorithm
// Pre: non-null arrays and variables
// Post: arrays printed to console, stack array set for future use
void printArraysTrace1(int n, int *dtime, int *ftime, int *parent, int *stack);
