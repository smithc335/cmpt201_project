// Claire Smith and Matt Beaulieu
// Project Milestone 1 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pigment.h"

int main(void){

	// Tests for loadPigmentData

	// Tests for loadPaintData
	printf("------------------------------------------------------------\n");
	printf("Tests for loadPaintData:\n");
	printf("------------------------------------------------------------\n");

	srand(time(NULL));

	char paint_filename[] = "paints.dat";
	paint_t* paint_array;
	int paint_n;
	int paint_err;
	int r;

	paint_err = loadPaintData(paint_filename, paint_array, &paint_n);
	r = rand() % paint_n;

	if(paint_err==1){
		printf("Function was unsuccessful.\n");
	}
	else{
		printf("Number of entries in %s: %i\n", paint_filename, paint_n);
		printf("\nSample data loaded into array:\n");
		printf("Rand int = %i\n", r);

		printf("%s, %s, %s, ", paint_array[r].ciName, paint_array[r].marketingName, paint_array[r].manufacturer);
		printf("%i, %i, %i, ", paint_array[r].transparency, paint_array[r].staining, paint_array[r].valueRange);
		printf("%i, %i, %i, ", paint_array[r].granulating, paint_array[r].blossom, paint_array[r].diffusion);
		printf("%i, %i, %i\n'", paint_array[r].hueAngle, paint_array[r].hueShift, paint_array[r].lightfast);

		/*
		for(int i=0; i<10; i++){
			printf("%s, %s, %s, ", paint_array[r+i].ciName, paint_array[r+i].marketingName, paint_array[r+i].manufacturer);
			printf("%i, %i, %i, ", paint_array[r+i].transparency, paint_array[r+i].staining, paint_array[r+i].valueRange);
			printf("%i, %i, %i, ", paint_array[r+i].granulating, paint_array[r+i].blossom, paint_array[r+i].diffusion);
			printf("%i, %i, %i\n'", paint_array[r+i].hueAngle, paint_array[r+i].hueShift, paint_array[r+i].lightfast);
		}
		*/
	}

	return 0;
}
