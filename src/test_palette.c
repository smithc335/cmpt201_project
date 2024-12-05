// Claire Smith and Matt Beaulieu
// Project Milestone 3 Tests for getPalette Function

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    char paintFilename[] = "../data/paints.dat";
	paint_t* paintArray = NULL;
	int paintN;
    paint_t* paletteArray = NULL;
    char type1[] = "triad:red_orange";
    char type2[] = "complimentary:blue_green";
    char type3[] = "split_complimentary:violet";
    char type4[] = "full:blue";
    char type5[] = "triad:red";
    char property1[] = "transparency:2";
    char property2[] = "staining:1";
    char property3[] = "blossom:4";
    char property4[] = "transparency:0";
    char* property5 = NULL;
    int paletteN;
    int err;

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);
    paletteN = paintN; // will be overwritten by size of paletteArray after function is over

    // Tests for getPalette
    printf("------------------------------------------------------------\n");
	printf("Tests for getPalette:\n");
	printf("------------------------------------------------------------\n");
    
    paletteArray = getPalette(paintArray, &paletteN, type1, property1);
    printf("\nPalette for %s with %s\n", type1, property1);
    printf("---> Contains %i paints\n", paletteN);
    printf("------------------------------------------------------------\n");
    err = printArray(paletteArray, paletteN);
    if(err==1){
        printf("Error: printArray function failed.\n");
        exit(EXIT_FAILURE);
    }

    // setup for next test
    free(paletteArray);
    paletteArray = NULL;
    paletteN = paintN;

    paletteArray = getPalette(paintArray, &paletteN, type2, property2);
    printf("------------------------------------------------------------\n");
    printf("\nPalette for %s with %s\n", type2, property2);
    printf("---> Contains %i paints\n", paletteN);
    printf("------------------------------------------------------------\n");
    err = printArray(paletteArray, paletteN);
    if(err==1){
        printf("Error: printArray function failed.\n");
        exit(EXIT_FAILURE);
    }

    // setup for next test
    free(paletteArray);
    paletteArray = NULL;
    paletteN = paintN;

    paletteArray = getPalette(paintArray, &paletteN, type3, property3);
    printf("------------------------------------------------------------\n");
    printf("\nPalette for %s with %s\n", type3, property3);
    printf("---> Contains %i paints\n", paletteN);
    printf("------------------------------------------------------------\n");
    err = printArray(paletteArray, paletteN);
    if(err==1){
        printf("Error: printArray function failed.\n");
        exit(EXIT_FAILURE);
    }

    // setup for next test
    free(paletteArray);
    paletteArray = NULL;
    paletteN = paintN;

    paletteArray = getPalette(paintArray, &paletteN, type4, property4);
    printf("------------------------------------------------------------\n");
    printf("\nPalette for %s with %s\n", type4, property4);
    printf("---> Contains %i paints\n", paletteN);
    printf("------------------------------------------------------------\n");
    err = printArray(paletteArray, paletteN);
    if(err==1){
        printf("Error: printArray function failed.\n");
        exit(EXIT_FAILURE);
    }

    // setup for next test
    free(paletteArray);
    paletteArray = NULL;
    paletteN = paintN;

    paletteArray = getPalette(paintArray, &paletteN, type5, property5);
    printf("------------------------------------------------------------\n");
    printf("\nPalette for %s with no property specified\n", type5);
    printf("---> Contains %i paints\n", paletteN);
    printf("------------------------------------------------------------\n");
    err = printArray(paletteArray, paletteN);
    if(err==1){
        printf("Error: printArray function failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("------------------------------------------------------------\n");

    // deallocate memory for paletteArray
    free(paletteArray);
    paletteArray = NULL;

    // deallocate memory for paintArray
    free(paintArray);
    paintArray = NULL;

    exit(EXIT_SUCCESS);
}