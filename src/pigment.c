// Claire Smith and Matt Beaulieu
// Project Function Implementations

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        if(token==NULL || strcmp(token, ".")==0){
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

int printPigment(pigment_t* pp, int i, int n){ // MATT

}


int printPaint(paint_t* pp, int i, int n){ // CLAIRE

}


paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp){ // CLAIRE

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

    // loop through main paint array and load valid entries into subarray
    // reallocate subarray if entries reaches capacity
    // increment nspp to count valid entries

    // set subarray pointer to NULL and return if no valid entries were found (nspp==0)

    return (spa); // return subarray
}

int getFileRange(paint_t* pp, int npp, int* fmin, int* fmax, gRange_t getType){

    if(pp==NULL){
        printf("Error: Passed in empty array.\n");
        return (1); // failure
    }

    char element[12];

    switch(getType){
        case(0):
            strcpy(element, "hueAngle");
            break;
        case(1):
            strcpy(element, "valueRange");
            break;
        case(2):
            strcpy(element, "granulating");
            break;
        case(3):
            strcpy(element, "transparency");
            break;
        case(4):
            strcpy(element, "staining");
            break;
        case(5):
            strcpy(element, "blossom");
            break;
        case(6):
            strcpy(element, "lightfast");
            break;
    }

    // loop through main array to find min and max
    *fmin = pp[0].element;
    *fmax = pp[0].element;

    for(int i=0; i<npp; i++){
        if(pp[i].element < *fmin){
            *fmin = pp[i].element;
        }

        if(pp[i].element > *fmax){
            *fmax = pp[i].element;
        }
    }

    return (0); // success
}


paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp){ // MATT
    paint_t* paintArray;
    int capacity = 10;
    int i = 0;
    int j = 0;

    //Allocate space for array
    paintArray = malloc((capacity) * sizeof(paint_t));
    if (paintArray == NULL){
        return (NULL);
    }

    //Looping through file
    while(i < 5){ //CHANGE TO *npp

        //Checking if need to realloc.
        if(i == capacity){
            capacity = (capacity) * 2; 
            //Checking if realloc succeeds with a temp pointer.
            paint_t* tempArray = realloc(paintArray, (capacity) * sizeof(paint_t));
            if(tempArray == NULL){
                printf("Error: Realloc Failed.\n");
                return (NULL);
            }

            paintArray = tempArray;
            tempArray = NULL;



        if ( strcmp (getType, MARKETINGNAME) == 0 ){

            if( (strcmp(pp[i].marketingName, name)) == 0 ){
                paintArray[j] = pp[i];
                *nspp++;
                j++;
            }

        }

        i++;

    }

    return (paintArray)
}






}