// Claire Smith and Matt Beaulieu
// Project Milestone 1 Header File

typedef struct Pigment_template{
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
	char manufacturer[50]; // dynamic memory for char arrays??
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

// add documentation to functions!!
int loadPigmentData(char* filename, pigment_t *pArray, int* n);
//Purpose: To open a file that contains pigment information and assign pigment values to structure members within a dynamically allocated array of structures. Each structure represents a different pigment.
//Parameters: A string representing the filename, a dynamically allocated array of structures, and an integer pointer indicating the number of lines in the file containing pigments.
//Returns: 0 if function was successful in assigning pigment values and 1 if the file was unable to open properly. 

int loadPaintData(char* filename, paint_t** pArray, int* n);