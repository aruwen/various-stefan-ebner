#include "EnemyFighter.h"

#include "EnemyCarrier.h"
#include "state\StateFighterApproachCarrier.h"
#include "state\StateFighterApproachTarget.h"
#include "state\StateFighterAttack.h"

EnemyFighter::EnemyFighter(float xPosition, float yPosition, EnemyCarrier *homeCarrier)
{	
	mAttacking = false;
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);
	homeCarrier->registerFighter(this);
	MovingObject *target = homeCarrier->getTarget();

	mFSM.addState(new StateFighterApproachCarrier(this,homeCarrier));
	mFSM.addState(new StateFighterApproachTarget(this,target));
	mFSM.addState(new StateFighterAttack(this,target));
	mFSM.setInitState(EnemyState::FIGHTER_APPROACH_CARRIER);
}

EnemyFighter::~EnemyFighter(void)
{
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


void EnemyFighter::setAttacking(bool state)
{
	mAttacking = state;
}
bool EnemyFighter::getAttacking()
{
	return mAttacking;
}

