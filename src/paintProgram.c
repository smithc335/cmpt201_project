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


        printf("\nChoose one of the following:\n");
        printf("0) Quit\n1) Enter a Palette type\n2) Enter a Palette Property\n3) Print Palette Choice\n4) Help\n");
        menuN = atoi(getc(stdin));


        break;
    }


    exit(EXIT_SUCCESS);
}