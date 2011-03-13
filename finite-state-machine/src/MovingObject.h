#pragma once

#include "ofTypes.h"
#include "ofGraphics.h"

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
protected:
	ofPoint mPosition, mSpeed;
};
