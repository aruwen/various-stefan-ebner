#ifndef SPRING_H
#define SPRING_H

#include "Body.h"

class Spring
{
public:
	Spring(void);
	~Spring(void);
	Body *mFrom;
	Body *mTo;
	float mStrength;
	float mLength;
	float mNormalLength;

	virtual void draw();
	virtual void update(float dt);
};

#endif