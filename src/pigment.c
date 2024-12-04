// Claire Smith and Matt Beaulieu
// Project Function Implementations

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pigment.h"

/*******************************************************************************
* MILESTONE 1 FUNCTIONS
*******************************************************************************/

pigment_t* loadPigmentData(char* filename, pigment_t *pArray, int* n){

    char* token = NULL;
    char strcatch[200];
    FILE* fp = fopen(filename, "r");
    int i = 0;

    //Testing if file opened 
    if (fp == NULL){
        printf("Error: Failed to open file.\n");
        return (NULL);
    }

    //Getting rid of first 9 lines of file.
    for(int i = 0; i < 9; i++){
        //Check if finds end of file.
        if (fgets(strcatch, 200, fp) == NULL){
            printf("Error: Reached end of file.\n");
            return (NULL);
        }
    }

    //Allocate space for array
    pArray = malloc((*n) * sizeof(pigment_t));
    if (pArray == NULL){
        return (NULL);
    }

    //Looping through file
    while(fgets(strcatch, 200, fp) != NULL){

        //Checking if need to realloc.
        if(i == *n){
            *n = (*n) * 2; 
            //Checking if realloc succeeds with a temp pointer.
            pigment_t *tempArray = realloc(pArray, (*n) * sizeof(pigment_t));
            if(tempArray == NULL){
                printf("Error: Realloc Failed.\n");
                return (NULL);
            }

            pArray = tempArray;
            tempArray = NULL;
        }

        //ciNAME
        if((token = strtok(strcatch, ",")) == NULL){
            strcpy(pArray[i].ciName, "EMPTY");
        }
        else{
            strcpy(pArray[i].ciName, token);
        }
        
        //pigmentName
        if((token = strtok(NULL, ",")) == NULL){
            strcpy(pArray[i].pigmentName, "EMPTY");
        }
        else{
            strcpy(pArray[i].pigmentName, token);
        }

        //value
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].value = 9999;
        }
        else{
            pArray[i].value = atoi(token);
        }

        //chroma
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].chroma = 9999;
        }
        else{
            pArray[i].chroma = atoi(token);
        }

        //abvalue[0]
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].abValue[0]= 9999;
        }
        else{
            pArray[i].abValue[0] = atoi(token);
        }

        //abvalue[1]
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].abValue[1] = 9999;
        }
        else{
            pArray[i].abValue[1] = atoi(token);
        }

        //hueAngle
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].hueAngle = 9999;
        }
        else{
            pArray[i].hueAngle = atoi(token);
        }

        //huePurity
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].huePurity = 9999;
        }
        else{
            pArray[i].huePurity = atof(token);
        }

        //abHp[1]
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].abHp[0]= 9999;
        }
        else{
            pArray[i].abHp[0] = atof(token);
        }

        //abHp[1]
        if((token = strtok(NULL, ",")) == NULL){
            pArray[i].abHp[1]= 9999;
        }
        else{
            pArray[i].abHp[1] = atof(token);
        }

        i++;
    }

    *n = i;
    fclose(fp);
    return (pArray);
}


