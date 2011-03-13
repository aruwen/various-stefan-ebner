#pragma once

#include "MovingObject.h"
#include "state\StateIdentifiers.h"
#include "state\FSM.h"

class EnemyCarrier;

class EnemyFighter: public MovingObject
{
public:
	EnemyFighter(float xPosition, float yPosition, EnemyCarrier *homeCarrier);
	~EnemyFighter(void);

	void update();
	void draw();
	
	void setAttacking(bool state);
	bool getAttacking();
	

private:
	bool mAttacking;
	FSM mFSM;
};

