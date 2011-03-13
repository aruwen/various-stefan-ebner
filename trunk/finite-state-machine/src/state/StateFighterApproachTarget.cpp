#include "StateFighterApproachTarget.h"

#include "..\EnemyFighter.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateFighterApproachTarget::maxSpeed = 5.0;
const float StateFighterApproachTarget::attackRadius = 100.0;


void StateFighterApproachTarget::initState()
{
	mID = EnemyState::FIGHTER_APPROACH_TARGET;
	printf("Init Fighter Approach Target State\n");
}

void StateFighterApproachTarget::enterState()
{
	printf("Enter Fighter Approach Target State\n");
}

void StateFighterApproachTarget::exitState()
{
	printf("Exit Fighter Approach Target State\n");
}

int StateFighterApproachTarget::update()
{
	if(!mOwnFighter->getAttacking())
		return EnemyState::FIGHTER_APPROACH_CARRIER;

	// distance check
	ofPoint distanceVector = mTarget->getPosition() - mOwnFighter->getPosition();
	float distance = sqrt(	distanceVector.x * distanceVector.x +
							distanceVector.y * distanceVector.y);

	// check for state change
	if(distance <= attackRadius)
		return EnemyState::FIGHTER_ATTACK;
	else
	{
		// seek behavior as described by Craig W. Reynolds.
		ofPoint accelerationVector = (distanceVector/distance) * maxSpeed;
		accelerationVector -= mOwnFighter->getSpeed();
		mOwnFighter->accelerateWithVector(accelerationVector);
		mOwnFighter->move();
		return mID;
	}
	
}