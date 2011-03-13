#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "BaseGameEntity.h"
#include "BasicTimer.h"


MessageDispatcher::MessageDispatcher(void)
{
//	BaseGameEntity::resetNextUnusedId();
}

MessageDispatcher::~MessageDispatcher(void)
{
}

MessageDispatcher* MessageDispatcher::getInstance()
{
	static MessageDispatcher mInstance;
	return &mInstance;
}

void MessageDispatcher::addListener( BaseGameEntity* listener )
{
	mListeners.insert(listener);
}

void MessageDispatcher::removeListener( BaseGameEntity* listener )
{
	std::set<BaseGameEntity*>::iterator it;
	it = mListeners.find(listener);
	mListeners.erase(it);
}

void MessageDispatcher::send( Message msg )
{
	send(msg.mReceiver, msg.mSender, msg.mMessageType, msg.mDelay, msg.mExtra);
}

void MessageDispatcher::send( int receiver, int sender, MessageType messageType, double delay/*=0*/, void *extra/*=NULL*/ )
{
	BaseGameEntity* pSender = EM->getEntityFromID(sender);
	BaseGameEntity* pReceiver = EM->getEntityFromID(receiver);

	if (pReceiver == NULL)
	{
		return;
	}

	Message message(receiver, sender, messageType, delay, extra);

	if (delay <= 0.0)
	{
		dispatch(pReceiver, message);
	}
	else
	{
		double currentTime = TIMER->getCurrentTime();
		message.mDelay = delay + currentTime;
		mMessageQueue.insert(message);
	}
}

void MessageDispatcher::broadcast( Message msg )
{
	broadcast( msg.mSender, msg.mMessageType, msg.mDelay, msg.mExtra);
}

void MessageDispatcher::broadcast( int sender, MessageType messageType, double delay/*=0*/, void *extra/*=NULL*/ )
{
	BaseGameEntity* pSender = EM->getEntityFromID(sender);

	std::set<BaseGameEntity*>::iterator it = mListeners.begin();

	if (delay <= 0.0)
	{
		for ( ; it!=mListeners.end(); it++)
		{
			Message message((*it)->getID(), sender, messageType, delay, extra);
			dispatch((*it), message);
		}
	}
	else
	{
		for ( ; it!=mListeners.end(); it++)
		{
			double currentTime = TIMER->getCurrentTime();
			Message message((*it)->getID(), sender, messageType, delay, extra);
			message.mDelay = currentTime + delay;
			mMessageQueue.insert(message);
		}
	}
}


// dispatches all messages that have an delay and are ready to be sent
// has to be called every update cycle in the main function
void MessageDispatcher::update()
{
	double CurrentTime = TIMER->getCurrentTime();

	while( (!mMessageQueue.empty()) &&
		(mMessageQueue.begin()->mDelay < CurrentTime))
	{
		const Message& message = *mMessageQueue.begin();

		BaseGameEntity* pReceiver = EM->getEntityFromID(message.mReceiver);

		dispatch(pReceiver, message);

		mMessageQueue.erase(mMessageQueue.begin());
	}
}

void MessageDispatcher::dispatch( BaseGameEntity* pReceiver, Message msg )
{
	if(!pReceiver->handleMessage(msg))
	{
		printf("could not handle the message\n");
	}
}