paint_t* loadPaintData(char* filename, paint_t* pArray, int* n){

	FILE* fp = fopen(filename, "r");
	if(fp==NULL){
        printf("Error: Failed to open file.\n");
		return (pArray); // returning array (array=NULL) for function failure
	}

	char line[140];
	char* getsRetVal;
	int capacity = 10;
	char* token;

	*n = 0; // make sure entries starts at zero

	// read unneeded lines
	for(int i=0; i<12; i++){
		fgets(line, 140, fp);
	}

	// allocate memory for 10 entries first
	pArray = malloc(capacity * sizeof(paint_t));

	// populate array
	getsRetVal = fgets(line, 95, fp); // get first entry line from file

	while(getsRetVal!=NULL){
		// reallocate if n > capacity of pArray
		if(*n>=capacity){
			capacity *= 2;
			pArray = realloc(pArray, (capacity * sizeof(paint_t)));
		}

		// tokenize line and populate
        // currently catching missing values as "—"
		token = strtok(line, ","); // ciName
		if(strcmp(token, "—")==0){
            strcpy(pArray[*n].ciName, "EMPTY");
        }
        else{
			strcpy(pArray[*n].ciName, token);
		}

		token = strtok(NULL, ","); // marketingName
		if(strcmp(token, "—")==0){
            strcpy(pArray[*n].marketingName, "EMPTY");
        }
        else{
			strcpy(pArray[*n].marketingName, token);
		}

		token = strtok(NULL, ","); // manufacturer
        if(strcmp(token, "—")==0){
            strcpy(pArray[*n].manufacturer, "EMPTY");
        }
        else{
			strcpy(pArray[*n].manufacturer, token);
		}

		token = strtok(NULL, ","); // code (not listed as struct member to be loaded)

		token = strtok(NULL, ","); // transparency
        if(strcmp(token, "—")==0){
            pArray[*n].transparency = 999;
        }
        else{
			pArray[*n].transparency = atoi(token);
		}

		token = strtok(NULL, ","); // staining
        if(strcmp(token, "—")==0){
            pArray[*n].staining = 999;
        }
        else{
			pArray[*n].staining = atoi(token);
		}

		token = strtok(NULL, ","); // valueRange
        if(strcmp(token, "—")==0){
            pArray[*n].valueRange = 999;
        }
        else{
			pArray[*n].valueRange = atoi(token);
		}

		token = strtok(NULL, ","); // granulating
		if(strcmp(token, "—")==0){
            pArray[*n].granulating = 999;
        }
        else{
			pArray[*n].granulating = atoi(token);
		}

		token = strtok(NULL, ","); // blossom
        if(strcmp(token, "—")==0){
            pArray[*n].blossom = 999;
        }
        else{
			pArray[*n].blossom = atoi(token);
		}

		token = strtok(NULL, ","); // diffusion
        if(strcmp(token, "—")==0){
            pArray[*n].diffusion = 999;
        }
        else{
			pArray[*n].diffusion = atoi(token);
		}

		token = strtok(NULL, ","); // hueAngle
        if(strcmp(token, "—")==0){
            pArray[*n].hueAngle = 999;
        }
        else{
			pArray[*n].hueAngle = atoi(token);
		}

		token = strtok(NULL, ","); // hueShift
        if(strcmp(token, "—")==0){
            pArray[*n].hueShift = 999;
        }
        else{
			pArray[*n].hueShift = atoi(token);
		}

		token = strtok(NULL, "/"); // lightfast 1998
		token = strtok(NULL, "\0"); // lightfast 2004
        if(token==NULL || token[0] == '.'){
            pArray[*n].lightfast = 999;
        }
        else{
			pArray[*n].lightfast = atoi(token);
		}

		*n += 1; // add entry to number of entries
		getsRetVal = fgets(line, 95, fp); // get next entry line from file
	}

	fclose(fp);

	return (pArray); // function was successful
}

/*******************************************************************************
* MILESTONE 2 FUNCTIONS
*******************************************************************************/

int printPigment(pigment_t* pp, int i, int n){

    // Checking if array was created previously.
    if (pp == NULL){
        printf("Error: Passed in empty array.\n");
        return (1);
    }

    // Function should not accept indices less than -1 or greater or equal to the number of indices in the array.
    if ( (i < (-1)) || (i >= n) ) {
        printf("Error: Index out of range.\n");
        return (1);
    }

    if (i == -1){
        for (int j = 0; j < n; j++){

            printf("--------------\n");
            printf("ciName       : %s\n", pp[j].ciName);
            printf("pigmentName  : %s\n", pp[j].pigmentName);
            printf("value        : %d\n", pp[j].value);
            printf("chroma       : %d\n", pp[j].chroma);
            printf("(a,b)        : (%d,%d)\n", pp[j].abValue[0], pp[j].abValue[1]);
            printf("hue [degrees]: %d\n", pp[j].hueAngle);
            printf("huePurity    : %.2f\n", pp[j].huePurity);
            printf("(ahp,ahp)    : (%.2f,%.2f)\n", pp[j].abHp[0], pp[j].abHp[1]);
        }
    }
    else{ 
        printf("--------------\n");
        printf("ciName       : %s\n", pp[i].ciName);
        printf("pigmentName  : %s\n", pp[i].pigmentName);
        printf("value        : %d\n", pp[i].value);
        printf("chroma       : %d\n", pp[i].chroma);
        printf("(a,b)        : (%d,%d)\n", pp[i].abValue[0], pp[i].abValue[1]);
        printf("hue [degrees]: %d\n", pp[i].hueAngle);
        printf("huePurity    : %.2f\n", pp[i].huePurity);
        printf("(ahp,ahp)    : (%.2f,%.2f)\n", pp[i].abHp[0], pp[i].abHp[1]);
    }

    return (0);
}


