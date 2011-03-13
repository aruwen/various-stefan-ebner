#include "StateCarrierAttack.h"

#include "..\EnemyCarrier.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateCarrierAttack::attackTerminationDistance = 150.0;

void StateCarrierAttack::initState()
{
	mID = EnemyState::CARRIER_ATTACK;
	printf("Init Carrier Search State\n");
}

void StateCarrierAttack::enterState()
{
	// let the carrier tell all the fighter-minions to search the player!
//	mOwnCarrier->setFightersAttackState(true);
	MD->broadcast(mOwnCarrier->getID(), MESSAGE_ATTACK_PLAYER, 0.1);
	printf("Enter Carrier Search State\n");
}

void StateCarrierAttack::exitState()
{
	// let the carrier tell all the fighter-minions to hurry back.
//	mOwnCarrier->setFightersAttackState(false);
	MD->broadcast(mOwnCarrier->getID(), MESSAGE_RETURN_TO_CARRIER, 0.5);
	printf("Exit Carrier Search State\n");
}

int StateCarrierAttack::update()
{
	// wait right there
	mOwnCarrier->accelerateWithVector(-mOwnCarrier->getSpeed());
	mOwnCarrier->move();

	// distance check
	ofPoint distanceVector = mTarget->getPosition() - mOwnCarrier->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	// check for state change
	if(distance >= attackTerminationDistance)
		return EnemyState::CARRIER_SEARCH;

	return mID;
}