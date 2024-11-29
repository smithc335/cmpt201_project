// Claire Smith and Matt Beaulieu
// Project Milestone 3 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    srand(time(NULL)); 

    // Tests for getPaintHue (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintHue:\n");
	printf("------------------------------------------------------------\n");

    char paintFilename[] = "../data/paints.dat";
	paint_t* paintArray1 = NULL;
    paint_t* colourarr;
	int pntN;
    int pntN2; //Necessary????????????????????????????????????????

    paintArray1 = loadPaintData(paintFilename, paintArray1, &pntN);
    if(paintArray1 == NULL){
        printf("Error: Function [paintArray1] failed.\n");
        exit(EXIT_FAILURE);
    }

    pntN2 = pntN;

    colourarr = getPaintHue(paintArray1, &pntN, RED);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s, %s, %s, ", colourarr[0].ciName, colourarr[0].marketingName, colourarr[0].manufacturer);
    printf("Number of colors in colorarr: %d\n", pntN);



    free(colourarr);
    colourarr = NULL;
 
    free(paintArray1);
	paintArray1 = NULL;




    // Tests for getPalette (CLAIRE)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPalette:\n");
	printf("------------------------------------------------------------\n");




    // deallocate memory for paintArray


    exit(EXIT_SUCCESS);
}