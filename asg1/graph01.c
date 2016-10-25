//===============================================//
//  Name:        Aidan Gadberry					 //
//  User ID:     agadberr						 //
//  Date:        4/15/2015						 //
//  Program:     Programming Assignment 1		 //
//===============================================//

#include <stdlib.h>
#include "intList.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){

	// declare variables
	int i;
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

	// allocate memory for an array of IntLists, with the length of the 
	// array = half the quantity of numbers stored in intLine
	IntList* intArr;
	intArr = calloc(len + 1, sizeof(IntList));
	for (i = 0; i < (len+1)/2; i++){
		intArr[i] = intNil;
	}

	// go through the inLine array, looking at every other value, starting
	// at 1, and making the corresponding following value another entry at
	// intArr[inLine[i]]. This will order the array of IntLists into a way
	// that can be easily read and printed
	for (i = 1; i < len; i += 2){
		if (inLine[i] > inLine[0]){
			printf("Error: %d is out of the range 1-%d\n", inLine[i], inLine[0]);
		}else{
			intArr[inLine[i]] = intCons(inLine[i+1], intArr[inLine[i]]);
		}
	}

	// print out the array of IntLists with the proper formatting
	printf("n = %d\n", inLine[0]);
	printf("m = %d\n", (len-1)/2);
	for (i = 1; i < inLine[0] + 1; i++){
		printf("%d\t", i);
		if (intArr[i] == intNil){
			printf("null\n");
		}else{
			printf("[");
			printf("%d", intFirst(intArr[i]));
			intArr[i] = intRest(intArr[i]);
			while (intArr[i] != intNil){
				printf(", %d", intFirst(intArr[i]));
				intArr[i] = intRest(intArr[i]);
			}
			printf("]\n");
		}
	}

	// exit
	return 0;
}