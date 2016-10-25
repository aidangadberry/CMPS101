//===============================================//
//  Name:        Aidan Gadberry                  //
//  User ID:     agadberr                        //
//  Date:        6/3/2015                        //
//  Program:     Programming Assignment 4        //
//===============================================//

#ifndef C101MinPQ
#define C101MinPQ
/* Multiple typedefs for the same type are an error in C. */

typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

// ---------- Constructors ---------------------- //

/**
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);

// ---------- Access Functions ------------------ //

/** isEmpty
*/
int isEmptyPQ(MinPQ pq);

/** getMin
*/
int getMin(MinPQ pq);

/** getStatus
*/
int getStatus(MinPQ pq, int id);

/** getParent
*/
int getParent(MinPQ pq, int id);

/** getPriority
*/
double getPriority(MinPQ pq, int id);

// ---------- Manipulation Procedures ----------- //

/** delMin
*/
void delMin(MinPQ pq);

/** insertPQ
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);


#endif
