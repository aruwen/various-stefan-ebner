#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyCarrier;

class StateCarrierSearch: public State
{
public:
	StateCarrierSearch(EnemyCarrier *ownCarrier, MovingObject *target):mOwnCarrier(ownCarrier), mTarget(target){initState();};
	~StateCarrierSearch(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float sensorRange;

private:
	EnemyCarrier *mOwnCarrier;
	MovingObject *mTarget;
	
};

