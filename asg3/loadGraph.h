//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include "intList.h"

// ---------- Access Functions ------------------ //

// loops through each IntArray in origGraph and tries to find a 
// cycle starting at that vertex by calling hasCycleLen. If it does,
// it will print out the vertex that was returned by the call to 
// hasCycleLen. If not, it will continue to the next IntArray vertex.
// If no cycle is found by the time it has looped through all the
// verticies, it will print that it does not contain any cycles
// Pre: origGraph != NULL, n >= 0
// Post: origGraph and n are unchanged, returns 1 if a cycle was
//       found, 0 if no cycle was found
int hasCycle(IntList* origGraph, int n);

// recursively loops through the given vertex until either the current
// length of the chain is greater than the number of total elements in 
// IntList arrays, or until there are no adjacent edges, after which 
// it will return the vertex or 0 accordingly
// Pre: origGraph != NULL, n >= 0, sofar >= 0, v > 0
// Post: all values are unchanged, returns either 0 if there are no
//       adjacent edges, vertex v if sofar >= n, or the return of
//       adjacent edges if neither of the previous cases are 
//		 satisfied
int hasCycleLen(IntList* origGraph, int n, int sofar, int v);


// ---------- Manipulation Procedures ----------- //

// transposes the input graph and returns the transposed graph as
// output
// Pre: origGraph != NULL, n >= 0
// Post: origGraph is filled with intNils, newGraph is transpose
//       of origGraph
IntList* transposeGraph(IntList* origGraph, int n);


// ---------- Other Functions ------------------- //

// prints the array of IntLists with proper formatting
// Pre: intArr != NULL, n >= 0, m >= 0
// Post: intArr, n, and m are unchanged, array is printed to console 
void printGraph(IntList* intArr, int n, int m);
