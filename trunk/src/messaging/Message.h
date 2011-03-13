#ifndef MESSAGE_H
#define MESSAGE_H

#include <cmath>
#include <iostream>
#include "MessageTypes.h"

struct Message
{
	int mReceiver;
	int mSender;
	MessageType mMessageType;
	double mDelay;
	void* mExtra;

	Message():
		mReceiver(-1),
		mSender(-1)
		{	}

	Message(int receiver, int sender, MessageType messageType, double delay, void* info = NULL):
		mReceiver(receiver),
		mSender(sender),
		mMessageType(messageType),
		mDelay(delay),
		mExtra(info)
		{	}
	
};


#endif