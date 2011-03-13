#include "Body.h"
#include "Simulation.h"

Body::Body(): mPosition(0.0f, 0.0f), mVelocity(0.0f, 0.0f), mMass(1.0f) {

}

Body::~Body() {
}

void Body::update(float dt) 
{
	//get total applied force
	ofPoint acceleration = mForce/mMass;
	//reset for next frame
	mForce = ofPoint(0.0f, 0.0f, 0.0f);

	mVelocity = mVelocity + acceleration * dt;
	//starting with the plus ==> quadratic integrator
	mPosition += mVelocity * dt + acceleration * 0.5f * dt * dt;
	
	//printf("velocity %f time %f\n", velocity, dt);
	if(mPosition.y < -Simulation::universeSize * 0.5f) mVelocity.y =  fabs(mVelocity.y);
	if(mPosition.x < -Simulation::universeSize * 0.5f) mVelocity.x =  fabs(mVelocity.x);
	if(mPosition.y > +Simulation::universeSize * 0.5f) mVelocity.y = -fabs(mVelocity.y);
	if(mPosition.x > +Simulation::universeSize * 0.5f) mVelocity.x = -fabs(mVelocity.x);
}

void Body::applyForce(ofPoint const &force)
{
	this->mForce += force;
}
