#include "MovingObject.h"
#include "Utility.h"

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
	mTimer.stop();
	mPosition += mSpeed * (float)mTimer.getTimeMilliSec() / 500.0f;
	handleCollision();
	mTimer.start();
}

ofPoint MovingObject::getPosition()
{
	return mPosition;
}

ofPoint MovingObject::getSpeed()
{
	return mSpeed;
}

float MovingObject::getMaxSpeed()
{
	return mMaxSpeed;
}

void MovingObject::handleCollision()
{
	if (mPosition.x < 0)
		mPosition.x = 0;
	else if(mPosition.x > WINDOW_WIDTH)
		mPosition.x = WINDOW_WIDTH;

	if (mPosition.y < 0)
		mPosition.y = 0;
	else if(mPosition.y > WINDOW_HEIGHT)
		mPosition.y = WINDOW_HEIGHT;
}