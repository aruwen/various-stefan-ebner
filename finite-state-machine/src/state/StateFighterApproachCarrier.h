#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyFighter;

class StateFighterApproachCarrier: public State
{
public:
	StateFighterApproachCarrier(EnemyFighter *ownFighter, MovingObject *targetCarrier):
			mOwnFighter(ownFighter), mTargetCarrier(targetCarrier) 
			{initState();};
	~StateFighterApproachCarrier(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float maxSpeed;
	static const float approachEndRadius;
private:
	EnemyFighter *mOwnFighter;
	MovingObject *mTargetCarrier;
	
};

ofPoint getProjectionVector(ofPoint u, ofPoint v); //projects v on u

ofPoint makeLeftNormalVector(ofPoint u);

float dot(ofPoint u, ofPoint v);

float getLength(ofPoint u);


