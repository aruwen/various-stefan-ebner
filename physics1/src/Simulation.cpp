#include "Simulation.h"

void Simulation::setup() {
	universeSize = 30.0;
	
	time = ofGetElapsedTimef();

	spaceShip = new SpaceShip(0, 128, 255);
	spaceShip->mPosition = ofPoint(1.0f, 0.0f);
	spaceShip->controls = &mCursorShipControls;

	spaceShip2 = new SpaceShip(128, 255, 0);
	spaceShip2->mPosition = ofPoint(-1.0f, 0.0f);
	spaceShip2->controls = &mWasdShipControls;

	mSpring.mFrom = spaceShip;
	mSpring.mTo = spaceShip2;
	mSpring.mNormalLength = 7.0f;
	mSpring.mStrength = 5.0f;


	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	Sleep(100);
}

void Simulation::update() {

	float t = ofGetElapsedTimef();
	float dt = t - time;
	spaceShip->update(dt);
	spaceShip2->update(dt);
	mSpring.update(dt);
	time = t;
}

void Simulation::draw() {
	// setup a top view for the physical universe
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	ofScale(ofGetWidth() / universeSize, -ofGetWidth() / universeSize, 1);

	// draw its only content
	spaceShip->draw();
	spaceShip2->draw();
	mSpring.draw();
}

void Simulation::handleKey(int key, bool value) {
	// handle the cursor ship controls
	switch (key) {
		case OF_KEY_LEFT:
			mCursorShipControls.turnLeft = value; break;
		case OF_KEY_RIGHT:
			mCursorShipControls.turnRight = value; break;
		case OF_KEY_UP:
			mCursorShipControls.thrust = value; break;

		case 'a':
			mWasdShipControls.turnLeft = value; break;
		case 'd':
			mWasdShipControls.turnRight = value; break;
		case 'w':
			mWasdShipControls.thrust = value; break;
	}
}

void Simulation::keyPressed(int key) {
	handleKey(key, true);
}

void Simulation::keyReleased(int key) {
	handleKey(key, false);
}

float Simulation::universeSize;