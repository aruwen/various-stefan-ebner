#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyCarrier;

class StateCarrierApproach: public State
{
public:
	StateCarrierApproach(EnemyCarrier *ownCarrier, MovingObject *target):mOwnCarrier(ownCarrier), mTarget(target) {initState();};
	~StateCarrierApproach(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float attackDistance;
private:
	EnemyCarrier *mOwnCarrier;
	MovingObject *mTarget;
	
};

