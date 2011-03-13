#pragma once
#include "Message.h"
#include <set>
#include <cmath>

#include "MessageTypes.h"

#define MD MessageDispatcher::getInstance()

class BaseGameEntity;

struct compareStr 
{
	bool operator()(Message m1, Message m2) const
	{
		float variance = 0.0002f;
	
		if (m1.mSender == m2.mSender && m1.mMessageType == m2.mMessageType && m1.mReceiver == m2.mReceiver &&
			fabs(m1.mDelay - m2.mDelay) < variance)
		{
			return false;
		}
		else return (m1.mDelay<m2.mDelay);
	}
};

class MessageDispatcher
{
public:
	static MessageDispatcher* getInstance();
	void addListener(BaseGameEntity* listener);
	void removeListener(BaseGameEntity* listener);
	void send(Message msg);
	void send(int receiver, int sender, MessageType messageType, double delay=0, void *extra=NULL);
	void broadcast(Message msg);
	void broadcast(int sender, MessageType messageType, double delay=0, void *extra=NULL);
	void update();

private:
	MessageDispatcher(void);
	~MessageDispatcher();
	MessageDispatcher& operator=(const MessageDispatcher&);
	void dispatch(BaseGameEntity* pReceiver, Message msg);

	std::set<BaseGameEntity*> mListeners;
	std::set<Message, compareStr> mMessageQueue;
	
};
