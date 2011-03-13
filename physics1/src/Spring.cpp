#include "Spring.h"


Spring::Spring(void)
{
}


Spring::~Spring(void)
{
}

void Spring::update( float dt )
{
	ofPoint radius = mTo->mPosition - mFrom->mPosition;
	float l = sqrt(radius.x * radius.x + radius.y * radius.y);

	float displacement = l - mNormalLength;
	// elastisches seil, also keine stauchungen
	if(displacement < 0.0f) return;

	float forceMagnitude = -mStrength * displacement;

	mTo->applyForce(radius/l * forceMagnitude);
	mFrom->applyForce(-radius/l * forceMagnitude);
}

void Spring::draw()
{
	ofSetColor(0);
	ofLine( mFrom->mPosition.x, mFrom->mPosition.y,
			mTo->mPosition.x, mTo->mPosition.y);
}


