#include "ofApp.h"


    


bool globalSortXFunction(ofRectangle a, ofRectangle b){ //this is our custom sort function
        return a.x < b.x;
}
    


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
    
    
    mFont.loadFont("256BYTES.TTF", 40);
    
    
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
        
        ofSetColor(255 * (float)i/mRectangles.size()); //gradually make the rectangles lighter
        
        ofRect(mRectangles[i]); //you might not be used to using ofRect in this way
                                //try cmd clicking on ofRect and looking at the source code to
                                // investigate other methods
    }
    
    
    //another way to traverse the vector is to use an iterator
    //these become increasingly useful as you get into c++
    
    ofSetColor(255, 0, 0, 50); // setting color to an opaque red so that you can see both sets drawn
    
    vector<ofRectangle>::iterator it; //declare the iterator type as vector<ofRectangle>
    it = mRectangles.begin(); //set it to the beginning of the vector
    
    while (it != mRectangles.end()) { // the end iterator is AFTER the final item
        
        ofRect(it->x, it->y, 20,20); //notice that 'it' is actually a pointer ... thats why we use -> instead of .
        
        it++; //increment the iterator just like you would an index integer
    }
    
    //TASK:
    //now create a vector of ofVec2fs
    //use an iterator to draw them in a for loop
    
    
    map<string, ofRectangle>::iterator it2 = mTextAreas.begin();
    
    while (it2 != mTextAreas.end()) { // we can increment through a map just like a vector
                                      // however maps are unordered we have no idea which order the elements will come out
        
        ofFill();

        ofSetColor(0,0, 200,150);
        ofRect(it2->second); // we need to use first to look up the key - in this case a string
                            //and second to look up the value - in this case a rectangle object
        
        ofSetColor(0, 255, 0);
        mFont.drawString(it2->first, it2->second.x, it2->second.y + it2->second.height);
        
        it2++;
    }
    

    
}

void ofApp::removeRandomItem(){
    
    int i = ofRandom(0, mRectangles.size() -1 ); //an index somewhere in the vector
    mRectangles.erase(mRectangles.begin() + i ); //turn it back into an iterator by adding it to .begin()
    
    //TASK:
    //look up erase at http://www.cplusplus.com/reference/vector/vector/erase/
    //work out how to delete multiple consecutive items at once without using any loops
    
}

void ofApp::sortByXAxis(){
    
    sort(mRectangles.begin(),mRectangles.end(), globalSortXFunction); // notice that I don't need to pass any parameters to globalSortXFunction
                                                                      // this is a function pointer ... like in javascript
    
    //TASK: make a sort by Y
    //use cplusplus.com to look up the shuffle method
    //you might want globalSortXFunction NOT to be global (either in a namespace or a static member function ... see if you can do this)
    
}

string ofApp::generateRandomString(int numChars){

    string t_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@$%^&*()";
    string randomString = "";
    
    for(int i = 0; i < numChars; i++){
        randomString += t_chars.substr(ofRandom(0, t_chars.length()-1), 1);
    }
    
    return randomString;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case OF_KEY_BACKSPACE:
            removeRandomItem();
            break;
        case ' ':
            sortByXAxis();
            break;
        default:
            break;
    }
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
    
    
    string s = generateRandomString(ofRandom(4,10));
    ofRectangle r = mFont.getStringBoundingBox(s, x, y);
    mTextAreas[s] = r;
    
    

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