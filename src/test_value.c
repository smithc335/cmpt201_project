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

    char pigmentFilename[] = "../cmpt201_project/data/pigments.dat"; 
    int numLines = 10;
    pigment_t* pigmentArray = NULL;
    int indexN = -1;
    int errN = 1;
	// srand(time(NULL));
	// int randomNum;
	
    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &numLines);
    if(pigmentArray == NULL){
        printf("Error: Function [pigmentArray] failed.\n");
        exit(EXIT_FAILURE);
    }

   errN = printPigment(pigmentArray, indexN, numLines);
     if (errN == 1){
        printf("Error: Function [printPigment] failed.\n");
        exit(EXIT_FAILURE);
    }

    free(pigmentArray);
    pigmentArray = NULL;

    // Tests for printPaint (CLAIRE)
    printf("\n------------------------------------------------------------\n");
	printf("Tests for printPaint:\n");
	printf("------------------------------------------------------------\n");

    srand(time(NULL));

    // CHANGED FILENAME MEANS THAT SRC MAKEFILE DOESN'T WORK
        // HAVE TO CHANGE TO BIN DIRECTORY TO RUN PROJECT????????????
    char paintFilename[] = "../cmpt201_project/data/paints.dat";
	paint_t* paintArray = NULL;
	int paintN;
    int inds[3] = {0, 0, 695};
    int err;

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);

    inds[1] = (rand() % (paintN - 2)) + 1; // min 1, max 694 to get a middle index

    printf("Printing indexes %i, %i, and %i:\n", inds[0], inds[1], inds[2]);
    for(int i=0; i<3; i++){
        err = printPaint(paintArray, inds[i], paintN);
        if(err==1){
            printf("Function was unsuccessful.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Tests for getPaintRange (CLAIRE)
    printf("\n------------------------------------------------------------\n");
	printf("Tests for getPaintRange:\n");

    paint_t* spaRange;
    int spaRangeN;
    float ranges[2][2] = {{0.0, 0.0}, {0.4, 0.5}};
    // gRange_t paintMember;
    
    // paintMember = rand() % 7; // min 0, max 6 to get which value to search from enumeration

    for(int i=0; i<(sizeof(ranges)/sizeof(float[2])); i++){
        spaRange = getPaintRange(paintArray, paintN, ranges[i][0], ranges[i][1], LIGHTFAST, &spaRangeN);

        printf("------------------------------------------------------------\n");
        printf("Number of LIGHTFAST values in the range [%.1f, %.1f]: %i\n", ranges[i][0], ranges[i][1], spaRangeN);
        printf("------------------------------------------------------------\n");

        for (int j=0; j<spaRangeN; j++){
            // err = printPaint(spaRange, j, paintN);
            // if(err==1){
            //     printf("Function was unsuccessful.\n");
            //     exit(EXIT_FAILURE);
            // }
            printf("%s, %s, %s, ", spaRange[j].ciName, spaRange[j].marketingName, spaRange[j].manufacturer);
            printf("%i, %i, %i, ", spaRange[j].transparency, spaRange[j].staining, spaRange[j].valueRange);
            printf("%i, %i, %i, ", spaRange[j].granulating, spaRange[j].blossom, spaRange[j].diffusion);
            printf("%i, %i, %i\n", spaRange[j].hueAngle, spaRange[j].hueShift, spaRange[j].lightfast);
        }
    }

    // deallocate memory for sub array
    free(spaRange);
    spaRange = NULL;

    // Tests for getPaintValue (MATT)
    printf("\n------------------------------------------------------------\n");
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

    printf("The number of elements that have the name %s is %d.\n", name, numResult);
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numResult ; i++){
        printf("%s, %s, %s, ", subPaint[i].ciName, subPaint[i].marketingName, subPaint[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint[i].transparency, subPaint[i].staining, subPaint[i].valueRange);
	    printf("%i, %i, %i, ", subPaint[i].granulating, subPaint[i].blossom, subPaint[i].diffusion);
	    printf("%i, %i, %i\n", subPaint[i].hueAngle, subPaint[i].hueShift, subPaint[i].lightfast);
    }

    // deallocate memory for paintArray and sub array
	free(paintArray);
	paintArray = NULL;
    free(subPaint);
    subPaint = NULL;

    exit(EXIT_SUCCESS);
}