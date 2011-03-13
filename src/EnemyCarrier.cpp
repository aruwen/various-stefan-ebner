#include "EnemyCarrier.h"

#include "EnemyFighter.h"
#include "state\StateCarrierApproach.h"
#include "state\StateCarrierApproachContact.h"
#include "state\StateCarrierAttack.h"
#include "state\StateCarrierSearch.h"


EnemyCarrier::EnemyCarrier(float xPosition, float yPosition, MovingObject *target):
	mTarget(target)
{	
	setId();
	mMaxSpeed = 2;
	mPosition = ofPoint(xPosition,yPosition,0.0);
	mSpeed = ofPoint(0.0,0.0,0.0);

	mFSM.addState(new StateCarrierApproach(this, target));
	mFSM.addState(new StateCarrierApproachContact(this, target));
	mFSM.addState(new StateCarrierAttack(this, target));
	mFSM.addState(new StateCarrierSearch(this, target));
	mFSM.setInitState(EnemyState::CARRIER_SEARCH);

}

EnemyCarrier::~EnemyCarrier(void)
{
}

bool EnemyCarrier::handleMessage(const Message& msg)
{
	switch (msg.mMessageType)
	{
	case MESSAGE_PLAYER_FOUND:

		mFSM.changeState(EnemyState::CARRIER_APPROACH_CONTACT);
		break;
	default:
		return false;
	}
	return true;
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


MovingObject *EnemyCarrier::getTarget()
{
	return mTarget;
}