#ifndef BASE_GAME_ENTITY_H
#define BASE_GAME_ENTITY_H

#include "Message.h"

class BaseGameEntity
{
public:

	static int nextUnusedId;

//	static void resetNextUnusedId() {nextUnusedId = 1;}

	virtual ~BaseGameEntity(void) {}
	virtual bool handleMessage(const Message& msg) = 0;
	int getID()const {return mId;}
	void setId() {mId = nextUnusedId; nextUnusedId++;}

private:
	int mId;
};


#endif BASE_GAME_ENTITY_H