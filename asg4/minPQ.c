//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#include <stdlib.h>
#include "minPQ.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Multiple typedefs for the same type are an error in C. */

struct MinPQNode{
	int numVert, numPQ, minVert;
	double oo;
	int* parent;
	double* priority;
	int* status;
};

// ---------- Constructors ---------------------- //

MinPQ createPQ(int n, int status[], double priority[], int parent[]){
	int i;
	MinPQ newMinPQ = calloc(n, sizeof(struct MinPQNode));
	newMinPQ->status = status;
	newMinPQ->priority = priority;
	newMinPQ->parent = parent;
	for (i = 1; i < n + 1; i++){
		status[i] = UNSEEN;
		parent[i] = -1;
	}
	newMinPQ->numVert = n;
	newMinPQ->numPQ = 0;
	newMinPQ->minVert = -1;
	newMinPQ->oo = INFINITY;
	return newMinPQ;
}

// ---------- Access Functions ------------------ //

int isEmptyPQ(MinPQ pq){
	return (pq->numPQ == 0);
}

int getMin(MinPQ pq){
	int v;
	double minWgt;
	minWgt = pq->oo;
	if (pq->minVert == -1){
		for (v = 1; v <= pq->numVert; v++){
			if (pq->status[v] == FRINGE){
				if (pq->priority[v] < minWgt){
					pq->minVert = v;
					minWgt = pq->priority[v];
				}
			}
		}
	}
	return pq->minVert;
}

int getStatus(MinPQ pq, int id){
	return pq->status[id];
}

int getParent(MinPQ pq, int id){
	return pq->parent[id];
}

double getPriority(MinPQ pq, int id){
	return pq->priority[id];
}

// ---------- Manipulation Procedures ----------- //

void delMin(MinPQ pq){
	int oldMin = getMin(pq);
	pq->status[oldMin] = INTREE;
	pq->minVert = -1;
	pq->numPQ--;
}

void insertPQ(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->priority[id] = priority;
	pq->status[id] = FRINGE;
	pq->minVert = -1;
	pq->numPQ++;
}

void decreaseKey(MinPQ pq, int id, double priority, int par){
	pq->parent[id] = par;
	pq->priority[id] = priority;
	pq->minVert = -1;
}
