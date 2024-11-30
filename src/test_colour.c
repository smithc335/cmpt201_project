// Claire Smith and Matt Beaulieu
// Project Milestone 3 Test for Function getPaintHue

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    // Tests for getPaintHue (MATT)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPaintHue:\n");
	printf("------------------------------------------------------------\n");

    char paintFilename[] = "../data/paints.dat";
	paint_t* paintArray1 = NULL;
    paint_t* colourarr;
	int pntN;
    int pntN2; 

    paintArray1 = loadPaintData(paintFilename, paintArray1, &pntN);
    if(paintArray1 == NULL){
        printf("Error: Function [paintArray1] failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Total paints = %d\n", pntN);
    int hueMax = 0;
    int unknownp = 0;
    for (int i = 0; i<pntN; i++){
        if( (paintArray1[i].hueAngle) == 999 ){
            unknownp++;
            continue;
        }
        if ( (paintArray1[i].hueAngle) > hueMax){
            
            hueMax = paintArray1[i].hueAngle;
        }
    }
    printf("hueMax = %d\n", hueMax);
    printf("unknownp = %d\n", unknownp);

    pntN2 = pntN;

    colourarr = getPaintHue(paintArray1, &pntN, RED_ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, RED_ORANGE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    colourarr = getPaintHue(paintArray1, &pntN, ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, ORANGE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };
    
    // deallocate memory for colourarr
    free(colourarr);
	colourarr = NULL;

    // deallocate memory for paintArray
    free(paintArray1);
	paintArray1 = NULL;

    exit(EXIT_SUCCESS);
}
