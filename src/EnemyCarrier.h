#pragma once

#include "MovingObject.h"
#include "messaging\BaseGameEntity.h"
#include "state\StateIdentifiers.h"
#include "state\FSM.h"

class EnemyFighter;

class EnemyCarrier: public MovingObject, public BaseGameEntity
{
public:
	EnemyCarrier(float xPosition, float yPosition, MovingObject *target);
	~EnemyCarrier(void);

	bool handleMessage(const Message& msg);

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

