#include "EnemyFighter.h"

#include "EnemyCarrier.h"
#include "state\StateFighterWander.h"
#include "state\StateFighterApproachCarrier.h"
#include "state\StateFighterApproachTarget.h"
#include "state\StateFighterAttack.h"

EnemyFighter::EnemyFighter(float xPosition, float yPosition, EnemyCarrier *homeCarrier)
{	
	setId();
	mMaxSpeed = 5;
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);
	homeCarrier->registerFighter(this);
	MovingObject *target = homeCarrier->getTarget();

	mFSM.addState(new StateFighterWander(this, homeCarrier, target));
	mFSM.addState(new StateFighterApproachCarrier(this,homeCarrier));
	mFSM.addState(new StateFighterApproachTarget(this,target));
	mFSM.addState(new StateFighterAttack(this,target));
	mFSM.setInitState(EnemyState::FIGHTER_APPROACH_CARRIER);
}

EnemyFighter::~EnemyFighter(void)
{
}

bool EnemyFighter::handleMessage(const Message& msg)
{
	switch (msg.mMessageType)
	{
	case MESSAGE_RETURN_TO_CARRIER:
		mFSM.changeState(EnemyState::FIGHTER_APPROACH_CARRIER);
		break;
	case MESSAGE_ATTACK_PLAYER:
		mFSM.changeState(EnemyState::FIGHTER_ATTACK);
		break;
	case MESSAGE_SEARCH_FOR_PLAYER:
		mFSM.changeState(EnemyState::FIGHTER_WANDER);
		break;
	default:
		return false;
	}
	return true;
}

void EnemyFighter::update()
{
	mFSM.update();
}

void EnemyFighter::draw()
{
	ofSetColor(0,0,0);
	ofFill();
	ofCircle(mPosition.x, mPosition.y, 5.0);
}



