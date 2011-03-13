#pragma once

#include "StateIdentifiers.h"

class State
{
public:
	State(){};
	virtual ~State(void){};

	virtual void initState() = 0;
	virtual void enterState() = 0;
	virtual void exitState() = 0;
	virtual int update() = 0;			// update game logic, change state if necessary
	virtual int getID() { return mID; };

protected:
	int mID;
};

