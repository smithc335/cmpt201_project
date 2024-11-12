// Claire Smith and Matt Beaulieu
// Project Milestone 1 Tests for Functions

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pigment.h"

int main(void){

	// Tests for loadPigmentData
	char filename[] = "pigments.dat";
    FILE *fp = NULL;
    char strcatch[200];
    int numlines = 0;


    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error: Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    //Getting rid of first 9 lines of file.
    for(int i = 0; i < 9; i++){
        if (fgets(strcatch, 200, fp) == NULL){
            printf("Error: Reached end of file.\n");
            exit(EXIT_FAILURE);
        }
    }

    //Count number of lines in file.
    while (fgets(strcatch, 200, fp)){
        numlines++;
    }

   struct Pigment *pArray = malloc((numlines) * sizeof(struct Pigment));


    if ((loadPigmentData(filename, pArray, &numlines)) == 1){
        printf("Error: Function did not work.\n");
        exit(EXIT_FAILURE);
    }



	// printf("ciName = %s, pigmentname = %s, value = %d, chroma = %d, abvalue = [%d, %d], hueAngle = %d, huePurity = %.3f,
	// 	 abHp = [%.3f, %.3f]\n", pArray[169].ciName, pArray[169].pigmentName, pArray[169].value, pArray[169].chroma,
	// 	 pArray[169].abValue[0], pArray[169].abValue[1], pArray[169].hueAngle, pArray[169].huePurity, pArray[169].abHp[0], 
	// 	 pArray[169].abHp[1]);


    free(pArray);
    pArray = NULL;
    fclose(fp);

	// Tests for loadPaintData
	printf("------------------------------------------------------------\n");
	printf("Tests for loadPaintData:\n");
	printf("------------------------------------------------------------\n");

	srand(time(NULL));

	char paint_filename[] = "paints.dat"; 
	paint_t* paint_array;
	int paint_n;
	int paint_err = 0;
	int r;

	paint_array = malloc(sizeof(paint_t));

	paint_err = loadPaintData(paint_filename, &paint_array, &paint_n); // PASSING IN DOUBLE POINTER
	r = rand() % (paint_n + 1);

	if(paint_err==1){
		printf("Function was unsuccessful.\n");
	}
	else{
		printf("Number of data entries in %s: %i\n", paint_filename, paint_n);
		printf("\nSample of loaded data from lines %i to %i:\n", r+13, r+22);
		// printf("Rand int = %i\n", r);
		printf("------------------------------------------------------------\n");

		// works when we return the pointer from the function or pass in double pointer

		// printf("%s, %s, %s, ", paint_array[0].ciName, paint_array[0].marketingName, paint_array[0].manufacturer);
		// printf("%i, %i, %i, ", paint_array[0].transparency, paint_array[0].staining, paint_array[0].valueRange);
		// printf("%i, %i, %i, ", paint_array[0].granulating, paint_array[0].blossom, paint_array[0].diffusion);
		// printf("%i, %i, %i\n", paint_array[0].hueAngle, paint_array[0].hueShift, paint_array[0].lightfast);
		
		for(int i=0; i<10; i++){
			printf("Line %i: ", r+i+13);
			printf("%s, %s, %s, ", paint_array[r+i].ciName, paint_array[r+i].marketingName, paint_array[r+i].manufacturer);
			printf("%i, %i, %i, ", paint_array[r+i].transparency, paint_array[r+i].staining, paint_array[r+i].valueRange);
			printf("%i, %i, %i, ", paint_array[r+i].granulating, paint_array[r+i].blossom, paint_array[r+i].diffusion);
			printf("%i, %i, %i\n", paint_array[r+i].hueAngle, paint_array[r+i].hueShift, paint_array[r+i].lightfast);
		}

		printf("------------------------------------------------------------\n");

	// deallocate memory
	free(paint_array);
	paint_array = NULL;
	}

	return 0;
}