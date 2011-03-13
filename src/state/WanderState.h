#ifndef WANDER_STATE_H
#define WANDER_STATE_H

// should have used ofVector2D for all the vector math
// not wokring too good but atleast i got the idea and will likely
// implement in the future in some other program

#include "state.h"
// #include "Enemy.h"
// #include "Player.h
#include <limits>
#include "MovingEntity.h"

#define RANDOM_MAX 0x7fff

class Player;
class Enemy;

class WanderState : public State
{
public:
	WanderState(Enemy* enemy, Player* player): 
	  mEnemy(enemy),
	  mPlayer(player)
	  {
		  mWanderDistanceFromPlayer = 250.0;
		  initState();
		  mWanderJitter = 30.0;
		  mWanderDistance = 0.8;
		  mWanderRadius = 2.5;
		  theta = randomFloat() * PI *2;
		  //some point on a circle in front of the enemy
		  mWanderTarget = ofPoint(mWanderRadius * cos(theta), mWanderRadius * sin(theta), 0);
	  }
	~WanderState(void);

	void initState();
	void enterState();
	void exitState();
	int update();			// update game logic, change state if necessary
	int getID() { return mID; };

private:
	float mWanderDistanceFromPlayer;
	Enemy* mEnemy;
	Player* mPlayer;
	float theta;
	
	float mWanderRadius;
	float mWanderDistance;
	float mWanderJitter;
	ofPoint mWanderTarget;
	float randomFloat();
	float randomFloatClamped();
};


#endif