// Claire Smith and Matt Beaulieu
// Project Milestone 1 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pigment.h"

int main(void){

	// Tests for loadPigmentData
	printf("------------------------------------------------------------\n");
	printf("Tests for loadPigmentData:\n");
	printf("------------------------------------------------------------\n");

    char pigmentFilename[] = "../data/pigments.dat"; 
    int numLines = 10;
	srand(time(NULL));
    pigment_t* pigmentArray = NULL;
	int randomNum;
	
    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &numLines);
    if(pigmentArray == NULL){
        printf("Function was unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

	randomNum = rand() % (numLines - 9);
	printf("Number of data entries in %s: %d\n", pigmentFilename, numLines);
	printf("\nSample of loaded data from lines %i to %i:\n", randomNum+10, randomNum+19);
	printf("------------------------------------------------------------\n");

	for(int i=0; i<10; i++){
		printf("Line %d: ", randomNum+10+i);
		printf("%s, %s, %d, ", pigmentArray[randomNum+i].ciName, pigmentArray[randomNum+i].pigmentName, pigmentArray[randomNum+i].value);
		printf("%d, %d, %d, ", pigmentArray[randomNum+i].chroma, pigmentArray[randomNum+i].abValue[0], pigmentArray[randomNum+i].abValue[1]);
		printf("%d, %.2f, %.2f, %.2f\n", pigmentArray[randomNum+i].hueAngle, pigmentArray[randomNum+i].huePurity, pigmentArray[randomNum+i].abHp[0], pigmentArray[randomNum+i].abHp[1]);
	}

	printf("------------------------------------------------------------\n");

    free(pigmentArray);
    pigmentArray = NULL;

	// Tests for loadPaintData
	printf("------------------------------------------------------------\n");
	printf("Tests for loadPaintData:\n");
	printf("------------------------------------------------------------\n");

	srand(time(NULL));

	char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;
	int r;

	paintArray = loadPaintData(paintFilename, paintArray, &paintN);
	r = rand() % (paintN - 9); // min 0 and max 686 to account for printing 10 lines

	if(paintArray == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Number of data entries in %s: %i\n", paintFilename, paintN);
		printf("\nSample of loaded data from lines %i to %i:\n", r+13, r+22);
		printf("------------------------------------------------------------\n");
		
		for(int i=0; i<10; i++){
			printf("Line %i: ", r+i+13);
			printf("%s, %s, %s, ", paintArray[r+i].ciName, paintArray[r+i].marketingName, paintArray[r+i].manufacturer);
			printf("%i, %i, %i, ", paintArray[r+i].transparency, paintArray[r+i].staining, paintArray[r+i].valueRange);
			printf("%i, %i, %i, ", paintArray[r+i].granulating, paintArray[r+i].blossom, paintArray[r+i].diffusion);
			printf("%i, %i, %i\n", paintArray[r+i].hueAngle, paintArray[r+i].hueShift, paintArray[r+i].lightfast);
		}

		printf("------------------------------------------------------------\n");

	// deallocate memory
	free(paintArray);
	paintArray = NULL;
	}

	return (0);
}