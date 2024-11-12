// Claire Smith and Matt Beaulieu
// Project Milestone 1 Function Implementations

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pigment.h"

/*
int loadPigmentData(char* filename, pigment_t* pArray, int* n){
	// Matt's function
}
*/

int loadPaintData(char* filename, paint_t* pArray, int* n){ // n is number of entries not lines??

	FILE* fp = fopen(filename, "r");
	if(fp==NULL){
		return 1; // function failed (ANYWHERE ELSE??)
	}

	char line[140];
	char* gets_err;
	int capacity = 1;
	char* token;

	*n = 0; // make sure entries starts at zero

	// read unneeded lines
	for(int i=0; i<12; i++){
		fgets(line, 140, fp);
	}

	// allocate memory
	//pArray = malloc(capacity * sizeof(paint_t)); // allocate for 10 entries first

	// populate array
	gets_err = fgets(line, 95, fp); // get first entry line from file

	while(gets_err!=NULL){
		// reallocate if n > capacity of pArray
		if(*n >= capacity){
			capacity *= 2;
			pArray = realloc(pArray, (capacity * sizeof(paint_t)));
			printf("%i\n", capacity);
		}

		// tokenize line and populate
		// SOMETIMES THE MISSING VALUES ARE ',-,' SO WTF!!!
		token = strtok(line, ","); // ciName
		if(token!=NULL){
			strcpy(pArray[*n].ciName, token);
		}

		token = strtok(NULL, ","); // marketingName
		if(token!=NULL){
			strcpy(pArray[*n].marketingName, token);
		}

		token = strtok(NULL, ","); // manufacturer
        if(token!=NULL){
			strcpy(pArray[*n].manufacturer, token);
		}

		token = strtok(NULL, ","); // code (NOT LISTED IN STRUCT!)

		token = strtok(NULL, ","); // transparency
        if(token!=NULL){
			pArray[*n].transparency = atoi(token);
		}

		token = strtok(NULL, ","); // staining
        if(token!=NULL){
			pArray[*n].staining = atoi(token);
		}

		token = strtok(NULL, ","); // valueRange
        if(token!=NULL){
			pArray[*n].valueRange = atoi(token);
		}

		token = strtok(NULL, ","); // granulating
		if(token!=NULL){
	        pArray[*n].granulating = atoi(token);
		}

		token = strtok(NULL, ","); // blossom
        if(token!=NULL){
			pArray[*n].blossom = atoi(token);
		}

		token = strtok(NULL, ","); // diffusion
        if(token!=NULL){
			pArray[*n].diffusion = atoi(token);
		}

		token = strtok(NULL, ","); // hueAngle
        if(token!=NULL){
			pArray[*n].hueAngle = atoi(token);
		}

		token = strtok(NULL, ","); // hueShift
        if(token!=NULL){
			pArray[*n].hueShift = atoi(token);
			/*
			if(token[0]=='-'){
				pArray[*n].hueShift = -atoi(&token[1]);
			}
			else{
				pArray[*n].hueShift = atoi(token);
			}
			*/
		}

		token = strtok(NULL, "/"); // lightfast 1998
		token = strtok(NULL, "\0"); // lightfast 2004
        if(token!=NULL && token[0]!='.'){
			pArray[*n].lightfast = atoi(token);
		}

		// add entry to number of entries
		*n += 1;

		// get next entry line from file
		gets_err = fgets(line, 95, fp);
	}

	/*
	printf("%s, %s, %s, ", pArray[681].ciName, pArray[681].marketingName, pArray[681].manufacturer);
	printf("%i, %i, %i, ", pArray[681].transparency, pArray[681].staining, pArray[681].valueRange);
	printf("%i, %i, %i, ", pArray[681].granulating, pArray[681].blossom, pArray[681].diffusion);
	printf("%i, %i, %i\n", pArray[681].hueAngle, pArray[681].hueShift, pArray[681].lightfast);
	*/

	fclose(fp);

	return 0; // function was successful
}
