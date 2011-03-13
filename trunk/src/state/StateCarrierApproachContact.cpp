#include "StateCarrierApproachContact.h"

#include "..\EnemyCarrier.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateCarrierApproachContact::attackDistance = 100.0;
const float StateCarrierApproachContact::sensorRange = 150.0;

void StateCarrierApproachContact::initState()
{
	mID = EnemyState::CARRIER_APPROACH_CONTACT;
	printf("Init Carrier Approach Contact State\n");
}

void StateCarrierApproachContact::enterState()
{
	printf("Enter Carrier Approach Contact State\n");
	mContactPosition = mTarget->getPosition();
}

void StateCarrierApproachContact::exitState()
{
	printf("Exit Carrier Approach Contact State\n");
}

int StateCarrierApproachContact::update()
{
	// distance check
	

	ofPoint realDistanceVector = mTarget->getPosition() - mOwnCarrier->getPosition();
	float realDistance = sqrt(	realDistanceVector.x * realDistanceVector.x +
								realDistanceVector.y * realDistanceVector.y);

	if (realDistance <= sensorRange)
		return EnemyState::CARRIER_APPROACH;
	else
	{
		ofPoint coontactDistanceVector = mContactPosition - mOwnCarrier->getPosition();
		float contactDistance = sqrt(	coontactDistanceVector.x * coontactDistanceVector.x +
										coontactDistanceVector.y * coontactDistanceVector.y);
		// check for state change
		if(contactDistance <= attackDistance)
			return EnemyState::CARRIER_SEARCH;
		else
		{
			// seek behavior as described by Craig W. Reynolds.
			ofPoint accelerationVector = (coontactDistanceVector/contactDistance)*mOwnCarrier->getMaxSpeed();
			accelerationVector -= mOwnCarrier->getSpeed();
			mOwnCarrier->accelerateWithVector(accelerationVector);
			mOwnCarrier->move();
			return mID;
		}

	}
	
}