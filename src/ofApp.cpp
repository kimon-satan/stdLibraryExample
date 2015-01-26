#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

    
    //lets fill up the vector with Rectangle objects
    //find out more about ofRectangle here ...
    // http://openframeworks.cc/documentation/types/ofRectangle.html
    
    for(int i = 0; i < 1000; i++){
        mRectangles.push_back(
                              ofRectangle(
                                          ofRandom(0,ofGetWidth()), //randomize position
                                          ofRandom(0,ofGetHeight()),
                                          10,  //size stays the same
                                          10
                                          )
                              );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    ofSetColor(255);
    ofFill();
    
    //this is the old way to traverse the vector
    
    for(int i = 0; i < mRectangles.size(); i++)
    {
        ofRect(mRectangles[i]); //you might not be used to using ofRect in this way
                                //try cmd clicking on ofRect and looking at the source code to
                                // investigate other methods
    }
    
    
    //another way to traverse the vector is to use an iterator
    //these become increasingly useful as you get into c++
    
    ofSetColor(255, 0, 0, 50); // setting color to an opaque red so that you can see both sets drawn
    
    vector<ofRectangle>::iterator it; //declare the iterator type as vector<ofRectangle>
    it = mRectangles.begin(); //set it to the beginning of the vector
    
    while (it != mRectangles.end()) {
        
        ofRect(it->x, it->y, 20,20); //notice that 'it' is actually a pointer ... thats why we use -> instead of .
        
        it++; //increment the iterator just like you would an index integer
    }
    

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}