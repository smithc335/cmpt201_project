# cmpt201_project
Claire Smith and Matt Beaulieu

# COMPILATION

To compile the main program file, type "make" or "make project" in the 
commandline while in the main project directory. To run the program, type 
"./project" into the commandline while in the bin directory. This will display
the Paints Program using functions implemented in the pigment.c file. 

The "make" or "make project" commands will create executables and object files.
Executables are placed in the bin directory and object files are placed in the
obj directory. To remove all executables and object files, run "make clean"
while in the main directory.

Executables and object files will be ignored during committing and pushing to
the remote repository due to being specified in the .gitignore file.

# VARIABLES

In pigments.dat: 
    COLOR INDEX = generic C.I. name of the pigment (this is missing for 
                  convenience mixtures and unclassified mineral pigments)
    PIGMENT NAME = common pigment name or marketing name
    J, aC, bC = pigment location in the CIECAM color appearance space 
                [Value, a,b]
    C = CIECAM pigment chroma, defined as (aC2+bC2)0.5
    HueAngle = CIECAM hue angle, defined as ARCTAN(bC/aC)
    Hue Purity = CIECAM hue purity, the ratio between the pigment chroma and 
                 the chroma of the optimal color of matching lightness and 
                 hue angle
    aHP, bHP = ab coordinates for pigment hue purity, scaled so that maximum
               possible hue purity equals 1.0

In paints.dat: 
    C.I.NAME = pigment
    MARKETING NAME = paint
    Manufacturer
    Code
    Tr = Transparency: 0 (very opaque) to 4 (transparent)
    St = Staining: 0 (nonstaining) to 4 (heavily staining)
    VR = Value Range: the value of the masstone color subtracted from the value
         of white paper, in steps of a 100 step value scale 
    Gr = Granulation: 0 (liquid texture) to 4 (granular)
    Bl = Blossom: 0 (no blossom) to 4 (strong blossom)
    Df = Diffusion: 0 (inert) to 4 (very active diffusion)
    HA = Hue Angle in degrees of the CIELAB a*b* plane
    HS = Hue Shift as the undertone hue angle minus the masstone hue angle, in
         degrees of the CIELAB a*b* plane
    Lf = Lightfastness: 1 (very fugitive) to 8 (very lightfast) for paint in
         tint, full strength (1998 test/2004 test)

# HUE MIN/MAX JUSTIFICATION
For function:  paint_t* getPaintHue(paint_t* pp, int* n, colour_t colour)

In pigment.h, the minimum and maximum values for the colors red, red-orange, 
orange, yellow-orange, yellow, yellow-green, green, blue-green, blue, 
blue-violet, violet, and red-violet are defined. The min and max ranges are 
based on a 15 degree window on either side of the aforementioned colours 
respective of their placement on the colour wheel. Min and max ranges are 
exclusive of each other to prevent overlapping complications. 