int printPaint(paint_t* pp, int i, int n){

    // check input (return 1 for failure)
    if(pp==NULL){
        printf("Error: Passed in empty array.\n");
        return (1);
    }
    else if(i<-1 || i>=n){
        printf("Error: Invalid index.\n");
        return (1);
    }

    if(i==-1){
        for(int j=0; j<n; j++){
            printf("--------------\n");
            printf("ciName       : %s\n", pp[j].ciName);
            printf("marketingName: %s\n", pp[j].marketingName);
            printf("manufacturer : %s\n", pp[j].manufacturer);
            printf("transparency : %i\n", pp[j].transparency);
            printf("staining     : %i\n", pp[j].staining);
            printf("valueRange   : %i\n", pp[j].valueRange);
            printf("granulating  : %i\n", pp[j].granulating);
            printf("blossom      : %i\n", pp[j].blossom);
            printf("diffusion    : %i\n", pp[j].diffusion);
            printf("hueAngle     : %i\n", pp[j].hueAngle);
            printf("hueShift     : %i\n", pp[j].hueShift);
            printf("lightfast    : %i\n", pp[j].lightfast);
        }
    }
    else{
        printf("--------------\n");
        printf("ciName       : %s\n", pp[i].ciName);
        printf("marketingName: %s\n", pp[i].marketingName);
        printf("manufacturer : %s\n", pp[i].manufacturer);
        printf("transparency : %i\n", pp[i].transparency);
        printf("staining     : %i\n", pp[i].staining);
        printf("valueRange   : %i\n", pp[i].valueRange);
        printf("granulating  : %i\n", pp[i].granulating);
        printf("blossom      : %i\n", pp[i].blossom);
        printf("diffusion    : %i\n", pp[i].diffusion);
        printf("hueAngle     : %i\n", pp[i].hueAngle);
        printf("hueShift     : %i\n", pp[i].hueShift);
        printf("lightfast    : %i\n", pp[i].lightfast);
    }

    return (0);
}


paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp){

    int capacity = 10;
    int fmin = 0;
    int fmax = 0;
    int err;
    float xlow, xhigh;
    paint_t* spa = NULL;
    
    // check input (returning NULL pointer for failure)
    if(pp==NULL){
        printf("Error: Passed in empty array.\n");
        return (spa);
    }
    else if(rmin<0 || rmin>1 || rmax<0 || rmax>1){
        printf("Error: Passed in invalid range value(s).\n");
        return (spa);
    }
    else if(rmin>rmax){ // passing in equal values is valid
        printf("Error: rmin is greater than rmax.\n");
        return (spa);
    }

    *nspp = 0; // start count of valid entries at 0

    // get min and max values from file
    err = getFileRange(pp, npp, &fmin, &fmax, getType);
    if(err==1){
        printf("Error: Could not retrieve file range values.\n");
        return (spa);
    }

    // calculate xlow and xhigh from file min and max values
    xlow = fmin + rmin * (fmax - fmin);
    xhigh = fmin + rmax * (fmax - fmin);

    // allocate memory
    spa = malloc(capacity * sizeof(paint_t));

    // loop through main paint array
    for(int i=0; i<npp; i++){
        // reallocate subarray if entries reaches capacity
		if(*nspp>=capacity){
			capacity *= 2;
			spa = realloc(spa, (capacity * sizeof(paint_t)));
		}

        // load valid entries into subarray
        switch(getType){
            case(0):
                if(xlow <= pp[i].hueAngle && pp[i].hueAngle <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(1):
                if(xlow <= pp[i].valueRange && pp[i].valueRange <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(2):
                if(xlow <= pp[i].granulating && pp[i].granulating <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(3):
                if(xlow <= pp[i].transparency && pp[i].transparency <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(4):
                if(xlow <= pp[i].staining && pp[i].staining <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(5):
                if(xlow <= pp[i].blossom && pp[i].blossom <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
            case(6):
                if(xlow <= pp[i].lightfast && pp[i].lightfast <= xhigh){
                    spa[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;
        }
    }

    return (spa); // return subarray (works even if no valid entries were found)
}


int getFileRange(paint_t* pp, int npp, int* fmin, int* fmax, gRange_t getType){

    if(pp==NULL){
        printf("Error: Passed in empty array.\n");
        return (1); // failure
    }

    switch(getType){
        case(0):
            *fmin = pp[0].hueAngle;
            *fmax = pp[0].hueAngle;

            for(int i=0; i<npp; i++){
                if(pp[i].hueAngle != 999){ // check for dummy value to leave out of comparisons
                    if(pp[i].hueAngle < *fmin){
                        *fmin = pp[i].hueAngle;
                    }
                    if(pp[i].hueAngle > *fmax){
                        *fmax = pp[i].hueAngle;
                    }
                }
            }
            break;

        case(1):
            *fmin = pp[0].valueRange;
            *fmax = pp[0].valueRange;

            for(int i=0; i<npp; i++){
                if(pp[i].valueRange != 999){
                    if(pp[i].valueRange < *fmin){
                        *fmin = pp[i].valueRange;
                    }
                    if(pp[i].valueRange > *fmax){
                        *fmax = pp[i].valueRange;
                    }
                }
            }
            break;

        case(2):
            *fmin = pp[0].granulating;
            *fmax = pp[0].granulating;

            for(int i=0; i<npp; i++){
                if(pp[i].granulating != 999){
                    if(pp[i].granulating < *fmin){
                        *fmin = pp[i].granulating;
                    }
                    if(pp[i].granulating > *fmax){
                        *fmax = pp[i].granulating;
                    }
                }
            }
            break;

        case(3):
            *fmin = pp[0].transparency;
            *fmax = pp[0].transparency;

            for(int i=0; i<npp; i++){
                if(pp[i].transparency != 999){
                    if(pp[i].transparency < *fmin){
                        *fmin = pp[i].transparency;
                    }
                    if(pp[i].transparency > *fmax){
                        *fmax = pp[i].transparency;
                    }
                }
            }
            break;

        case(4):
            *fmin = pp[0].staining;
            *fmax = pp[0].staining;

            for(int i=0; i<npp; i++){
                if(pp[i].staining != 999){
                    if(pp[i].staining < *fmin){
                        *fmin = pp[i].staining;
                    }
                    if(pp[i].staining > *fmax){
                        *fmax = pp[i].staining;
                    }
                }
            }
            break;

        case(5):
            *fmin = pp[0].blossom;
            *fmax = pp[0].blossom;

            for(int i=0; i<npp; i++){
                if(pp[i].blossom != 999){
                    if(pp[i].blossom < *fmin){
                        *fmin = pp[i].blossom;
                    }
                    if(pp[i].blossom > *fmax){
                        *fmax = pp[i].blossom;
                    }
                }
            }
            break;

        case(6):
            *fmin = pp[0].lightfast;
            *fmax = pp[0].lightfast;

            for(int i=0; i<npp; i++){
                if(pp[i].lightfast != 999){
                    if(pp[i].lightfast < *fmin){
                        *fmin = pp[i].lightfast;
                    }
                    if(pp[i].lightfast > *fmax){
                        *fmax = pp[i].lightfast;
                    }
                }
            }
            break;
    }

    return (0); // success
}


paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp){

    paint_t* paintArray;
    int capacity = 10;
    int i = 0;

    //Allocate space for array
    paintArray = malloc((capacity) * sizeof(paint_t));
    if (paintArray == NULL){
        return (NULL);
    }

    *nspp = 0; // start count of valid entries at 0

    //Looping through file
    while(i < npp){ 
        //Checking if need to realloc.
        if(*nspp == capacity){
            capacity = (capacity) * 2; 
            //Checking if realloc succeeds with a temp pointer.
            paint_t* tempArray = realloc(paintArray, (capacity) * sizeof(paint_t));
            if(tempArray == NULL){
                printf("Error: Realloc Failed.\n");
                return (NULL);
            }

            paintArray = tempArray;
            tempArray = NULL;
        }

        switch (getType){
            // CINAME
            case (0):
                if( (strcmp(pp[i].ciName, name)) == 0 ){
                    paintArray[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;

            //MARKETINGNAME
            case (1):
                if( (strcmp(pp[i].marketingName, name)) == 0 ){
                    paintArray[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;

            //MANUFACTURER
            case (2):
                if( (strcmp(pp[i].manufacturer, name)) == 0 ){
                    paintArray[*nspp] = pp[i];
                    *nspp += 1;
                }
                break;

            default:
                printf("Error: Incorrect value inputted");
                return (NULL);

        }

        i++;
    }

    return (paintArray);
}


/*******************************************************************************
* MILESTONE 3 FUNCTIONS
*******************************************************************************/


paint_t* getPaintHue(paint_t* pp, int* n, colour_t colour){ // MATT

    paint_t* hueRange = NULL;
    int capacity = 10;
    int hueMin = 0;
    int hueMax = 0;
    int arrNum = 0;

    hueRange = malloc((capacity) * sizeof(paint_t));
    if (hueRange == NULL){
        return (NULL);
    }

    //Determining which colour was chosen.
    switch (colour){
        case (0):
            hueMin = RED_MIN;
            hueMax = RED_MAX;
            break;

        case (1):
            hueMin = RED_ORANGE_MIN;
            hueMax = RED_ORANGE_MAX;
            break;

        case (2):
            hueMin = ORANGE_MIN;
            hueMax = ORANGE_MAX;
            break;

        case (3):
            hueMin = YELLOW_ORANGE_MIN;
            hueMax = YELLOW_ORANGE_MAX;
            break;

        case (4):
            hueMin = YELLOW_MIN;
            hueMax = YELLOW_MAX;
            break;

        case (5):
            hueMin = YELLOW_GREEN_MIN;
            hueMax = YELLOW_GREEN_MAX;
            break;

        case (6):
            hueMin = GREEN_MIN;
            hueMax = GREEN_MAX;
            break;

        case (7):
            hueMin = BLUE_GREEN_MIN;
            hueMax = BLUE_GREEN_MAX;
            break;

        case (8):
            hueMin = BLUE_MIN;
            hueMax = BLUE_MAX;
            break;

        case (9):
            hueMin = BLUE_VIOLET_MIN;
            hueMax = BLUE_VIOLET_MAX;
            break;

        case (10):
            hueMin = VIOLET_MIN;
            hueMax = VIOLET_MAX;
            break;

        case (11):
            hueMin = RED_VIOLET_MIN;
            hueMax = RED_VIOLET_MAX;
            break;

        default:
            printf("Error: Color not recognized.\n");
            return (NULL);
    }

    if (colour == RED_ORANGE){

        for (int i = 0; i < *n; i++){

            //Checking if array has reach capacity.
            if(arrNum == capacity){

                capacity = (capacity) * 2; 
                //Checking if realloc succeeds with a temp pointer.
                // paint_t* tempArray = realloc(hueRange, (capacity) * sizeof(paint_t));
                // if(tempArray == NULL){
                //     printf("Error: Realloc Failed.\n");
                //     return (NULL);
                // }
                hueRange = realloc(hueRange, (capacity) * sizeof(paint_t)); // CLAIRE CHANGED
            }                

            //Checking if hue equals 0 or 360 as they can be used interchangeably.
            if( (pp[i].hueAngle == 0) || (pp[i].hueAngle == 360) ){

                hueRange[arrNum] = pp[i];
                arrNum++;
            }

            else{
                // #define RED_ORANGE_MIN 345 
                // #define RED_ORANGE_MAX 14
                if ( ((pp[i].hueAngle >= hueMin) && (pp[i].hueAngle <= 359)) || ((pp[i].hueAngle >= 1) && (pp[i].hueAngle <= hueMax)) ){

                    hueRange[arrNum] = pp[i];
                    arrNum++;
                }
            }
        }
        
    }

    //If the color is anything other than RED_ORANGE.
    else{

        for (int i = 0; i < *n; i++){

            if ( (pp[i].hueAngle >= hueMin) && (pp[i].hueAngle <= hueMax) ){

                //Checking if array has reach capacity.
                if(arrNum == capacity){
                    capacity = (capacity) * 2; 
                    //Checking if realloc succeeds with a temp pointer.
                    // paint_t* tempArray = realloc(hueRange, (capacity) * sizeof(paint_t));
                    // if(tempArray == NULL){
                    //     printf("Error: Realloc Failed.\n");
                    //     return (NULL);
                    // }
                    hueRange = realloc(hueRange, (capacity) * sizeof(paint_t)); // CLAIRE CHANGED
                }
                hueRange[arrNum] = pp[i];
                arrNum++;
            }
        }
    }
    *n = arrNum;

    return (hueRange);
}


int printHue(paint_t* subArr, int *subNum, int fullNum, colour_t colour){ // MATT

    if(subArr == NULL){
        printf("Error: Array parameter is empty.\n");
        return (1);
    }

        //Printing the color genre name for confirmation.
    switch (colour){
        case (0):
            printf("\nPrinting Red Paints\n");
            break;

        case (1):
            printf("\nPrinting Red-Orange Paints\n");
            break;

        case (2):
            printf("\nPrinting Orange Paints\n");
            break;

        case (3):
            printf("\nPrinting Yellow-Orange Paints\n");
            break;

        case (4):
            printf("\nPrinting Yellow Paints\n");
            break;

        case (5):
            printf("\nPrinting Yellow-Green Paints\n");
            break;

        case (6):
            printf("\nPrinting Green Paints\n");
            break;

        case (7):
            printf("\nPrinting Blue-Green Paints\n");
            break;

        case (8):
            printf("\nPrinting Blue Paints\n");
            break;

        case (9):
            printf("\nPrinting Blue-Violet Paints\n");
            break;

        case (10):
            printf("\nPrinting Violet Paints\n");
            break;

        case (11):
            printf("\nPrinting Red-Violet Paints\n");
            break;

        default:
            printf("\nError: Color not recognized.\n");
            return(1);
    }
    printf("Number of paints within selected color: %d\n", *subNum);
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < *subNum; i++){
        printf("%s, %s, %s, ", subArr[i].ciName, subArr[i].marketingName, subArr[i].manufacturer);
        printf("%i, %i, %i, ", subArr[i].transparency, subArr[i].staining, subArr[i].valueRange);
        printf("%i, %i, %i, ", subArr[i].granulating, subArr[i].blossom, subArr[i].diffusion);
        printf("%i, %i, %i\n", subArr[i].hueAngle, subArr[i].hueShift, subArr[i].lightfast);
    }
    printf("------------------------------------------------------------\n");

    free(subArr);
    subArr = NULL;
    *subNum = fullNum;

    return(0);
}


paint_t* getPalette(paint_t* pp, int* n, char* type, char* properties){ // CLAIRE

    // paletteType: full = 0, triad = 1, complimentary = 2, split_complimentary = 3
    // propertyType: NULL = -1, transparency = 0, staining = 1, blossom = 2

    char typeCopy[50];
    char propertiesCopy[50];
    char* token;
    char* token2;
    int paletteType;
    colour_t paletteColor;
    int propertyType;
    int propertyValue;
    int capacity = 10;
    int hueN = *n;
    paint_t* hueArray = NULL;
    paint_t* validHueArray = NULL;
    int paletteN = 0;
    paint_t* paletteArray = NULL;
    int colors[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // extra -1 value in array to signal end of array when all 12 paint colors loaded in

    strcpy(typeCopy, type);
    if(properties!=NULL){
        strcpy(propertiesCopy, properties);
    }
    
    // check input and return NULL pointer for failure
    // MOVE ERROR CHECKS TO HELPER FUNCTIONS

    // check if array is empty
    if(pp==NULL){
        printf("Error: Passed in empty array.\n");
        return (paletteArray);
    }

    // check type parameter
    token = strtok(typeCopy, ":"); // should return the palette type
    if(strcmp(token, "full")==0){
        paletteType = 0;
    }
    else if(strcmp(token, "triad")==0){
        paletteType = 1;
    }
    else if(strcmp(token, "complimentary")==0){
        paletteType = 2;
    }
    else if(strcmp(token, "split_complimentary")==0){
        paletteType = 3;
    }
    else{
        printf("Error: Format of type (palette name) is invalid.\n");
        return (paletteArray);
    }

    token = strtok(NULL, "\0"); // should return the palette color
    if(strcmp(token, "red")==0){
        paletteColor = 0;
    }
    else if(strcmp(token, "red_orange")==0){
        paletteColor = 1;
    }
    else if(strcmp(token, "orange")==0){
        paletteColor = 2;
    }
    else if(strcmp(token, "yellow_orange")==0){
        paletteColor = 3;
    }
    else if(strcmp(token, "yellow")==0){
        paletteColor = 4;
    }
    else if(strcmp(token, "yellow_green")==0){
        paletteColor = 5;
    }
    else if(strcmp(token, "green")==0){
        paletteColor = 6;
    }
    else if(strcmp(token, "blue_green")==0){
        paletteColor = 7;
    }
    else if(strcmp(token, "blue")==0){
        paletteColor = 8;
    }
    else if(strcmp(token, "blue_violet")==0){
        paletteColor = 9;
    }
    else if(strcmp(token, "violet")==0){
        paletteColor = 10;
    }
    else if(strcmp(token, "red_violet")==0){
        paletteColor = 11;
    }
    else{
        printf("Error: Format of type (color) is invalid.\n");
        return (paletteArray);
    }

    // check properties parameter
    if(properties!=NULL){ // properties is allowed to be NULL
        token2 = strtok(propertiesCopy, ":"); // should return the property type
        if(strcmp(token2, "transparency")==0){
            propertyType = 0;
        }
        else if(strcmp(token2, "staining")==0){
            propertyType = 1;
        }
        else if(strcmp(token2, "blossom")==0){
            propertyType = 2;
        }
        else{
            printf("Error: Format of properties (property type) is invalid.\n");
            return (paletteArray);
        }

        token2 = strtok(NULL, "\0"); // should return the property value
        for(int i=0; i<strlen(token2); i++){
            if(isdigit(token2[i])==0){
                printf("Error: Format of properties (property value) is invalid.\n");
                return (paletteArray);
            }
        }
        propertyValue = atoi(token2);
        if(propertyValue<0 || propertyValue>4){
            printf("Error: Format of properties (property value) is invalid.\n");
            return (paletteArray);
        }
    }
    else{
        propertyType = -1;
    }

    // allocate memory
    paletteArray = malloc(capacity * sizeof(paint_t));

    // calculate which colors to pull based on palette type
        // could replace paletteColor with colors[0]?? in error checks above too
    switch(paletteType){
        case(0):
            for(int i=0; i<12; i++){
                colors[i] = i;
            }
            break;

        case(1): // triad
            colors[0] = paletteColor;
            colors[1] = (paletteColor + 4) % 12;
            colors[2] = (paletteColor + 8) % 12;
            break;

        case(2): // complimentary
            colors[0] = paletteColor;
            colors[1] = (paletteColor + 6) % 12;
            break; 

        case(3): // split complimentary
            colors[0] = paletteColor;
            colors[1] = (paletteColor + 5) % 12;
            colors[2] = (paletteColor + 7) % 12;
            break;
    }    

    for(int i=0; colors[i]!=(-1); i++){
        // get subarray of each paint color using getPaintHue (using Matt's function)
        hueArray = getPaintHue(pp, &hueN, colors[i]);

        // narrow hueArray down to valid property entries only
        // COULD USE getPaintRange FUNCTION HERE INSTEAD OF HELPER FUNCTIONS STUPID!!
        switch(propertyType){
            case(-1): // no property testing
                validHueArray = malloc(hueN * sizeof(paint_t));
                for(int i=0; i<hueN; i++){
                    validHueArray[i] = hueArray[i];
                }
                break;

            case(0): // transparency
                validHueArray = getValidTransparency(hueArray, &hueN, propertyValue);
                break;

            case(1): // staining
                validHueArray = getValidStaining(hueArray, &hueN, propertyValue);
                break;

            case(2): // blossom
                validHueArray = getValidBlossom(hueArray, &hueN, propertyValue);
                break;
        }

        // add paints with valid values into paletteArray
        for(int i=0; i<hueN; i++){
            // reallocate paletteArray if entries reaches capacity
            if(paletteN>=capacity){
                capacity *= 2;
                paletteArray = realloc(paletteArray, (capacity * sizeof(paint_t)));
            }

            paletteArray[paletteN] = validHueArray[i];
            paletteN += 1;
        }

        hueN = *n; // reset hueN for next loop through

        // deallocate subarrays
        free(hueArray);
        hueArray = NULL;
        free(validHueArray);
        validHueArray = NULL;
    }

    *n = paletteN; // replace paintN with size of paletteArray

    return (paletteArray);
}


paint_t* getValidTransparency(paint_t* spa, int* n, int value){ // CLAIRE

    int validHuesN = 0;
    paint_t* validHues = NULL;

    validHues = malloc(*n * sizeof(paint_t)); // will be less than or equal to size of hueArray

    // loop through subarray and sort out valid paints
    for(int i=0; i<*n; i++){
        if(spa[i].transparency==value){
            validHues[validHuesN] = spa[i];
            validHuesN += 1;
        }
    } 

    *n = validHuesN; // n is passed in as hueN and comes out as validHuesN
    return (validHues);
}


paint_t* getValidStaining(paint_t* spa, int* n, int value){ // CLAIRE

    int validHuesN = 0;
    paint_t* validHues = NULL;

    validHues = malloc(*n * sizeof(paint_t)); // will be less than or equal to size of hueArray

    // loop through subarray and sort out valid paints
    for(int i=0; i<*n; i++){
        if(spa[i].staining==value){
            validHues[validHuesN] = spa[i];
            validHuesN += 1;
        }
    } 

    *n = validHuesN; // n is passed in as hueN and comes out as validHuesN
    return (validHues);
}

 
paint_t* getValidBlossom(paint_t* spa, int* n, int value){ // CLAIRE

    int validHuesN = 0;
    paint_t* validHues = NULL;

    validHues = malloc(*n * sizeof(paint_t)); // will be less than or equal to size of hueArray

    // loop through subarray and sort out valid paints
    for(int i=0; i<*n; i++){
        if(spa[i].blossom==value){
            validHues[validHuesN] = spa[i];
            validHuesN += 1;
        }
    } 

    *n = validHuesN; // n is passed in as hueN and comes out as validHuesN
    return (validHues);
}


int printArray(paint_t* pArray, int n){ // CLAIRE

    if(pArray==NULL){
        printf("Error: Passed in empty array.\n");
        return (1);
    }

    for(int i=0; i<n; i++){
        printf("%s, %s, %s, ", pArray[i].ciName, pArray[i].marketingName, pArray[i].manufacturer);
        printf("%i, %i, %i, ", pArray[i].transparency, pArray[i].staining, pArray[i].valueRange);
        printf("%i, %i, %i, ", pArray[i].granulating, pArray[i].blossom, pArray[i].diffusion);
        printf("%i, %i, %i\n", pArray[i].hueAngle, pArray[i].hueShift, pArray[i].lightfast);
    }

    return(0);
}


int isValidTypeInput(char* input){ // CLAIRE

    char inputCopy[strlen(input)+1];
    char* token;

    strcpy(inputCopy, input);

    token = strtok(inputCopy, ":"); // should return the palette type
    if((strcmp(token, "full")!=0) && (strcmp(token, "triad")!=0) && (strcmp(token, "complimentary")!=0) && (strcmp(token, "split_complimentary")!=0)){
        return (1);
    }

    token = strtok(NULL, "\0"); // should return the palette color
    if(token == NULL){
        return(1);
    }
    else if(strcmp(token, "red")==0){
        return(0);
    }
    else if(strcmp(token, "red_orange")==0){
        return(0);
    }
    else if(strcmp(token, "orange")==0){
        return(0);
    }
    else if(strcmp(token, "yellow_orange")==0){
        return(0);
    }
    else if(strcmp(token, "yellow")==0){
        return(0);
    }
    else if(strcmp(token, "yellow_green")==0){
        return(0);
    }
    else if(strcmp(token, "green")==0){
        return(0);
    }
    else if(strcmp(token, "blue_green")==0){
        return(0);
    }
    else if(strcmp(token, "blue")==0){
        return(0);
    }
    else if(strcmp(token, "blue_violet")==0){
        return(0);
    }
    else if(strcmp(token, "violet")==0){
        return(0);
    }
    else if(strcmp(token, "red_violet")==0){
        return(0);
    }
    else{
        return(1);
    }
}


int isValidPropertyInput(char* input){ // CLAIRE

    char inputCopy[strlen(input)+1];
    int inputValue;
    char* token;

    strcpy(inputCopy, input);

    if(strcmp(input, "none")==0){ // properties is allowed to be "none"
        return(0);
    }
    else{
        token = strtok(inputCopy, ":"); // should return the property type
        if((strcmp(token, "transparency")!=0) && (strcmp(token, "staining")!=0) && (strcmp(token, "blossom")!=0)){
            return(1);
        }

        token = strtok(NULL, "\0"); // should return the property value
        if(token==NULL){
            return(1);
        }

        for(int i=0; i<strlen(token); i++){
            if(isdigit(token[i])==0){
                return (1);
            }
        }

        inputValue = atoi(token);
        if(inputValue<0 || inputValue>4){
            return (1);
        }
    }

    return(0);
}