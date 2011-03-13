#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include "Body.h"

#include <stdio.h>

using namespace std;

class ShipControls {
public:
	bool turnLeft, turnRight, thrust;

	ShipControls() {
		turnLeft = turnRight = thrust = false;
	}
};

class SpaceShip: public Body {
public:
	float heading;
	ShipControls *controls;

	SpaceShip(int r, int g, int b);
	virtual ~SpaceShip();

	virtual void update(float dt);
	virtual void draw();

private:
	int mR;
	int mG;
	int mB;
};

#endif
