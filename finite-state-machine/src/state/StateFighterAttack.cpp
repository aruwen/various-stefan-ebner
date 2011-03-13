#include "StateFighterAttack.h"

#include "..\EnemyFighter.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateFighterAttack::maxSpeed = 2.0;
const float StateFighterAttack::attackRadius = 100.0;


void StateFighterAttack::initState()
{
	mID = EnemyState::FIGHTER_ATTACK;
	printf("Init Fighter Attack State\n");
}

void StateFighterAttack::enterState()
{
	printf("Enter Fighter Attack State\n");
}

void StateFighterAttack::exitState()
{
	printf("Exit Fighter Attack State\n");
}

int StateFighterAttack::update()
{
	if(!mOwnFighter->getAttacking())
		return EnemyState::FIGHTER_APPROACH_CARRIER;


	// distance check
	ofPoint distanceVector = mTarget->getPosition() - mOwnFighter->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	// check for state change
	if(distance > attackRadius)
		return EnemyState::FIGHTER_APPROACH_TARGET;
	else
	{
		// this acts like gravity towards the target
		ofPoint accelerationVector = (distanceVector/distance) * maxSpeed;
		mOwnFighter->accelerateWithVector(accelerationVector);
		mOwnFighter->move();
		return mID;
	}
	
}