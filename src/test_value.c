// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    // Tests for printPigment (MATT)

    // Tests for printPaint (CLAIRE)

    char paintFilename[] = "../data/paints.dat"; 
	paint_t* paintArray = NULL;
	int paintN;

    paintArray = loadPaintData(paintFilename, paintArray, &paintN);

    // Tests for getPaintRange (CLAIRE)

    // deallocate memory
    // free(array);
    // array = NULL;

    // Tests for getPaintValue (MATT)

    return (0);
}