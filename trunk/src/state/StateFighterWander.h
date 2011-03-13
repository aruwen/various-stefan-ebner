#pragma once
#include "State.h"

#include "..\MovingObject.h"
#include "..\Utility.h"
#include "..\EnemyCarrier.h"

class EnemyFighter;

class StateFighterWander: public State
{
public:
	StateFighterWander(EnemyFighter *ownFighter, EnemyCarrier *ownCarrier, MovingObject *targetPlayer):
			mOwnFighter(ownFighter), mOwnCarrier(ownCarrier), mTargetPlayer(targetPlayer), mWanderAngle(randomRadian())
			{initState();};
	~StateFighterWander(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float wanderEndRadius;
	static const float wanderJitterSize;
	static const float wanderDistance;
	static const float wanderRadius;

private:
	EnemyFighter *mOwnFighter;
	EnemyCarrier *mOwnCarrier;
	MovingObject *mTargetPlayer;
	float mWanderAngle;
	
};

/*

ofPoint getProjectionVector(ofPoint u, ofPoint v); //projects v on u

ofPoint makeLeftNormalVector(ofPoint u);

float dot(ofPoint u, ofPoint v);

float getLength(ofPoint u);
*/

