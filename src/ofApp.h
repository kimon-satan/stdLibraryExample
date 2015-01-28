#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void removeRandomItem();
        void sortByXAxis();
    
        string generateRandomString(int numChars);
    
        vector<ofRectangle> mRectangles; //vectors can contain any type of object
    
        map<string, ofRectangle> mTextAreas; //maps are just like objects in javascript and dictionaries in python

    
};
