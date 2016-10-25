//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include <stdlib.h>
#include "dfsPhase2.h"
#include "intList.h"
#include <stdio.h>
#include <string.h>

void dfsPhase2(IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int *root){
	// initialize variables
	int timer = 1;
	int i;
	int numVert = 0;
	int color[n+1];

	// count the number of verticies in the graph
	for (i = 1; i < n + 1; i++){
		if (dtime[i] > 0){
			numVert++;
		}
	}

	// create a copy of the graph so that the original doesn't get affected
	IntList* arrCopy;
	arrCopy = calloc(n + 1, sizeof(IntList));
	memcpy(arrCopy, origGraph, (n + 1) * sizeof(IntList));

	// initialize all of the information arrays
	for (i = 1; i < n + 1; i++){
		color[i] = 0;
		dtime[i] = 0;
		ftime[i] = 0;
		parent[i] = -1;
		root[i] = -1;
	}

	// call the recursive DFS call (visitPhase2) using each valid vertex as
	// a starting vertex
	for (i = 1; i < numVert + 1; i++){
		if (color[stack[i]] == 0){
			if (arrCopy[stack[i]] != intNil){
				timer = visitPhase2(stack[i], color, arrCopy, n, dtime, ftime, parent, stack, timer);
			}
		}
	}

	// call the recursive function findRootPhase2 on each vertex and add the result
	// to the root array
	for (i = 1; i < numVert + 1; i++){
		root[i] = findRootPhase2(i, parent);
	}

	// call the print function to print the results of each array
	printArraysPhase2(numVert, dtime, ftime, parent, root);
}

int visitPhase2(int i, int *color, IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int timer){
	// set color to grey, add the discover time of current vertex, then increment the time
	color[i] = 1;
	dtime[i] = timer;
	timer++;

	// recursively call visit function on the child of the current vertex if it hasn't been
	// visited yet
	while (origGraph[i] != intNil){
		if (color[intFirst(origGraph[i])] == 0){
			parent[intFirst(origGraph[i])] = i;
			timer = visitPhase2(intFirst(origGraph[i]), color, origGraph, n, dtime, ftime, parent, stack, timer);
		}else{
			origGraph[i] = intRest(origGraph[i]);
		}
	}

	// set color to black, add the finish time of current vertex, then increment the time
	color[i] = 2;
	ftime[i] = timer;
	timer++;
	return timer;
}

int findRootPhase2(int v, int *parent){
	// if it is a root (has a parent of -1), then return current vertex as the leader,
	// otherwise call findRootPhase2 on the parent of the current vertex
	if (parent[v] == -1){
		return v;
	}else{
		return (findRootPhase2(parent[v], parent));
	}
}

void printArraysPhase2(int n, int *dtime, int *ftime, int *parent, int *root){
	// variable initialization and formatting
	int i, j, flag;
	printf("\n");
	if (n > 9){
		printf(" ");
	}

	// prints the table of array values
	printf("v dT fT  p  r\n");
	for (i = 1; i < n + 1; i++){
		if (dtime[i] > 0){
			if (n > 9){
				printf("%2d %2d %2d %2d %2d\n", i, dtime[i], ftime[i], parent[i], root[i]);
			}else{
				printf("%1d %2d %2d %2d %2d\n", i, dtime[i], ftime[i], parent[i], root[i]);
			}
		}
	}
	printf("\n");

	// prints the SCC groups
	for (i = 1; i < n + 1; i++){
		flag = 0;
		for (j = 1; j < n + 1; j++){
			if (root[j] == i){
				printf("SCC with leader %d containing: ", i);
				flag = 1;
				break;
			}
		}
		for (j = 1; j < n + 1; j++){
			if (root[j] == i){
				printf("%d ", j);
			}
		}
		if (flag == 1){
			printf("\n");
		}
	}
}