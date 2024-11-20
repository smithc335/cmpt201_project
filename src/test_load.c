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

    char filename[] = "pigments.dat";
    int numlines = 10;

    pigment_t *pArray = NULL;

    pArray = loadPigmentData(filename, pArray, &numlines);
    if (pArray == NULL){
        printf("Error: Function Failed.\n");
        exit(EXIT_FAILURE);
    }

	printf("Number of data entries in %s: %d\n", filename, numlines);
    printf("\nLine 1: ciName = %s, pigmentname = %s, value = %d, chroma = %d, abvalue = [%d, %d], hueAngle = %d, huePurity = %.2f, abHp = [%.2f, %.2f]\n", pArray[0].ciName, pArray[0].pigmentName, pArray[0].value, pArray[0].chroma, pArray[0].abValue[0], pArray[0].abValue[1], pArray[0].hueAngle, pArray[0].huePurity, pArray[0].abHp[0], pArray[0].abHp[1]);
    printf("Line 30: ciName = %s, pigmentname = %s, value = %d, chroma = %d, abvalue = [%d, %d], hueAngle = %d, huePurity = %.2f, abHp = [%.2f, %.2f]\n", pArray[29].ciName, pArray[29].pigmentName, pArray[29].value, pArray[29].chroma, pArray[29].abValue[0], pArray[29].abValue[1], pArray[29].hueAngle, pArray[29].huePurity, pArray[29].abHp[0], pArray[29].abHp[1]);
    printf("Line 111: ciName = %s, pigmentname = %s, value = %d, chroma = %d, abvalue = [%d, %d], hueAngle = %d, huePurity = %.2f, abHp = [%.2f, %.2f]\n", pArray[110].ciName, pArray[110].pigmentName, pArray[110].value, pArray[110].chroma, pArray[110].abValue[0], pArray[110].abValue[1], pArray[110].hueAngle, pArray[110].huePurity, pArray[110].abHp[0], pArray[110].abHp[1]);
    printf("Line 170: ciName = %s, pigmentname = %s, value = %d, chroma = %d, abvalue = [%d, %d], hueAngle = %d, huePurity = %.2f, abHp = [%.2f, %.2f]\n\n", pArray[169].ciName, pArray[169].pigmentName, pArray[169].value, pArray[169].chroma, pArray[169].abValue[0], pArray[169].abValue[1], pArray[169].hueAngle, pArray[169].huePurity, pArray[169].abHp[0], pArray[169].abHp[1]);

    free(pArray);
    pArray = NULL;

	// Tests for loadPaintData
	printf("------------------------------------------------------------\n");
	printf("Tests for loadPaintData:\n");
	printf("------------------------------------------------------------\n");

	srand(time(NULL));

	char paintFilename[] = "paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;
	int r;

	paintArray = loadPaintData(paintFilename, paintArray, &paintN);
	r = rand() % (paintN + 1);

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