// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    // Tests for printPigment (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for printPigment:\n");
	printf("------------------------------------------------------------\n");

    // Tests for printPaint (CLAIRE)
    printf("------------------------------------------------------------\n");
	printf("Tests for printPaint:\n");
	printf("------------------------------------------------------------\n");

    char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);

    // Tests for getPaintRange (CLAIRE)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintRange:\n");
	printf("------------------------------------------------------------\n");

    paint_t* spaRange;
    int spaRangeN;
    float range[] = {0.5, 1};

    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], HUE, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], VALUE, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], GRANULATING, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], TRANSPARENT, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], STAINING, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], BLOOM, &spaRangeN);
    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], LIGHTFAST, &spaRangeN);

    // deallocate memory for sub array
    free(spaRange);
    spaRange = NULL;

    // Tests for getPaintValue (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintValue:\n");
	printf("------------------------------------------------------------\n");
 

    paint_t* paintPoint;
    char name[] = "cerulean blue";
    int* numResult = 0;


    paintPoint = getPaintValue(paintArray, &paintN, name, MARKETINGNAME, &numResult);

    printf("The number of elements that have the name %s is %d\n", name, numResult);

    for (int i = 0; i < numResult ; i++){
        printf("%s, %s, %s, ", paintPoint[i].ciName, paintPoint[i].marketingName, paintPoint[i].manufacturer);
	    printf("%i, %i, %i, ", paintPoint[i].transparency, paintPoint[i].staining, paintPoint[i].valueRange);
	    printf("%i, %i, %i, ", paintPoint[i].granulating, paintPoint[i].blossom, paintPoint[i].diffusion);
	    printf("%i, %i, %i\n", paintPoint[i].hueAngle, paintPoint[i].hueShift, paintPoint[i].lightfast);

    }


    // deallocate memory for paintArray
	free(paintArray);
	paintArray = NULL;

    exit(EXIT_SUCCESS);
}