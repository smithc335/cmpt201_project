// Claire Smith and Matt Beaulieu
// Project Milestone 1 Header File

typedef struct pigment_template{
	// Matt's struct
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
int loadPigmentData(char* filename, pigment_t* pArray, int* n);

int loadPaintData(char* filename, paint_t* pArray, int* n);
