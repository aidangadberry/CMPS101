//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#include <stdlib.h>
#include "edgeList.h"
#include <stdio.h>
#include <string.h>

struct EdgeListNode{
	EdgeInfo data;
	EdgeList next;
};

const EdgeList edgeNil = NULL;

// ---------- Constructors ---------------------- //

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
	EdgeList newEdge = calloc(1, sizeof(struct EdgeListNode));
	newEdge->data = newE;
	newEdge->next = oldL;
	return newEdge;
}

// ---------- Access Functions ------------------ //

EdgeInfo edgeFirst(EdgeList oldL){
	return oldL->data;
}

EdgeList edgeRest(EdgeList oldL){
	return oldL->next;
}
