#ifndef SIMULATION_H
#define SIMULATION_H

#include "ofMain.h"
#include "SpaceShip.h"
#include "Spring.h"

class Simulation: public ofBaseApp {
public:	
	static float universeSize;
	float time;
	SpaceShip* spaceShip;
	SpaceShip* spaceShip2;
	Spring mSpring;
	ShipControls mCursorShipControls;
	ShipControls mWasdShipControls;

	void setup();
	void update();

	void draw();
	void handleKey(int key, bool value);
	void keyPressed(int key);
	void keyReleased(int key);
};

#endif
