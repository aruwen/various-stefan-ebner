#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyFighter;

class StateFighterApproachTarget: public State
{
public:
	StateFighterApproachTarget(EnemyFighter *ownFighter, MovingObject *target):mOwnFighter(ownFighter), mTarget(target) {initState();};
	~StateFighterApproachTarget(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float attackRadius;
private:
	EnemyFighter *mOwnFighter;
	MovingObject *mTarget;
	
};

