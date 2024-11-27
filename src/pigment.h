// Claire Smith and Matt Beaulieu
// Project Header File

typedef struct pigment_template{
	char ciName[50];
	char pigmentName[50];
	int value;
	int chroma;
	int abValue[2];
	int hueAngle;
	float huePurity;
	float abHp[2]; 
} pigment_t;

typedef struct paint_template{
	char ciName[20];
	char marketingName[50];
	char manufacturer[50];
	int transparency;
	int staining;
	int valueRange;
	int granulating;
	int blossom;
	int diffusion;
	int hueAngle;
	int hueShift;
	int lightfast;
} paint_t;

typedef enum{
	HUE, VALUE, GRANULATING, TRANSPARENT, STAINING, BLOOM, LIGHTFAST
} gRange_t;

typedef enum{
	CINAME, MARKETINGNAME, MANUFACTURER
} gValue_t;

/*******************************************************************************
* Purpose: To open a file that contains pigment information and assign pigment 
*          values to structure members within a dynamically allocated array of 
*          structures. Each structure represents a different pigment.
* Parameters:
*		char* filename - A string representing the filename.
*		pigment_t* pArray - A dynamically allocated array of structures.
*		int* n - An integer pointer indicating the number of lines in the file 
*				 containing pigments.
* Returns: pigment_t* - Pointer to the dynamically allocated array of structs.
*******************************************************************************/
pigment_t* loadPigmentData(char* filename, pigment_t* pArray, int* n);


/*******************************************************************************
* Purpose: Loads data from a given file into a dynamically allocated array of
*		   paint structures. Each struct represents one paint or one line.
* Parameters:
*		char* filename - String representing the given filename.
*		paint_t* pArray - Pointer to dynamically allocated array of structures.
*		int* n - Integer pointer indicating the number of data lines read from
*				 the given file.
* Returns: paint_t* - Pointer to the dynamically allocated array of structs.
*******************************************************************************/
paint_t* loadPaintData(char* filename, paint_t* pArray, int* n);


/*******************************************************************************
* Purpose: To print pigment data in a specified format.
* Parameters: 
		pigment_t* pp - The array of pigment structures.
		int i - The integer index of the array.
		int n - The size of the array of pigment structures.
*
* Returns: 0 if the function succeeded and 1 if it failed.
*******************************************************************************/
int printPigment(pigment_t* pp, int i, int n); // MATT


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
int printPaint(paint_t* pp, int i, int n); // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp); // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
int getFileRange(paint_t* pp, int npp, int* fmin, int* fmax, gRange_t getType); // CLAIRE


/*******************************************************************************
* Purpose: Creates a subset array of paint structures, from the previously 
           loaded array of paint data structures, based on a name and an 
		   identifier (i.e. CINAME, MARKETINGNAME, MANUFACTURER).
* Parameters:
		paint_t* pp - The array of paint structures.
		int npp - The size of the array of paint structures.
		gValue_t getType - The enumerated value based on the 3 identifiers.
		char* name - The specific name found under the identifier's category. 
					 (i.e. "cerulean blue" is a name found in the MARKETINGNAME
					 category).
		int* nspp - The pointer to the number of elements that have the specified 
					name.
*
* Returns: A pointer to the dynamically allocated array of paint structures based 
		   on the specific name and identifier criteria. Will NULL if the function 
		   failed.
*******************************************************************************/
paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp); // MATT