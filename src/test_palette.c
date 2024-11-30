// Claire Smith and Matt Beaulieu
// Project Milestone 3 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    // srand(time(NULL)); 

    char paintFilename[] = "../data/paints.dat";
	paint_t* paintArray = NULL;
	int paintN;

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);

    // Tests for getPalette (CLAIRE)
    printf("------------------------------------------------------------\n");
	printf("Tests for getPalette:\n");
	printf("------------------------------------------------------------\n");

    paint_t* paletteArray = NULL;
    char type[] = "full:yellow";
    char property[] = "transparency:0";
    int paletteN = paintN;

    printf("BEFORE: palette: %i paint: %i\n", paletteN, paintN);

    // PASS IN A TEMP POINTER FOR n WHICH CONTAINS DUPLICATE OF PAINTARRAY SIZE
        // will be overwritten by size of new array after function is over

    paletteArray = getPalette(paintArray, &paletteN, type, property);

    printf("AFTER: palette: %i paint: %i\n", paletteN, paintN);

    for(int i=0; i<paletteN; i++){
        printf("%s, %s, %s, ", paletteArray[i].ciName, paletteArray[i].marketingName, paletteArray[i].manufacturer);
        printf("%i, %i, %i, ", paletteArray[i].transparency, paletteArray[i].staining, paletteArray[i].valueRange);
        printf("%i, %i, %i, ", paletteArray[i].granulating, paletteArray[i].blossom, paletteArray[i].diffusion);
        printf("%i, %i, %i\n", paletteArray[i].hueAngle, paletteArray[i].hueShift, paletteArray[i].lightfast);
    }

    // deallocate memory for paletteArray
    free(paletteArray);
    paletteArray = NULL;

    // deallocate memory for paintArray
    free(paintArray);
    paintArray = NULL;

    exit(EXIT_SUCCESS);
}