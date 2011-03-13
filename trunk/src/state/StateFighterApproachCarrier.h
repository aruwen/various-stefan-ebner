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

	static const float approachEndRadius;
private:
	EnemyFighter *mOwnFighter;
	MovingObject *mTargetCarrier;
	
};



