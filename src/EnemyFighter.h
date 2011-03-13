#pragma once

#include "MovingObject.h"
#include "messaging\BaseGameEntity.h"
#include "state\StateIdentifiers.h"
#include "state\FSM.h"

class EnemyCarrier;

class EnemyFighter: public MovingObject, public BaseGameEntity
{
public:
	EnemyFighter(float xPosition, float yPosition, EnemyCarrier *homeCarrier);
	~EnemyFighter(void);

	bool handleMessage(const Message& msg);

	void update();
	void draw();	

private:
	FSM mFSM;
};

