#include "StateCarrierSearch.h"

#include "..\EnemyCarrier.h"
#include "StateIdentifiers.h"
#include "..\Utility.h"

#include "ofTypes.h"

const float StateCarrierSearch::sensorRange = 150.0;

void StateCarrierSearch::initState()
{
	mID = EnemyState::CARRIER_SEARCH;
	printf("Init Carrier Search State\n");
}

void StateCarrierSearch::enterState()
{
	// let the carrier tell all the fighter-minions to attack!
	MD->broadcast(mOwnCarrier->getID(), MESSAGE_SEARCH_FOR_PLAYER, 1.0);
	printf("Enter Carrier Search State\n");
}

void StateCarrierSearch::exitState()
{
	// let the carrier tell all the fighter-minions to hurry back.
	MD->broadcast(mOwnCarrier->getID(), MESSAGE_RETURN_TO_CARRIER, 0.1);
	printf("Exit Carrier Search State\n");
}

int StateCarrierSearch::update()
{
	// wait right there
	mOwnCarrier->accelerateWithVector(-mOwnCarrier->getSpeed());
	mOwnCarrier->move();

	ofPoint vectorToPlayer = mTarget->getPosition() - mOwnCarrier->getPosition();
	if (getLength(vectorToPlayer) < sensorRange)
		return EnemyState::CARRIER_APPROACH;

	return mID;
}