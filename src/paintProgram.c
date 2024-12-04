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
    paint_t* paletteArray = NULL;
	int paintN;
    int paletteN;
    int err;

    int menuN;
    char paletteT[20] = "None";
    char paletteP[20] = "None";




    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &pigmentN);
    if(pigmentArray == NULL){
        printf("Error: Function [loadPigmentData] was unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    //Load Paint Data
	paintArray = loadPaintData(paintFilename, paintArray, &paintN);
	if(paintArray == NULL){
		printf("Error: Function [loadPaintData] was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    paletteN = paintN; // will be overwritten by size of paletteArray after function is over


    printf("Welcome to Paints Program\n");
    printf("\nChoose one of the following:\n");
    printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
    

    menuN = (getc(stdin) - '0');
    printf("menuN = %d", menuN);

    while(menuN != 0){

    
        switch(menuN){
            case(1):
                scanf("%s", paletteT);
                break;

            case(2):
                scanf("%s", paletteP);
                break;
            case(3):
                printf("Printing Palette Choice\n");
                if  ( (strcmp(paletteT, "None") == 0) || (strcmp(paletteP, "None") == 0) ) {
                    printf("Please enter a palette type and a palette property.\n");
                    break;
                }
                else{
                    paletteArray = getPalette(paintArray, &paletteN, paletteT, paletteP);
                    printf("\nPalette for %s: selected colour with %s:2\n", paletteT, paletteP);
                    printf("---> Contains %i paints\n", paletteN);
                    printf("------------------------------------------------------------\n");
                    err = printArray(paletteArray, paletteN);
                    if(err==1){
                        printf("Error: Function [printArray] was unsuccessful.\n");
                        exit(EXIT_FAILURE);

                }

    }
                break;

            case(4):
                printf("Valid Palette Types:\n");
                printf("\t-> full\n");
                printf("\t-> triad\n");
                printf("\t-> complimentary\n");
                printf("\t-> split_complimentary\n");

                printf("Valid Palette Properties:\n");
                printf("\t-> transparency\n");
                printf("\t-> staining\n");
                printf("\t-> blossom\n");
                break;
            default:
                printf("Invalid menu option\n");
                break;

        }


        printf("\nChoose one of the following:\n");
        printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
        menuN = (getc(stdin) - '0');


        break;
    }


    exit(EXIT_SUCCESS);
}