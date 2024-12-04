//Matt and Claire
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pigment.h"

int main(void){

	//Load Pigment Data
    char pigmentFilename[] = "../data/pigments.dat"; 
    pigment_t* pigmentArray = NULL;
    int pigmentN = 10;
	
    char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;

    int menuN;
    char paletteT[20] = "None";
    char paletteP[20] = "None";




    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &pigmentN);
    if(pigmentArray == NULL){
        printf("Function [loadPigmentData] was unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    //Load Paint Data
	paintArray = loadPaintData(paintFilename, paintArray, &paintN);
	if(paintArray == NULL){
		printf("Function [loadPaintData] was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }


    printf("Welcome to Paints Program\n");
    printf("\nChoose one of the following:\n");




    // while(menuN != 0){

    //     break;
    // }


    exit(EXIT_SUCCESS);
}