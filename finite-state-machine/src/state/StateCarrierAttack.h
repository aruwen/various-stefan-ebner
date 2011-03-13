#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyCarrier;

class StateCarrierAttack: public State
{
public:
	StateCarrierAttack(EnemyCarrier *ownCarrier, MovingObject *target):mOwnCarrier(ownCarrier), mTarget(target) {initState();};
	~StateCarrierAttack(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float attackTerminationDistance;
private:
	EnemyCarrier *mOwnCarrier;
	MovingObject *mTarget;
	
};

