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
    int pntN2; //Necessary????????????????????????????????????????

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

    // for(int i = 0; i < pntN; i++){
    //     printf("%s, %s, %s, %d\n ", colourarr[i].ciName, colourarr[i].marketingName, colourarr[i].manufacturer, colourarr[i].hueAngle);
    // }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;

    //////////////////////////////////////////////////////////////////
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, YELLOW_ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, YELLOW);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, YELLOW_GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, BLUE_GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, BLUE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);


    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, BLUE_VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, RED_VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

    free(colourarr);
    colourarr = NULL;
    pntN = pntN2;

    colourarr = getPaintHue(paintArray1, &pntN, RED);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Number of colors in colorarr: %d\n", pntN);

///////////////////////////////////////////////////////////////////////////////


    free(colourarr);
    colourarr = NULL;
 
    // deallocate memory for paintArray
    free(paintArray1);
	paintArray1 = NULL;

    exit(EXIT_SUCCESS);
}
