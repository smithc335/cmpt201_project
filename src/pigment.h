// Claire Smith and Matt Beaulieu
// Project Milestone 1 Header File

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