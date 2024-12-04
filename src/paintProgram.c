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
    char paletteT[50] = "None";
    char paletteP[50] = "None";




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
    
    printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
    printf("\nChoose one of the following: ");

    menuN = (getc(stdin) - '0');

    while(menuN != 0){
        switch(menuN){
            case(1):
                printf("Enter Palette Type: ");
                scanf("%s", paletteT);
                // make helper function to check palette type name and message if wrong
                break;

            case(2):
                printf("Enter Property Type: ");
                scanf("%s", paletteP);
                // make helper function to check property type name and message if wrong
                break;

            case(3):
                printf("Printing Palette Choice\n");
                if  ( (strcmp(paletteT, "None") == 0) ) {
                    printf("Please enter a palette type.\n");
                    break;
                }
                else if(strcmp(paletteP, "None") == 0){
                    paletteArray = getPalette(paintArray, &paletteN, paletteT, NULL);
                    printf("\nPalette for %s with no property specified\n", paletteT);
                    printf("---> Contains %i paints\n", paletteN);
                    printf("------------------------------------------------------------\n");
                    err = printArray(paletteArray, paletteN);
                    if(err==1){
                        printf("Error: Function [printArray] was unsuccessful.\n");
                        exit(EXIT_FAILURE);
                }
                else{
                    paletteArray = getPalette(paintArray, &paletteN, paletteT, paletteP);
                    printf("\nPalette for %s with %s\n", paletteT, paletteP);
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
                printf("\nPlease format palette type as [type]:[color] and\nproperty as [property]:[number].\n");
                printf("----------------------------------------------------------------------\n");
                printf("Valid Palette Type Entries\n");
                printf("----------------------------------------------------------------------\n");
                printf("Choices for Palette Type:\n");
                printf("\t-> full\n");
                printf("\t-> triad\n");
                printf("\t-> complimentary\n");
                printf("\t-> split_complimentary\n");

                printf("\nChoices for Starting Palette Color:\n");
                printf("\t-> red\n");
                printf("\t-> red_orange\n");
                printf("\t-> orange\n");
                printf("\t-> yellow_orange\n");
                printf("\t-> yellow\n");
                printf("\t-> yellow_green\n");
                printf("\t-> green\n");
                printf("\t-> blue_green\n");
                printf("\t-> blue\n");
                printf("\t-> blue_violet\n");
                printf("\t-> violet\n");
                printf("\t-> red_violet\n");

                printf("\n----------------------------------------------------------------------\n");
                printf("Valid Palette Property Entries:\n");
                printf("----------------------------------------------------------------------\n");
                printf("Choices for Property Type:\n");
                printf("\t-> transparency\n");
                printf("\t-> staining\n");
                printf("\t-> blossom\n");

                printf("\nProperty Number can be any integer in the range [0-4] inclusive.\n\n");
                break;
                
            default:
                printf("Invalid menu option\n");
                break;

        }


        
        printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
        printf("\nChoose one of the following: ");
        menuN = (getc(stdin) - '0');

    }


    exit(EXIT_SUCCESS);
}