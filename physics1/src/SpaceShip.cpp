#include "SpaceShip.h"

SpaceShip::SpaceShip(int r, int g, int b): Body() {
	heading = PI / 2;
	this->mR = r;
	this->mG = g;
	this->mB = b;
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::update(float dt) {
	if (controls->turnLeft) heading += 0.04;
	if (controls->turnRight) heading -= 0.04;

	float thrustMagnitude = controls->thrust ? 1.0f : 0.0f;

	applyForce(ofPoint(cos(heading), sin(heading)) * thrustMagnitude);
	applyForce(ofPoint(0.0f, -0.4f));

	
	Body::update(dt);
}

void SpaceShip::draw() {
	// draw a simple triangle as our spaceship
	ofPushMatrix();
	ofTranslate(mPosition.x, mPosition.y, 0);
	ofRotateZ(heading / PI * 180);
	ofFill();
	ofSetColor(mR,mG,mB);
	ofBeginShape();
		ofVertex(2, 0);
		ofVertex(-1,-1);
		ofVertex(-1,+1);
	ofEndShape();
	ofPopMatrix();
}
