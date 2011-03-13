#include "StateFighterApproachCarrier.h"

#include "..\Utility.h"
#include "..\EnemyFighter.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateFighterApproachCarrier::approachEndRadius = 50.0;


void StateFighterApproachCarrier::initState()
{
	mID = EnemyState::FIGHTER_APPROACH_CARRIER;
	printf("Init Fighter Approach Carrier State\n");
}

void StateFighterApproachCarrier::enterState()
{
	printf("Enter Fighter Approach Carrier State\n");
}

void StateFighterApproachCarrier::exitState()
{
	printf("Exit Fighter Approach Carrier State\n");
}





int StateFighterApproachCarrier::update()
{
	// handle the approach - this is a form of "Offset pursuit" described by Craig W. Reynolds in 
	// "Steering Behaviors For Autonomous Characters".
	// In this case it could rather be described as "Offset seeking".
	ofPoint objectToTargetVector = mTargetCarrier->getPosition() - mOwnFighter->getPosition();
	ofPoint speedVector = mOwnFighter->getSpeed();
	if (speedVector.x == 0 && speedVector.y == 0)
		speedVector = ofPoint(1,1,0);
	
	ofPoint normalizedObjectToTargetVector = objectToTargetVector * getLength(objectToTargetVector);

	// added these two lines of code to make the fighter circle around the target.
	if (getLength(objectToTargetVector) <60)
		speedVector += normalizedObjectToTargetVector * 0.01;

	ofPoint speedNormalVector = makeLeftNormalVector(speedVector);
	
	ofPoint targetOffsetVector = getProjectionVector(speedNormalVector, objectToTargetVector);
	ofPoint pointToReach = mTargetCarrier->getPosition();
	pointToReach += targetOffsetVector / getLength(targetOffsetVector) * -approachEndRadius;


	ofPoint distanceVector = pointToReach - mOwnFighter->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	ofPoint accelerationVector = (distanceVector/distance) * mOwnFighter->getMaxSpeed();
	accelerationVector -= mOwnFighter->getSpeed();
	mOwnFighter->accelerateWithVector(accelerationVector);
	mOwnFighter->move();

	return mID;
	
}


