//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#include "edgeList.h"
#include "minPQ.h"

// ---------- Other Functions ------------------- //

// prints the array of EdgeLists with proper formatting
// Pre: edgeArr != NULL, n >= 0
// Post: edgeArr, n, and m are unchanged, array is printed to console 
void printGraph(EdgeList* EdgeArr, int n);


void printPrim(int n, int parent[], double priority[], int status[], char flag);


void primMST(EdgeList* adjInfo, int n, int s, int parent[], double priority[], int status[], char flag);


void updateFringe(MinPQ pq, EdgeList adjInfoOfV, int v, char flag);