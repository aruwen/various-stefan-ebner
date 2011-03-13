#pragma once

#include "MovingObject.h"

class Player: public MovingObject
{
public:
	Player(float xPosition, float yPosition);
	~Player(void);
	void update();
	void draw();
	void setPressedUp(bool state) {mPressedUp = state;}
	void setPressedDown(bool state) {mPressedDown = state;}
	void setPressedLeft(bool state) {mPressedLeft = state;}
	void setPressedRight(bool state) {mPressedRight = state;}
	static const float maxSpeed;
private:
	bool mPressedUp, mPressedDown, mPressedLeft, mPressedRight;
};
