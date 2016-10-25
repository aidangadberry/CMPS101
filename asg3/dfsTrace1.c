//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include <stdlib.h>
#include "dfsTrace1.h"
#include "intList.h"
#include <stdio.h>
#include <string.h>

void dfsTrace1(IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack){
	// initialize variables
	int timer = 1;
	int i;
	int color[n+1];

	//create a copy of the graph so the original doesn't get affected
	IntList* arrCopy;
	arrCopy = calloc(n + 1, sizeof(IntList));
	memcpy(arrCopy, origGraph, (n + 1) * sizeof(IntList));

	// initialize all of the information arrays
	for (i = 1; i < n + 1; i++){
		color[i] = 0;
		dtime[i] = 0;
		ftime[i] = 0;
		parent[i] = -1;
		stack[i] = 0;
	}

	// call the recursive DFS call (visitTrace1) using each valid vertex
	// as a starting vertex
	for (i = 1; i < n + 1; i++){
		if (color[i] == 0){
			if (arrCopy[i] != intNil){
				timer = visitTrace1(i, color, arrCopy, n, dtime, ftime, parent, stack, timer);
			}
		}
	}

	// call the print function to print the results of each array
	printArraysTrace1(n, dtime, ftime, parent, stack);
}

int visitTrace1(int i, int *color, IntList* origGraph, int n, int *dtime, int *ftime, int *parent, int *stack, int timer){
	// set color to grey, add the discover time of the current vertex, then increment the time
	color[i] = 1;
	dtime[i] = timer;
	timer++;

	// recursively call visit function on the child of the current vertex if it hasn't been
	// visited yet
	while (origGraph[i] != intNil){
		if (color[intFirst(origGraph[i])] == 0){
			parent[intFirst(origGraph[i])] = i;
			timer = visitTrace1(intFirst(origGraph[i]), color, origGraph, n, dtime, ftime, parent, stack, timer);
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

void printArraysTrace1(int n, int *dtime, int *ftime, int *parent, int *stack){
	// variable initialization and formatting
	int i;
	int k;
	int numVert = 0;
	int max;
	printf("\n");
	if (n > 9){
		printf(" ");
	}

	// prints the table of array values
	printf("v dT fT  p\n");
	for (i = 1; i < n + 1; i++){
		if (dtime[i] > 0){
			if (n > 9){
				printf("%2d %2d %2d %2d\n", i, dtime[i], ftime[i], parent[i]);
			}else{
				printf("%1d %2d %2d %2d\n", i, dtime[i], ftime[i], parent[i]);
			}
			numVert++;
		}
	}
	printf("\n");

	// sets the stack based on the finish times of each vertex
	for (i = 1; i < numVert + 1; i++){
		max = 1;
		for (k = 1; k < numVert + 1; k++){
			if (ftime[k] > ftime[max]){
				max = k;
			}
		}
		ftime[max] = 0;
		stack[i] = max;
	}

	// prints the stack
	printf("Stack: ");
	for (i = 1; i < numVert + 1; i++){
		printf("%d ", stack[i]);
	}
	printf("\n\n");
}
