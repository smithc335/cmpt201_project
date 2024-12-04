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
    printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
    

    menuN = atoi(getc(stdin));

    while(menuN != 0){

    
        switch(menuN){
            case(1):
                scanf("%s", &paletteT);
                break;

            case(2):
                scanf("%s", &paletteP);
                break;
            case(3):
                printf("Printing Palette Choice");
                break;
            case(4);
                printf("Valid Palette Types: ");
                printf("Valid Palette Properties: ");
                break;
            default:
                printf("Invalid menu option\n");
                break;

        }


        printf("\nChoose one of the following:\n");
        printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
        menuN = atoi(getc(stdin));


        break;
    }


    exit(EXIT_SUCCESS);
}