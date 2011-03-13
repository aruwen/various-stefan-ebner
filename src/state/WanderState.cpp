#include "WanderState.h"
#include "Player.h"
#include "Enemy.h"


WanderState::~WanderState(void)
{
}

void WanderState::initState()
{
	mID = EnemyState::WANDER;
}

void WanderState::enterState()
{
	printf("lets Wander\n");
}

void WanderState::exitState()
{
	printf("enough! wandering around\n");
}

int WanderState::update()			
{
	// projecting a circle infront of the enemy and getting a random point on that circle
	// the target position then is set to that point on the circle
	float distanceToPlayer = mEnemy->getDistanceToPlayer();

	if (distanceToPlayer > mWanderDistanceFromPlayer)
	{
		// using time independent framerate -> 
		float jitterTimeAdjusted = mWanderJitter * mEnemy->getTimeElapsed();

		//randomize the target vector
		mWanderTarget+=ofPoint(randomFloatClamped() * jitterTimeAdjusted, randomFloatClamped() * jitterTimeAdjusted, 0);
		
		//normalize that vector and prevent division by zero
		float targetLength = sqrt(mWanderTarget.x*mWanderTarget.x + mWanderTarget.y*mWanderTarget.y);
		if (targetLength > std::numeric_limits<float>::epsilon())
		{
			mWanderTarget.x /= targetLength;
			mWanderTarget.y /= targetLength;
		}

		// increase length of the target vector by the radius
		mWanderTarget *= mWanderRadius;

		// now move the target into a position in front of the target
		mWanderTarget += ofPoint(mWanderDistance*(float)mEnemy->getVelocity().x, (float)mWanderDistance*mEnemy->getVelocity().y, 0);
		
		mEnemy->moveEnemy(mWanderTarget);
		
		return EnemyState::WANDER;
	} 
	else if (distanceToPlayer < mWanderDistanceFromPlayer)
	{
		return EnemyState::SEEK;
	}
 	else // just in case something unplanned happens
 	{
 		return EnemyState::FLEE;
 	}
	
}

float WanderState::randomFloat()
{
	return ((rand()) / (RANDOM_MAX+1.0));
}

float WanderState::randomFloatClamped()
{
	//-1 to +1
	return randomFloat() - randomFloat();
}	
