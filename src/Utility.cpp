#include "Utility.h"
#include <limits>



ofPoint getProjectionVector(ofPoint u, ofPoint v)
{
	ofPoint w;
	w = u * (dot(u,v)/dot(u,u));
	return w;
}

ofPoint makeLeftNormalVector(ofPoint u)
{
	ofPoint v;
	v.x = -u.y;
	v.y = u.x;
	return v;
}

float dot(ofPoint u, ofPoint v)
{
	return u.x*v.x + u.y*v.y + u.z*v.z;
}

float getLength(ofPoint u)
{
	return sqrt(dot(u,u));
}


float randomFloat()
{
	return ((rand()) / ((float)RAND_MAX+1.0f));
}

float randomFloatClamped()
{
	//-1 to +1
	return randomFloat() - randomFloat();
}	

float randomRadian()
{
	return randomFloat() * (float)UTILITY_PI * 2.0f;
}