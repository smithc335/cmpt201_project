// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pigment.h"

int main(void){

    srand(time(NULL)); 

    // Tests for printPigment (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for printPigment:\n");
	printf("------------------------------------------------------------\n");

    char pigmentFilename[] = "../data/pigments.dat"; 
    int numLines = 10;
    pigment_t* pigmentArray = NULL;
   // int indexN = -1;
    int errN = 1;
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
    printf("\n------------------------------------------------------------\n");
	printf("Tests for printPaint:\n");
	printf("------------------------------------------------------------\n");

    srand(time(NULL));

    char paintFilename[] = "../data/paints.dat";
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
 
    int ranN;
    ranN = rand() % (paintN);
    // printf("Index tested = %d\n", ranN);

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

    printf("Marketing Name tested is %s.\n", markName);
    printf("Manufacture Name tested is %s.\n", manName);
    printf("C.I. Name tested is %s.\n", cName);


    subPaint1 = getPaintValue(paintArray, paintN, markName, MARKETINGNAME, &numResult1);
    if(subPaint1 == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    subPaint2 = getPaintValue(paintArray, paintN, manName, MANUFACTURER, &numResult2);
    if(subPaint2 == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    subPaint3 = getPaintValue(paintArray, paintN, cName, CINAME, &numResult3);
    if(subPaint3 == NULL){
		printf("Function was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }


    printf("------------------------------------------------------------\n");

    printf("The number of elements that have the marketing name %s is %d\n", markName, numResult1);

    for (int i = 0; i < numResult1 ; i++){
        printf("%s, %s, %s, ", subPaint1[i].ciName, subPaint1[i].marketingName, subPaint1[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint1[i].transparency, subPaint1[i].staining, subPaint1[i].valueRange);
	    printf("%i, %i, %i, ", subPaint1[i].granulating, subPaint1[i].blossom, subPaint1[i].diffusion);
	    printf("%i, %i, %i\n", subPaint1[i].hueAngle, subPaint1[i].hueShift, subPaint1[i].lightfast);
    }

    printf("The number of elements that have the manufacturer name %s is %d\n", manName, numResult2);

    for (int i = 0; i < numResult2 ; i++){
        printf("%s, %s, %s, ", subPaint2[i].ciName, subPaint2[i].marketingName, subPaint2[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint2[i].transparency, subPaint2[i].staining, subPaint2[i].valueRange);
	    printf("%i, %i, %i, ", subPaint2[i].granulating, subPaint2[i].blossom, subPaint2[i].diffusion);
	    printf("%i, %i, %i\n", subPaint2[i].hueAngle, subPaint2[i].hueShift, subPaint2[i].lightfast);
    }


    printf("The number of elements that have the ciname %s is %d\n", cName, numResult3);

    for (int i = 0; i < numResult3 ; i++){
        printf("%s, %s, %s, ", subPaint3[i].ciName, subPaint3[i].marketingName, subPaint3[i].manufacturer);
	    printf("%i, %i, %i, ", subPaint3[i].transparency, subPaint3[i].staining, subPaint3[i].valueRange);
	    printf("%i, %i, %i, ", subPaint3[i].granulating, subPaint3[i].blossom, subPaint3[i].diffusion);
	    printf("%i, %i, %i\n", subPaint3[i].hueAngle, subPaint3[i].hueShift, subPaint3[i].lightfast);
    }

    // deallocate memory for paintArray and sub array
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