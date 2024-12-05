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
                getTypeInput(paletteTypeCopy, paletteType);

                err = isValidTypeInput(paletteType);
                if(err==1){
                    strcpy(paletteType, paletteTypeCopy);
                    printf("Invalid entry for palette type. Please see Help Page for more information.\n");
                }
                break;

            case(2):
                getPropertyInput(palettePropertyCopy, paletteProperty);

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
                else{
                    err = printPalette(paletteArray, paintArray, &paletteN, paintN, paletteType, paletteProperty);
                    if(err==1){
                        printf("Error: printPalette failed because printArray was unsuccessful.\n");
                    }
                }
                break;

            case(4):
                printHelpPage();
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
    // paletteArray deallocated and freed in getPalette

    exit(EXIT_SUCCESS);
}