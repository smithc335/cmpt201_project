// Claire Smith and Matt Beaulieu
// Project Header File

#define RED_MIN 315
#define RED_MAX 344
#define RED_ORANGE_MIN 345 
#define RED_ORANGE_MAX 14
#define ORANGE_MIN 15
#define ORANGE_MAX 44
#define YELLOW_ORANGE_MIN 45 
#define YELLOW_ORANGE_MAX 74
#define YELLOW_MIN 75
#define YELLOW_MAX 104
#define YELLOW_GREEN_MIN 105 
#define YELLOW_GREEN_MAX 134
#define GREEN_MIN 135
#define GREEN_MAX 164
#define BLUE_GREEN_MIN 165 
#define BLUE_GREEN_MAX 194
#define BLUE_MIN 195
#define BLUE_MAX 224
#define BLUE_VIOLET_MIN 225
#define BLUE_VIOLET_MAX 254
#define VIOLET_MIN 255
#define VIOLET_MAX 284
#define RED_VIOLET_MIN 285
#define RED_VIOLET_MAX 314

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
	HUE, 
	VALUE, 
	GRANULATING, 
	TRANSPARENT, 
	STAINING, 
	BLOOM, 
	LIGHTFAST
} gRange_t;

typedef enum{
	CINAME, 
	MARKETINGNAME, 
	MANUFACTURER
} gValue_t;

typedef enum{
	RED,           // 0
	RED_ORANGE,    // 1 
	ORANGE,        // 2
	YELLOW_ORANGE, // 3
	YELLOW,        // 4
	YELLOW_GREEN,  // 5
	GREEN,         // 6
	BLUE_GREEN,    // 7
	BLUE,          // 8
	BLUE_VIOLET,   // 9
	VIOLET,        // 10
	RED_VIOLET     // 11
} colour_t;

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
*		pigment_t* pp - The array of pigment structures.
*		int i - The integer index of the array.
*		int n - The size of the array of pigment structures.
*
* Returns: 0 if the function succeeded and 1 if it failed.
*******************************************************************************/
int printPigment(pigment_t* pp, int i, int n);


/*******************************************************************************
* Purpose: Prints paint data in a specified format.
* Parameters:
*		paint_t* pp - Pointer to the loaded array of paint structures.
*		int i - Integer index of the structure to be printed.
*		int n - Size of the array of paint structures.
* Returns: 0 if the function succeeded and 1 if the function failed.
*******************************************************************************/
int printPaint(paint_t* pp, int i, int n);


/*******************************************************************************
* Purpose: Gets a subset of paints from the loaded paint array of structures
*		   based on a name of an element and value range.
* Parameters:
*		paint_t* pp - Pointer to the loaded array of paint structures.
*		int npp - Number of elements within the paint data array.
*		float rmin - Minimum value of the normalized inclusive range.
*		float rmax - Maximum value of the normalized inclusive range.
*		gRange_t getType - Identifier to which the range is attached to.
*		int* nspp - Pointer to number of elements found to meet criteria.
* Returns: Pointer to dynamically allocated subarray of paint data found. Will 
*		   point to NULL if an error occurs.
*******************************************************************************/
paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp);


/*******************************************************************************
* Purpose: Gets the minimum and maximum values of a specified element from the
*		   loaded array of paint structures.
* Parameters:
*		paint_t* pp - Pointer to the loaded array of paint structures.
*		int npp - Number of elements within the paint data array.
*		int* fmin - Pointer to minimum file value found.
*		int* fmax - Pointer to maximum file value found.
*		gRange_t getType - Identifier of the struct element to be searched.
* Returns: 0 if the function succeeded and 1 if the function failed.
*******************************************************************************/
int getFileRange(paint_t* pp, int npp, int* fmin, int* fmax, gRange_t getType);


/*******************************************************************************
* Purpose: Creates a subset array of paint structures, from the previously 
*          loaded array of paint data structures, based on a name and an 
*		   identifier (i.e. CINAME, MARKETINGNAME, MANUFACTURER).
* Parameters:
*		paint_t* pp - The array of paint structures.
*		int npp - The size of the array of paint structures.
*		gValue_t getType - The enumerated value based on the 3 identifiers.
*		char* name - The specific name found under the identifier's category. 
*					 (i.e. "cerulean blue" is a name found in the MARKETINGNAME
*					 category).
*		int* nspp - Pointer to the number of elements that have the specified 
*					name.
* Returns: Pointer to the dynamically allocated array of paint structures based
*		   on the specific name and identifier criteria. Will point to NULL if 
*		   the function failed.
*******************************************************************************/
paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp);


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
paint_t* getPaintHue(paint_t* pp, int* n, colour_t colour); // MATT


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
int printHue(paint_t* subArr, int *subNum, int fullNum, colour_t colour); // MATT


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
paint_t* getPalette(paint_t* pp, int* n, char* type, char* properties); // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
paint_t* getValidTransparency(paint_t* spa, int* n, int value); // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
paint_t* getValidStaining(paint_t* spa, int* n, int value); // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*		
* Returns: 
*******************************************************************************/
paint_t* getValidBlossom(paint_t* spa, int* n, int value); // CLAIRE