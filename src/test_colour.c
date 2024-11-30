// Claire Smith and Matt Beaulieu
// Project Milestone 3 Tests for getPaintHue Function

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

    printf("Total Paints = %d\n", pntN);
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
 
    printf("Unknown Paints = %d\n", unknownp);
    printf("------------------------------------------------------------\n");

    //Storing the number of paints in separate variable to bring it back to 
    //baseline later.
    pntN2 = pntN;



    //TEST RED-ORANGE
    colourarr = getPaintHue(paintArray1, &pntN, RED_ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, RED_ORANGE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST ORANGE
    colourarr = getPaintHue(paintArray1, &pntN, ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, ORANGE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST YELLOW-ORANGE
    colourarr = getPaintHue(paintArray1, &pntN, YELLOW_ORANGE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, YELLOW_ORANGE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST YELLOW
    colourarr = getPaintHue(paintArray1, &pntN, YELLOW);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, YELLOW)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST YELLOW-GREEN
    colourarr = getPaintHue(paintArray1, &pntN, YELLOW_GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, YELLOW_GREEN)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST GREEN
    colourarr = getPaintHue(paintArray1, &pntN, GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, GREEN)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


      //TEST BLUE-GREEN
    colourarr = getPaintHue(paintArray1, &pntN, BLUE_GREEN);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, BLUE_GREEN)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST BLUE
    colourarr = getPaintHue(paintArray1, &pntN, BLUE);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, BLUE)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST BLUE-VIOLET
    colourarr = getPaintHue(paintArray1, &pntN, BLUE_VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, BLUE_VIOLET)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST VIOLET
    colourarr = getPaintHue(paintArray1, &pntN, VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, VIOLET)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST RED-VIOLET
    colourarr = getPaintHue(paintArray1, &pntN, RED_VIOLET);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, RED_VIOLET)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };


    //TEST RED
    colourarr = getPaintHue(paintArray1, &pntN, RED);
    if(colourarr == NULL){
        printf("Error: Function [colorarr] failed.\n");
        exit(EXIT_FAILURE);
    }

    if ((printHue(colourarr, &pntN, pntN2, RED)) == 1){
        printf("Error: Function [printHue] failed.\n");
        exit(EXIT_FAILURE);
    };
    
    // deallocate memory for colourarr 


    // deallocate memory for paintArray
    free(paintArray1);
	paintArray1 = NULL;

    exit(EXIT_SUCCESS);
}
