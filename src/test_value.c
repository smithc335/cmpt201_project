// Claire Smith and Matt Beaulieu
// Project Milestone 2 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include "pigment.h"

int main(void){

    // Tests for printPigment (MATT)

    // Tests for printPaint (CLAIRE)

    // Tests for getPaintRange (CLAIRE)

    // Tests for getPaintValue (MATT)

 

    paint_t* paintPoint;
    char name[] = "cerulean blue"
    int* numResult = 0;


    paintPoint = getPaintValue(paintArray, &paintN, name, MARKETINGNAME, &numResult);

    printf("The number of elements that have the name %s is %d\n", name, numResult);

    for (int i = 0; i < numResult ; i++){
        printf("%s, %s, %s, ", paintPoint[i].ciName, paintPoint[i].marketingName, paintPoint[i].manufacturer);
	    printf("%i, %i, %i, ", paintPoint[i].transparency, paintPoint[i].staining, paintPoint[i].valueRange);
	    printf("%i, %i, %i, ", paintPoint[i].granulating, paintPoint[i].blossom, paintPoint[i].diffusion);
	    printf("%i, %i, %i\n", paintPoint[i].hueAngle, paintPoint[i].hueShift, paintPoint[i].lightfast);

    }




    exit(EXIT_SUCCESS);
}