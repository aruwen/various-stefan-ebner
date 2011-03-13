#pragma once

#include "ofTypes.h"
#include "ofGraphics.h"

#include "Timer.h"

class MovingObject
{
public:
	MovingObject(void);
	~MovingObject(void);
	void accelerateWithVector(ofPoint vector);
	virtual void update() = 0;
	virtual void draw() = 0;
	void move();
	ofPoint getPosition();
	ofPoint getSpeed();
	float getMaxSpeed();
protected:
	void handleCollision();
	Timer mTimer;
	ofPoint mPosition, mSpeed;
	float mMaxSpeed;
};
