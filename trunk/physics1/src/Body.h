#ifndef BODY_H
#define BODY_H

#include "ofMain.h"


// this abstract is used by all bodies participating in the physical simulation
class Body {
public:
	ofPoint mPosition;
	ofPoint mVelocity;
	float	mMass;
	ofPoint mForce;

	Body();
	// we have to declare a virtual destructor
	virtual ~Body();

	// update the body with a simulation time step of dt
	virtual void update(float dt);
	// draw the body
	virtual void draw() = 0;
	//
	virtual void applyForce(ofPoint const &force);
};

#endif
