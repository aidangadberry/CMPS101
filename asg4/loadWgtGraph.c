//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#include <stdlib.h>
#include "loadWgtGraph.h"
#include "edgeList.h"
#include "minPQ.h"
#include <stdio.h>
#include <string.h>

// ---------- Other Functions ------------------- //

// prints the array of EdgveLists with proper formatting
// Pre: edgeArr != NULL, n >= 0
// Post: edgeArr, n, and m are unchanged, array is printed to console 
void printGraph(EdgeList* edgeArr, int n){
	int i;
	EdgeList* arrCopy;
	EdgeInfo info;
	double weight;
	int next;
	arrCopy = calloc(n + 1, sizeof(EdgeList));
	memcpy(arrCopy, edgeArr, (n + 1) * sizeof(EdgeList));
	printf("From   To     Weight\n");
	printf("--------------------\n");
	for (i = 1; i < n + 1; i++){
		printf("%-7d", i);
		if (arrCopy[i] == edgeNil){
			printf("null   null\n");
		}else{
			info = edgeFirst(arrCopy[i]);
			weight = info.wgt;
			next = info.to;
			printf("%-7d%-7.2lf\n", next, weight);
			arrCopy[i] = edgeRest(arrCopy[i]);
			while (arrCopy[i] != edgeNil){
				info = edgeFirst(arrCopy[i]);
				weight = info.wgt;
				next = info.to;
				printf("       %-7d%-7.2lf\n", next, weight);
				arrCopy[i] = edgeRest(arrCopy[i]);
			}
		}
		printf("--------------------\n");
	}
	printf("\n");
}

void printPrim(int n, int parent[], double priority[], int status[], char flag){
	int i;
	if (flag == 'P'){
		printf("Prim's Graph Traversal\n\n");
	}else{
		printf("Dijkstra's Graph Traversal\n\n");
	}
	printf("Vert  Status  Parent  Priority\n");
	for (i = 1; i < n + 1; i++){
		if (status[i] != 'u'){
			printf("%-6d%-8c%-8d%-.2lf\n", i, status[i], parent[i], priority[i]);
		}else{
			printf("%-6du       N/A     N/A\n", i);
		}
	}
	printf("\n");
}

void primMST(EdgeList* adjInfo, int n, int s, int parent[], double priority[], int status[], char flag){
	MinPQ pq = createPQ(n, status, priority, parent);
	int v;

	insertPQ(pq, s, 0, -1);
	while (isEmptyPQ(pq) == 0){
		printPrim(n, parent, priority, status, flag);
		v = getMin(pq);
		delMin(pq);
		updateFringe(pq, adjInfo[v], v, flag);
	}
}

void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, char flag){
	EdgeList remAdj;
	int w;
	double newWgt;
	double addWgt = 0;
	if (flag == 'D'){
		addWgt = getPriority(pq, v);
	}
	remAdj = adjInfoOfV;
	while (remAdj != edgeNil){
		EdgeInfo wInfo = edgeFirst(remAdj);
		w = wInfo.to;
		newWgt = wInfo.wgt + addWgt;
		if (getStatus(pq, w) == UNSEEN){
			insertPQ(pq, w, newWgt, v);
		}else if (getStatus(pq, w) == FRINGE){
			if (newWgt < getPriority(pq, w)){
				decreaseKey(pq, w, newWgt, v);
			}
		}
		remAdj = edgeRest(remAdj);
	}
}





