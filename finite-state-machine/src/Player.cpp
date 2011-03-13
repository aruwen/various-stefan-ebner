#include "Player.h"

const float Player::maxSpeed = 5.0;


Player::Player(float xPosition, float yPosition):
	mPressedUp(false),
	mPressedDown(false),
	mPressedLeft(false),
	mPressedRight(false)
{	
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);
}

Player::~Player(void)
{
}

void Player::update()
{
	ofPoint speed;
	if (mPressedUp)		speed += ofPoint(0.0,-maxSpeed,0.0);
	if (mPressedDown)	speed += ofPoint(0.0,+maxSpeed,0.0);
	if (mPressedLeft)	speed += ofPoint(-maxSpeed,0.0,0.0);
	if (mPressedRight)	speed += ofPoint(+maxSpeed,0.0,0.0);
	mPosition += speed;
}

void Player::draw()
{
	ofSetColor(255,255,255);
	ofNoFill();
	ofCircle(mPosition.x, mPosition.y, 10.0);
}
