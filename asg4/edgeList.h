//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct{
    int to;
    double wgt;
}EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

// ---------- Constructors ---------------------- //

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);


EdgeInfo infoCons(int par, double weight);

// ---------- Access Functions ------------------ //

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

#endif
