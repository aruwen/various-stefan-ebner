#include "testApp.h"
#include "stdio.h"
#include "EnemyFighter.h"
#include "EnemyCarrier.h"
#include "MovingObject.h"


//--------------------------------------------------------------
testApp::testApp(){

}

//--------------------------------------------------------------
void testApp::setup(){
	int fighterAmount = 2;

	mPlayer = new Player(100,400);
	mObjectList.push_back(mPlayer);

	EnemyCarrier *carrier = new EnemyCarrier(400, 400, mPlayer);
	mObjectList.push_back(carrier);

	EnemyFighter *fighter;
	for (int i=0; i<fighterAmount; i++)
	{
		fighter = new EnemyFighter(500, 500+i*60, carrier);
		mObjectList.push_back(fighter);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	vector<MovingObject *>::iterator it;

	for (it=mObjectList.begin(); it < mObjectList.end(); it++ )
		(*it)->update();
}


//--------------------------------------------------------------
void testApp::draw(){

	vector<MovingObject *>::iterator it;

	for (it=mObjectList.begin(); it < mObjectList.end(); it++ )
		(*it)->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	switch (key)
	{
	case OF_KEY_UP:
		mPlayer->setPressedUp(true);
		break;
	case OF_KEY_DOWN:
		mPlayer->setPressedDown(true);
		break;
	case OF_KEY_LEFT:
		mPlayer->setPressedLeft(true);
		break;
	case OF_KEY_RIGHT:
		mPlayer->setPressedRight(true);
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	switch (key)
	{
	case OF_KEY_UP:
		mPlayer->setPressedUp(false);
		break;
	case OF_KEY_DOWN:
		mPlayer->setPressedDown(false);
		break;
	case OF_KEY_LEFT:
		mPlayer->setPressedLeft(false);
		break;
	case OF_KEY_RIGHT:
		mPlayer->setPressedRight(false);
		break;
	}
}

//--------------------------------------------------------------
void testApp::exit()
{
	while (!mObjectList.empty())
	{
		MovingObject *objectToDelete = mObjectList.back();
		mObjectList.pop_back();
		delete objectToDelete;
	}
}


//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}

