#include "StateFighterWander.h"


#include "..\EnemyFighter.h"
#include "StateIdentifiers.h"

#include "ofTypes.h"

const float StateFighterWander::wanderEndRadius = 50.0f;
const float StateFighterWander::wanderJitterSize = 0.01f;
const float StateFighterWander::wanderDistance = 0.8f;
const float StateFighterWander::wanderRadius = 5.0f;


void StateFighterWander::initState()
{
	mID = EnemyState::FIGHTER_WANDER;
	printf("Init Fighter Wander State\n");
}

void StateFighterWander::enterState()
{
	printf("Enter Fighter Wander State\n");
}

void StateFighterWander::exitState()
{
	printf("Exit Fighter Wander State\n");
}





int StateFighterWander::update()
{
	// projecting a circle infront of the enemy and getting a random point on that circle
	// the target position then is set to that point on the circle

	float distanceToPlayer = getLength(mTargetPlayer->getPosition() - mOwnFighter->getPosition());

	if (distanceToPlayer > wanderEndRadius)
	{
		mWanderAngle += (randomRadian() - (float)UTILITY_PI) * wanderJitterSize;

		ofPoint wanderVector = mOwnFighter->getSpeed() + (ofPoint(cos(mWanderAngle), sin(mWanderAngle)) * wanderRadius);
		float wanderDistance = getLength(wanderVector);

		ofPoint accelerationVector = (wanderVector/wanderDistance) * mOwnFighter->getMaxSpeed();
		accelerationVector -= mOwnFighter->getSpeed();
		mOwnFighter->accelerateWithVector(accelerationVector);
		mOwnFighter->move();
		
	} 
	else  
	{
		// notyfy carryer that the player has been found
		MD->send(mOwnCarrier->getID(), mOwnFighter->getID(), MESSAGE_PLAYER_FOUND, 0.0);
		mOwnFighter->accelerateWithVector(-mOwnFighter->getSpeed());
		mOwnFighter->move();
		
	}
	return mID;
	
}

/*

ofPoint getProjectionVector(ofPoint u, ofPoint v)
{
	ofPoint w;
	w = u * (dot(u,v)/dot(u,u));
	return w;
}

ofPoint makeLeftNormalVector(ofPoint u)
{
	ofPoint v;
	v.x = -u.y;
	v.y = u.x;
	return v;
}

float dot(ofPoint u, ofPoint v)
{
	return u.x*v.x + u.y*v.y + u.z*v.z;
}

float getLength(ofPoint u)
{
	return sqrt(dot(u,u));
}

*/