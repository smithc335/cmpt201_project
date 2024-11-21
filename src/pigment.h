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

	CINAME, MARKETINGNAME, MANUFACTURER;

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
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
int printPigment(pigment_t* pp, int i, int n) // MATT


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
int printPaint(paint_t* pp, int i, int n) // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
paint_t* getPaintRange(paint_t* pp, int npp, float rmin, float rmax, gRange_t getType, int* nspp) // CLAIRE


/*******************************************************************************
* Purpose: 
* Parameters:
*
* Returns: 
*******************************************************************************/
paint_t* getPaintValue(paint_t* pp, int npp, char* name, gValue_t getType, int* nspp) // MATT