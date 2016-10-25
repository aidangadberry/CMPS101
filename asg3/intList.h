//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#ifndef C101IntList
#define C101IntList

// the struct of the IntList, making both the element at the node
// and the location of the next node accessible
typedef struct IntListNode * IntList;

// defining constant intNil to be NULL
const IntList intNil;

// ---------- Constructors ---------------------- //

// constructs a new IntList node with element value newElement that
// connects to the front of the oldList
// Pre: newElement is int
// Post: return the new IntList at the head of the linked list, with
//       values newList->element = newElement and newList->next =
//       the oldList, or intNil if intCons was called on an intNil
IntList intCons(int newE, IntList oldL);

// ---------- Access Functions ------------------ //

// returns the element in the given IntList
// Pre: aList != NULL
// Post: aList still exists, aList->element is returned but remains
//       unchanged, aList->next unchanged
int intFirst(IntList oldL);

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

// essentially pops off the first IntList by returning aList->next
// Pre: aList != NULL
// Post: original aList is removed from linked list, return pointer
//       to aList with unchanged aList->element and aList->next
IntList intRest(IntList oldL);

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

#endif
