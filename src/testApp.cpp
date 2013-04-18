#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(30);
//    builder = new Builder(3, 3, 3);
    level = new Level();
}

//--------------------------------------------------------------
void testApp::update(){
    level->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    
    level->draw();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    level->emitSignal();

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

//    delete builder;
//    builder = new Builder(3, rand()%10, 3 );
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
