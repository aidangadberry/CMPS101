//===============================================//
//  Name:        Aidan Gadberry					 //
//  User ID:     agadberr						 //
//  Date:        5/6/2015						 //
//  Program:     Programming Assignment 2		 //
//===============================================//

#include <stdlib.h>
#include "intList.h"
#include <stdio.h>
#include <string.h>

// ---------- Structs -------------------------- //

// the struct of the IntList, making both the element at the node
// and the location of the next node accessible
struct IntListNode{
	int element;
	IntList next;
};

// defining constant intNil to be NULL
const IntList intNil = NULL;

// ---------- Constructors ---------------------- //

// constructs a new IntList node with element value newElement that
// connects to the front of the oldList
// Pre: newElement is int
// Post: return the new IntList at the head of the linked list, with
//       values newList->element = newElement and newList->next =
//       the oldList, or intNil if intCons was called on an intNil
IntList intCons(int newElement, IntList oldList){
	IntList newList = calloc(1, sizeof(struct IntListNode));
	newList->element = newElement;
	newList->next = oldList;
	return newList;
}

// ---------- Access Functions ------------------ //

// returns the element in the given IntList
// Pre: aList != NULL
// Post: aList still exists, aList->element is returned but remains
//       unchanged, aList->next unchanged
int intFirst(IntList aList){
	return aList->element;
}

// loops through each IntArray in origGraph and tries to find a 
// cycle starting at that vertex by calling hasCycleLen. If it does,
// it will print out the vertex that was returned by the call to 
// hasCycleLen. If not, it will continue to the next IntArray vertex.
// If no cycle is found by the time it has looped through all the
// verticies, it will print that it does not contain any cycles
// Pre: origGraph != NULL, n >= 0
// Post: origGraph and n are unchanged, returns 1 if a cycle was
//       found, 0 if no cycle was found
int hasCycle(IntList* origGraph, int n){
	int i;
	int vert;
	IntList* arrCopy;
	arrCopy = calloc(n + 1, sizeof(IntList));
	memcpy(arrCopy, origGraph, (n + 1) * sizeof(IntList));
	for (i = 0; i < n; i++){
		if (arrCopy[i] != intNil){
			vert = hasCycleLen(arrCopy, n, 0, i);
			if (vert > 0){
				printf("Found a cycle containing vertex %d.\n", vert);
				return (1);
			}
		}
	}
	printf("No cycles found.\n");
	return (0);
}

// recursively loops through the given vertex until either the current
// length of the chain is greater than the number of total elements in 
// IntList arrays, or until there are no adjacent edges, after which 
// it will return the vertex or 0 accordingly
// Pre: origGraph != NULL, n >= 0, sofar >= 0, v > 0
// Post: all values are unchanged, returns either 0 if there are no
//       adjacent edges, vertex v if sofar >= n, or the return of
//       adjacent edges if neither of the previous cases are 
//		 satisfied
int hasCycleLen(IntList* origGraph, int n, int sofar, int v){
	if (sofar >= n){
		return (v);
	}
	while (origGraph[v] != intNil){
		if (hasCycleLen(origGraph, n, sofar + 1, intFirst(origGraph[v])) == 0){
			origGraph[v] = intRest(origGraph[v]);
		}else{
			return (hasCycleLen(origGraph, n, sofar + 1, intFirst(origGraph[v])));
		}
	}
	return (0);
}

// ---------- Manipulation Procedures ----------- //

// essentially pops off the first IntList by returning aList->next
// Pre: aList != NULL
// Post: original aList is removed from linked list, return pointer
//       to aList with unchanged aList->element and aList->next
IntList intRest(IntList aList){
	return aList->next;
}

// transposes the input graph and returns the transposed graph as
// output
// Pre: origGraph != NULL, n >= 0
// Post: origGraph is filled with intNils, newGraph is transpose
//       of origGraph
IntList* transposeGraph(IntList* origGraph, int n){
	int i;
	IntList* newGraph;
	newGraph = calloc(n + 1, sizeof(IntList));
	IntList* arrCopy;
	arrCopy = calloc(n + 1, sizeof(IntList));
	memcpy(arrCopy, origGraph, (n + 1) * sizeof(IntList));
	for (i = 0; i < n; i++){
		newGraph[i] = intNil;
	}
	for (i = 0; i < n + 1; i++){
		while (arrCopy[i] != intNil){
			newGraph[intFirst(arrCopy[i])] = intCons(i, newGraph[intFirst(arrCopy[i])]);
			arrCopy[i] = intRest(arrCopy[i]);
		}
	}
	return newGraph;
}

// ---------- Other Functions ------------------- //

// prints the array of IntLists with proper formatting
// Pre: intArr != NULL, n >= 0, m >= 0
// Post: intArr, n, and m are unchanged, array is printed to console 
void printGraph(IntList* intArr, int n, int m){
	int i;
	IntList* arrCopy;
	arrCopy = calloc(n + 1, sizeof(IntList));
	memcpy(arrCopy, intArr, (n + 1) * sizeof(IntList));
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	for (i = 1; i < n + 1; i++){
		printf("%d\t", i);
		if (arrCopy[i] == intNil){
			printf("null\n");
		}else{
			printf("[");
			printf("%d", intFirst(arrCopy[i]));
			arrCopy[i] = intRest(arrCopy[i]);
			while (arrCopy[i] != intNil){
				printf(", %d", intFirst(arrCopy[i]));
				arrCopy[i] = intRest(arrCopy[i]);
			}
			printf("]\n");
		}
	}
}