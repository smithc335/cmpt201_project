// Claire Smith and Matt Beaulieu
// Project Milestone 3 Main Paint Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pigment.h"

int main(void){

    char pigmentFilename[] = "../data/pigments.dat"; 
    pigment_t* pigmentArray = NULL;
    int pigmentN = 10;
    char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
    int paintN;
    paint_t* paletteArray = NULL;
    int paletteN;
    int err;
    int menuChoice;
    char paletteType[50] = "none";
    char paletteProperty[50] = "none";
    char paletteTypeCopy[50];
    char palettePropertyCopy[50];

    // load pigment data
    pigmentArray = loadPigmentData(pigmentFilename, pigmentArray, &pigmentN);
    if(pigmentArray == NULL){
        printf("Error: Function [loadPigmentData] was unsuccessful.\n");
        exit(EXIT_FAILURE);
    }

    // load paint data
	paintArray = loadPaintData(paintFilename, paintArray, &paintN);
	if(paintArray == NULL){
		printf("Error: Function [loadPaintData] was unsuccessful.\n");
		exit(EXIT_FAILURE);
    }

    // paletteN = paintN; // will be overwritten by size of paletteArray after function is over

    printf("********************************************************************************\n");
    printf("Welcome to Paints Program\n");
    printf("********************************************************************************\n");
    printf("0) Quit\n1) Enter Palette Type\n\t-> Currently set at: %s\n", paletteType);
    printf("2) Enter Palette Property\n\t-> Currently set at: %s\n3) Print Palette Choice\n", paletteProperty);
    printf("4) Help Page\n\t-> View valid palette types and properties.\n");
    printf("\nChoose one of the above: ");
    scanf("%d", &menuChoice);
    printf("********************************************************************************\n");

    while(menuChoice != 0){
        switch(menuChoice){
            case(1):
                strcpy(paletteTypeCopy, paletteType); // for reverting back if entry is invalid
                printf("\nEnter Palette Type: ");
                scanf("%s", paletteType);

                err = isValidTypeInput(paletteType);
                if(err==1){
                    strcpy(paletteType, paletteTypeCopy);
                    printf("Invalid entry for palette type. Please see Help Page for more information.\n");
                }
                break;

            case(2):
                strcpy(palettePropertyCopy, paletteProperty); // for reverting back if entry is invalid
                printf("\nEnter Palette Property: ");
                scanf("%s", paletteProperty);

                err = isValidPropertyInput(paletteProperty);
                if(err==1){
                    strcpy(paletteProperty, palettePropertyCopy);
                    printf("Invalid entry for palette property. Please see Help Page for more information.\n");
                }
                break;

            case(3):
                if((strcmp(paletteType, "none")==0)){
                    printf("\nPlease enter a palette type.\n");
                    break;
                }
                else if(strcmp(paletteProperty, "none")==0){
                    paletteN = paintN; // reset before calling getPalette function
                    paletteArray = getPalette(paintArray, &paletteN, paletteType, NULL);
                    printf("\nPalette for %s with no property specified\n", paletteType);
                    printf("\t-> Contains %i paints\n", paletteN);
                    printf("--------------------------------------------------------------------------------\n");

                    err = printArray(paletteArray, paletteN);
                    if(err==1){
                        printf("Error: Function [printArray] was unsuccessful.\n");
                        exit(EXIT_FAILURE);
                    }

                    free(paletteArray);
                    paletteArray = NULL;
                }
                else{
                    paletteN = paintN; // reset before calling getPalette function
                    paletteArray = getPalette(paintArray, &paletteN, paletteType, paletteProperty);
                    printf("\nPalette for %s with %s\n", paletteType, paletteProperty);
                    printf("\t-> Contains %i paints\n", paletteN);
                    printf("--------------------------------------------------------------------------------\n");

                    err = printArray(paletteArray, paletteN);
                    if(err==1){
                        printf("Error: Function [printArray] was unsuccessful.\n");
                        exit(EXIT_FAILURE);
                    }

                    free(paletteArray);
                    paletteArray = NULL;
                }
                break;

            case(4):
                printf("\nPAINT PROGRAM HELP PAGE\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("Please format palette type as [type]:[color] and\nproperty as [property]:[value].\n\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("Valid Palette Type Entries\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("Choices for [type]:\n");
                printf("\t-> full\n");
                printf("\t-> triad\n");
                printf("\t-> complimentary\n");
                printf("\t-> split_complimentary\n");

                printf("\nChoices for [color]:\n");
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

                printf("\n--------------------------------------------------------------------------------\n");
                printf("Valid Palette Property Entries:\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("Property can be entered as \"none\" to not specify any properties.\n\n");

                printf("Choices for [property]:\n");
                printf("\t-> transparency\n");
                printf("\t-> staining\n");
                printf("\t-> blossom\n");

                printf("\n[value] can be any integer in the range [0-4] inclusive.\n");
                break;
                
            default:
                printf("\nInvalid menu option. Enter one of the options provided.\n");
                break;
        }

        printf("\n********************************************************************************\n");
        printf("0) Quit\n1) Enter Palette Type\n\t-> Currently set at: %s\n", paletteType);
        printf("2) Enter Palette Property\n\t-> Currently set at: %s\n3) Print Palette Choice\n", paletteProperty);
        printf("4) Help Page\n\t-> View valid palette types and properties.\n");
        printf("\nChoose one of the above: ");
        scanf("%d", &menuChoice);
        printf("********************************************************************************\n");
    }

    // deallocate memory and free pointers
    free(pigmentArray);
    pigmentArray = NULL;
    free(paintArray);
    paintArray = NULL;
    // free(paletteArray);
    // paletteArray = NULL;

    exit(EXIT_SUCCESS);
}