// Claire Smith and Matt Beaulieu
// Project Milestone 1 Header File

struct Pigment{
	char ciName[50];
	char pigmentName[50];
	int value;
	int chroma;
	int abValue[2];
	int hueAngle;
	float huePurity;
	float abHp[2]; 
};


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
int loadPigmentData(char* filename, struct Pigment *pArray, int* n);

int loadPaintData(char* filename, paint_t* pArray, int* n);
