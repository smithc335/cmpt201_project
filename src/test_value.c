// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pigment.h"

int main(void){

    // Tests for printPigment (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for printPigment:\n");
	printf("------------------------------------------------------------\n");

    char pigmentFilename[] = "../data/pigments.dat"; 
    int numLines = 10;
    pigment_t* pigmentArray = NULL;
   // int indexN = -1;
    int errN = 1;
	srand(time(NULL)); // We probably only need one of these
	int randomNum;
    int randomind[3];
	
	
    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &numLines);
    if(pigmentArray == NULL){
        printf("Error: Function [pigmentArray] failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; i++){
        randomNum = rand() % (numLines);
        randomind[i] = randomNum;
    }
    printf("Indices tested are: {%d, %d, %d}.\n", randomind[0], randomind[1], randomind[2]);

    for (int i = 0; i < 3; i++){
        errN = printPigment(pigmentArray, randomind[i], numLines);
        if (errN == 1){
            printf("Error: Function [printPigment] failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    free(pigmentArray);
    pigmentArray = NULL;





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
 
    int ranN;
    ranN = rand() % (paintN);
    printf("Index tested = %d\n", ranN);

    paint_t* subPaint1;
    paint_t* subPaint2;
    paint_t* subPaint3;

    char markName[100];
    char manName[100];
    char cName[100];

    int numResult1 = 0;
    int numResult2 = 0;
    int numResult3 = 0;

    strcpy(markName, paintArray[ranN].marketingName);
    strcpy(manName, paintArray[ranN].manufacturer);
	strcpy(cName, paintArray[ranN].ciName);

    printf("markName is %s.\n", markName);
    printf("manName is %s.\n", manName);
    printf("cName is %s.\n", cName);


    // subPaint1 = getPaintValue(paintArray, paintN, markName, MARKETINGNAME, &numResult1);
    // if(subPaint1 == NULL){
	// 	printf("Function was unsuccessful.\n");
	// 	exit(EXIT_FAILURE);
    // }

    // subPaint2 = getPaintValue(paintArray, paintN, manName, MANUFACTURER, &numResult2);
    // if(subPaint2 == NULL){
	// 	printf("Function was unsuccessful.\n");
	// 	exit(EXIT_FAILURE);
    // }

    subPaint3 = getPaintValue(paintArray, paintN, cName, CINAME, &numResult3);
    if(subPaint3 == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    // printf("The number of elements that have the marketing name %s is %d\n", markName, numResult1);

    // for (int i = 0; i < numResult1 ; i++){
    //     printf("%s, %s, %s, ", subPaint1[i].ciName, subPaint1[i].marketingName, subPaint1[i].manufacturer);
	//     printf("%i, %i, %i, ", subPaint1[i].transparency, subPaint1[i].staining, subPaint1[i].valueRange);
	//     printf("%i, %i, %i, ", subPaint1[i].granulating, subPaint1[i].blossom, subPaint1[i].diffusion);
	//     printf("%i, %i, %i\n", subPaint1[i].hueAngle, subPaint1[i].hueShift, subPaint1[i].lightfast);
    // }

    // printf("The number of elements that have the manufacturer name %s is %d\n", manName, numResult2);

    // for (int i = 0; i < numResult2 ; i++){
    //     printf("%s, %s, %s, ", subPaint2[i].ciName, subPaint2[i].marketingName, subPaint2[i].manufacturer);
	//     printf("%i, %i, %i, ", subPaint2[i].transparency, subPaint2[i].staining, subPaint2[i].valueRange);
	//     printf("%i, %i, %i, ", subPaint2[i].granulating, subPaint2[i].blossom, subPaint2[i].diffusion);
	//     printf("%i, %i, %i\n", subPaint2[i].hueAngle, subPaint2[i].hueShift, subPaint2[i].lightfast);
    // }


    printf("The number of elements that have the ciname %s is %d\n", cName, numResult3);

    for (int i = 0; i < numResult3 ; i++){
        printf("%s, %s, %s, ", subPaint3[i].ciName, subPaint3[i].marketingName, subPaint3[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint3[i].transparency, subPaint3[i].staining, subPaint3[i].valueRange);
	    printf("%i, %i, %i, ", subPaint3[i].granulating, subPaint3[i].blossom, subPaint3[i].diffusion);
	    printf("%i, %i, %i\n", subPaint3[i].hueAngle, subPaint3[i].hueShift, subPaint3[i].lightfast);
    }

    // deallocate memory for paintArray


	free(paintArray);
	paintArray = NULL;
    free(subPaint1);
    subPaint1 = NULL;
    free(subPaint2);
    subPaint2 = NULL;
    free(subPaint3);
    subPaint3 = NULL;

    exit(EXIT_SUCCESS);
}