#include "StateCarrierAttack.h"

#include "..\EnemyCarrier.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateCarrierAttack::attackTerminationDistance = 150.0;

void StateCarrierAttack::initState()
{
	mID = EnemyState::CARRIER_ATTACK;
	printf("Init Carrier Attack State\n");
}

void StateCarrierAttack::enterState()
{
	// let the carrier tell all the fighter-minions to attack!
	mOwnCarrier->setFightersAttackState(true);
	printf("Enter Carrier Attack State\n");
}

void StateCarrierAttack::exitState()
{
	// let the carrier tell all the fighter-minions to hurry back.
	mOwnCarrier->setFightersAttackState(false);
	printf("Exit Carrier Attack State\n");
}

int StateCarrierAttack::update()
{
	// distance check
	ofPoint distanceVector = mTarget->getPosition() - mOwnCarrier->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	// check for state change
	if(distance >= attackTerminationDistance)
		return EnemyState::CARRIER_APPROACH;

	return mID;
}