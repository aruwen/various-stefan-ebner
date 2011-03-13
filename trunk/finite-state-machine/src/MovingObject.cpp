#include "MovingObject.h"

MovingObject::MovingObject(void)
{
}

MovingObject::~MovingObject(void)
{
}

void MovingObject::accelerateWithVector(ofPoint vector)
{
	mSpeed += vector;
}

void MovingObject::move()
{
	mPosition += mSpeed;
}

ofPoint MovingObject::getPosition()
{
	return mPosition;
}

ofPoint MovingObject::getSpeed()
{
	return mSpeed;
}
