//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include "intList.h"

// runs the second phase of DFS, using the stack as the node list. Calls visit on each valid 
// Pre: all arrays are declared, origGraph != NULL, n > 0
// Post: DFS and findRoot are run, and array values are printed
void dfsPhase2(IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int *root);

// recursive DFS function that sets discover time, goes as deep as it can until there are 
// no more children, then sets the finish time and parent
//
// Pre: non-null arrays and variables
// Post: returns the timer of the current visit call, adds discover times, finish times
//       and parents accordingly
int visitPhase2(int i, int *color, IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int timer);

// returns the current vertex if it has no parent, otherwise returns the recursive
// call of findRoot on its parent
// Pre: non-null arrays and variables
// Post: returns the root
int findRootPhase2(int v, int *parent);


// formats and prints the arrays to the console
// Pre: non-null arrays and variables
// Post: arrays printed to console
void printArraysPhase2(int n, int *dtime, int *ftime, int *parent, int *root);
