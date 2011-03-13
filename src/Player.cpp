#include "Player.h"



Player::Player(float xPosition, float yPosition):
	mPressedUp(false),
	mPressedDown(false),
	mPressedLeft(false),
	mPressedRight(false)
{	
	mMaxSpeed = 5.0;
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);
}

Player::~Player(void)
{
}

void Player::update()
{
	ofPoint speed;
	if (mPressedUp)		speed += ofPoint(0.0,-mMaxSpeed,0.0);
	if (mPressedDown)	speed += ofPoint(0.0,+mMaxSpeed,0.0);
	if (mPressedLeft)	speed += ofPoint(-mMaxSpeed,0.0,0.0);
	if (mPressedRight)	speed += ofPoint(+mMaxSpeed,0.0,0.0);

	setSpeed(speed);
	move();
}

void Player::draw()
{
	ofSetColor(255,255,255);
	ofNoFill();
	ofCircle(mPosition.x, mPosition.y, 10.0);
}

void Player::setSpeed(ofPoint speed)
{
	mSpeed = speed;
}