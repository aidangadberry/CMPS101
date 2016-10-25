//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        5/28/2015                       //
//  Program:     Programming Assignment 3        //
//===============================================//

#include <stdlib.h>
#include "edgeList.h"
#include "loadWgtGraph.h"
#include "minPQ.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){

	// declare variables
	int i, n, start;
	int len = 1;
	FILE *in;
	int child[1024];
	int curr[1024];
	double weight[1024];
	int to, from;
	char flag;
	double priority;

	// make sure the function has been called correctly, and that the
	// given file is able to be opened
	if (argc != 4){
      	printf("Usage: %s -P/D <start point> <input file>\n", argv[0]);
      	exit(1);
   	}
   	if (strcmp(argv[1],"-P") == 0){
   		flag = 'P';
   	}else if (strcmp(argv[1], "-D") == 0){
   		flag = 'D';
   	}else{
   		printf("Usage: %s -P/D <input file>\n", argv[0]);
   		exit(1);
   	}
   	start = atoi(argv[2]);
   	if (strcmp(argv[3],"-") == 0){
   		in = stdin;
   	}else{
   		in = fopen(argv[3], "r");
   	}
	if (in == NULL){
		printf("Unable to open file %s for reading\n", argv[3]);
		exit (1);
	}
	printf("\nOpened %s for input.\n\n", argv[3]);

	fscanf(in, "%d", &n);

	// scan input file and put each number into an array, 1 per index
	while(fscanf(in, "%d %d %lf", &from, &to, &priority) != EOF){
		curr[len] = from;
		child[len] = to;
		weight[len] = priority;
		len++;
	}

	// allocate memory for an array of EdgeLists, with the length of the 
	// array = half the quantity of numbers stored in inLine
	EdgeList* edgeArr;
	edgeArr = calloc(n+1, sizeof(EdgeList));
	for (i = 0; i < n + 1; i++){
		edgeArr[i] = edgeNil;
	}

	EdgeInfo* data = malloc(sizeof(EdgeInfo));
	int par[n+1];
	double pri[n+1];
	int stat[n+1];

	// go through the inLine array, looking at every other value, starting
	// at 1, and making the corresponding following value another entry at
	// edgeArr[inLine[i]]. This will order the array of EdgeLists into a way
	// that can be easily read and printed
	for (i = 1; i < len; i++){
		if (curr[i] > n){
			printf("Error: %d is out of the vertex range 1-%d\n", curr[i], n);
		}
		if (child[i] > n){
			printf("Error: %d is out of the edge range 1-%d\n", child[i], n);
		}
		if (weight[i] < 0.0){
			printf("Error: %.2lf is a negative number\n", weight[i]);
		}
		if ((curr[i] <= n && child[i] <= n) && weight[i] >= 0.0){
			data->to = child[i];
			data->wgt = weight[i];
			edgeArr[curr[i]] = edgeCons(*data, edgeArr[curr[i]]);
			if (flag == 'P'){
				data->to = curr[i];
				data->wgt = weight[i];
				edgeArr[child[i]] = edgeCons(*data, edgeArr[child[i]]);
			}
		}
	}
	// prints the original graph, then calls dfsTrace1 on it
	printGraph(edgeArr, n);
	primMST(edgeArr, n, start, par, pri, stat, flag);
	printPrim(n, par, pri, stat, flag);

	// exit
	return 0;
}
