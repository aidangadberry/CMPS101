//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include <stdlib.h>
#include "loadGraph.h"
#include "intList.h"
#include <stdio.h>
#include <string.h>

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