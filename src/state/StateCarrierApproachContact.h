#pragma once
#include "State.h"
#include "..\MovingObject.h"


class EnemyCarrier;

class StateCarrierApproachContact: public State
{
public:
	StateCarrierApproachContact(EnemyCarrier *ownCarrier, MovingObject *target):mOwnCarrier(ownCarrier), mTarget(target) {initState();};
	~StateCarrierApproachContact(){};

	virtual void initState();
	virtual void enterState();
	virtual void exitState();
	virtual int update();			// update game logic

	static const float attackDistance;
	static const float sensorRange;
private:
	ofPoint mContactPosition;
	EnemyCarrier *mOwnCarrier;
	MovingObject *mTarget;
	
};

