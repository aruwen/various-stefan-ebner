#ifndef UTILITY
#define UTILITY

#include "ofTypes.h"

#define UTILITY_PI 3.14159265
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

ofPoint getProjectionVector(ofPoint u, ofPoint v); //projects v on u

ofPoint makeLeftNormalVector(ofPoint u);

float dot(ofPoint u, ofPoint v);

float getLength(ofPoint u);

float randomFloat();

float randomFloatClamped();

float randomRadian();

#endif