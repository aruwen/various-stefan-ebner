#pragma once

#include "MovingObject.h"
#include "state\StateIdentifiers.h"
#include "state\FSM.h"

class EnemyFighter;

class EnemyCarrier: public MovingObject
{
public:
	EnemyCarrier(float xPosition, float yPosition, MovingObject *target);
	~EnemyCarrier(void);

	void update();
	void draw();

	void registerFighter(EnemyFighter *fighter);
	void setFightersAttackState(bool state);
	MovingObject *getTarget();

private:
	MovingObject *mTarget;
	vector<EnemyFighter *> mFighterList;
	FSM mFSM;
};

