//===============================================//
//  Name:        Aidan Gadberry					 //
//  User ID:     agadberr						 //
//  Date:        4/15/2015						 //
//  Program:     Programming Assignment 1		 //
//===============================================//

#ifndef C101IntList
#define C101IntList

// the struct of the IntList, making both the element at the node
// and the location of the next node accessible
typedef struct IntListNode * IntList;

// defining constant intNil to be NULL
const IntList intNil;

// ---------- Access Functions ------------------ //

// returns the element in the given IntList
// Pre: aList != NULL
// Post: aList still exists, aList->element is returned but remains
//       unchanged, aList->next unchanged
int intFirst(IntList oldL);

// ---------- Manipulation Procedures ----------- //

// essentially pops off the first IntList by returning aList->next
// Pre: aList != NULL
// Post: original aList is removed from linked list, return pointer
//       to aList with unchanged aList->element and aList->next
IntList intRest(IntList oldL);

// ---------- Constructors ---------------------- //

// constructs a new IntList node with element value newElement that
// connects to the front of the oldList
// Pre: newElement is int
// Post: return the new IntList at the head of the linked list, with
//       values newList->element = newElement and newList->next =
//       the oldList, or intNil if intCons was called on an intNil
IntList intCons(int newE, IntList oldL);

#endif