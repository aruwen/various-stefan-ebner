#include "EnemyCarrier.h"

#include "EnemyFighter.h"
#include "state\StateCarrierApproach.h"
#include "state\StateCarrierAttack.h"

EnemyCarrier::EnemyCarrier(float xPosition, float yPosition, MovingObject *target):
	mTarget(target)
{	
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);

	mFSM.addState(new StateCarrierApproach(this,target));
	mFSM.addState(new StateCarrierAttack(this,target));
	mFSM.setInitState(EnemyState::CARRIER_APPROACH);
}

EnemyCarrier::~EnemyCarrier(void)
{
}

void EnemyCarrier::update()
{
	mFSM.update();
}

void EnemyCarrier::draw()
{
	ofSetColor(0,0,0);
	ofFill();
	ofCircle(mPosition.x, mPosition.y, 15.0);
}

void EnemyCarrier::registerFighter(EnemyFighter *fighter)
{
	mFighterList.push_back(fighter);
}

void EnemyCarrier::setFightersAttackState(bool state)
{
	vector<EnemyFighter *>::iterator it;
	for (it=mFighterList.begin(); it < mFighterList.end(); it++ )
		(*it)->setAttacking(state);
}



MovingObject *EnemyCarrier::getTarget()
{
	return mTarget;
}