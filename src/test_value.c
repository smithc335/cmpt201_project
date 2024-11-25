// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

    srand(time(NULL));

    char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;
    int inds[3] = {0, 0, 695};
    int err;

    // FOR SOME REASON RAND IS JUST SWITCHING BETWEEN 1 AND 2??
    inds[1] = (rand() % (paintN - 2)) + 1; // min 1, max 694 to get a middle index
    printf("inds = {%i, %i, %i}\n", inds[0], inds[1], inds[2]);

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);

    printf("Printing indexes %i, %i, and %i:\n", inds[0], inds[1], inds[2]);
    for(int i=0; i<3; i++){
        err = printPaint(paintArray, inds[i], paintN);
        if(err==1){
            printf("Function was unsuccessful.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Tests for getPaintRange (CLAIRE)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintRange:\n");
	printf("------------------------------------------------------------\n");

    paint_t* spaRange;
    int spaRangeN;
    float range[] = {0, 0};

    spaRange = getPaintRange(paintArray, paintN, range[0], range[1], HUE, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], VALUE, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], GRANULATING, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], TRANSPARENT, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], STAINING, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], BLOOM, &spaRangeN);
    // spaRange = getPaintRange(paintArray, paintN, range[0], range[1], LIGHTFAST, &spaRangeN);

    printf("Number of HUE values in the range [%.1f, %.1f]: %i\n", range[0], range[1], spaRangeN);
    for (int i=0; i<spaRangeN; i++){
        printf("%s, %s, %s, ", spaRange[i].ciName, spaRange[i].marketingName, spaRange[i].manufacturer);
	    printf("%i, %i, %i, ", spaRange[i].transparency, spaRange[i].staining, spaRange[i].valueRange);
	    printf("%i, %i, %i, ", spaRange[i].granulating, spaRange[i].blossom, spaRange[i].diffusion);
	    printf("%i, %i, %i\n", spaRange[i].hueAngle, spaRange[i].hueShift, spaRange[i].lightfast);
    }

    // deallocate memory for sub array
    free(spaRange);
    spaRange = NULL;

    // Tests for getPaintValue (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintValue:\n");
	printf("------------------------------------------------------------\n");
 
    paint_t* subPaint;
    // char name[] = "cerulean blue";
    // char name[] = "PBk9";
    char name[] = "DaVinci";
    int numResult = 0;

    // subPaint = getPaintValue(paintArray, paintN, name, MARKETINGNAME, &numResult);
    // subPaint = getPaintValue(paintArray, paintN, name, CINAME, &numResult);
    subPaint = getPaintValue(paintArray, paintN, name, MANUFACTURER, &numResult);
    
    if(subPaint == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    printf("The number of elements that have the name %s is %d\n", name, numResult);

    for (int i = 0; i < numResult ; i++){
        printf("%s, %s, %s, ", subPaint[i].ciName, subPaint[i].marketingName, subPaint[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint[i].transparency, subPaint[i].staining, subPaint[i].valueRange);
	    printf("%i, %i, %i, ", subPaint[i].granulating, subPaint[i].blossom, subPaint[i].diffusion);
	    printf("%i, %i, %i\n", subPaint[i].hueAngle, subPaint[i].hueShift, subPaint[i].lightfast);
    }

    // deallocate memory for paintArray
	free(paintArray);
	paintArray = NULL;
    free(subPaint);
    subPaint = NULL;

    exit(EXIT_SUCCESS);
}