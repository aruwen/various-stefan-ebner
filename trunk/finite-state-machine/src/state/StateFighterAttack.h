#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyFighter;

class StateFighterAttack: public State
{
public:
	StateFighterAttack(EnemyFighter *ownFighter, MovingObject *target):mOwnFighter(ownFighter), mTarget(target) {initState();};
	~StateFighterAttack(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float maxSpeed;
	static const float attackRadius;
private:
	EnemyFighter *mOwnFighter;
	MovingObject *mTarget;
	
};

