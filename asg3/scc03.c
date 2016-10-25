//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include <stdlib.h>
#include "intList.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"
#include "loadGraph.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){

	// declare variables
	int i, n, m;
	int len = 0;
	FILE *in;
	int inLine[1024];
	int line;

	// make sure the function has been called correctly, and that the
	// given file is able to be opened
	if (argc != 2){
      	printf("Usage: %s <input file>\n", argv[0]);
      	exit(1);
   	}
   	if (strcmp(argv[1],"-") == 0){
   		in = stdin;
   	}else{
   		in = fopen(argv[1], "r");
   	}
	if (in == NULL){
		printf("Unable to open file %s for reading\n", argv[1]);
		exit (1);
	}
	printf("Opened %s for input.\n", argv[1]);

	// scan input file and put each number into an array, 1 per index
	while(fscanf(in, "%d", &line) != EOF){
		inLine[len] = line;
		len++;
	}

	// set the length of the array as n, and the total number of intList
	// elements in the array as m
	n = inLine[0];
	m = 0;
	int dtime[n+1];
	int ftime[n+1];
	int parent[n+1];
	int stack[n+m];
	int root[n+1];

	// allocate memory for an array of IntLists, with the length of the 
	// array = half the quantity of numbers stored in intLine
	IntList* intArr;
	intArr = calloc(n + 1, sizeof(IntList));
	for (i = 0; i < n + 1; i++){
		intArr[i] = intNil;
	}

	// go through the inLine array, looking at every other value, starting
	// at 1, and making the corresponding following value another entry at
	// intArr[inLine[i]]. This will order the array of IntLists into a way
	// that can be easily read and printed
	for (i = 1; i < len; i += 2){
		if (inLine[i] > n){
			printf("Error: %d is out of the vertex range 1-%d\n", inLine[i], n);
		}
		if (inLine[i+1] > n){
			printf("Error: %d is out of the edge range 1-%d\n", inLine[i+1], n);
		}
		if (inLine[i] <= n && inLine[i+1] <= n){
			intArr[inLine[i]] = intCons(inLine[i+1], intArr[inLine[i]]);
			m++;
		}
	}

	// prints the original graph, then calls dfsTrace1 on it
	printGraph(intArr, n, m);
	dfsTrace1(intArr, n, dtime, ftime, parent, stack);

	// transposes the graph, prints it, then calls dfsTrace2 on it
	intArr = transposeGraph(intArr, n);
	printGraph(intArr, n, m);
	dfsPhase2(intArr, n, dtime, ftime, parent, stack, root);
	// exit
	return 0;
}
