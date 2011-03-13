#include "StateCarrierApproach.h"

#include "..\EnemyCarrier.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateCarrierApproach::attackDistance = 100.0;
const float StateCarrierApproach::maxSpeed = 1.0;


void StateCarrierApproach::initState()
{
	mID = EnemyState::CARRIER_APPROACH;
	printf("Init Carrier Approach State\n");
}

void StateCarrierApproach::enterState()
{
	printf("Enter Carrier Approach State\n");
}

void StateCarrierApproach::exitState()
{
	printf("Exit Carrier Approach State\n");
}

int StateCarrierApproach::update()
{
	// distance check
	ofPoint distanceVector = mTarget->getPosition() - mOwnCarrier->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	// check for state change
	if(distance <= attackDistance)
		return EnemyState::CARRIER_ATTACK;
	else
	{
		// seek behavior as described by Craig W. Reynolds.
		ofPoint accelerationVector = (distanceVector/distance)*maxSpeed;
		accelerationVector -= mOwnCarrier->getSpeed();
		mOwnCarrier->accelerateWithVector(accelerationVector);
		mOwnCarrier->move();
		return mID;
	}
	
}