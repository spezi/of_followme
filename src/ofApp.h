#pragma once
#include "ofMain.h"

class circularPixelBuffer{
public:
    
    
    
	circularPixelBuffer(){
		currentIndex = 0;
	}
	void setup(int numFrames){
		frames.resize(numFrames);
		currentIndex = numFrames -1;
	}
	void pushPixels(ofPixels& pix){
		currentIndex--;
		if (currentIndex < 0) {
			currentIndex = frames.size() -1;
		}
		frames[currentIndex] = pix;
	}
    
	
	ofPixels& getDelayedPixels(size_t delay){
		if(delay < frames.size()){
			return frames[ofWrap(delay + currentIndex, 0, frames.size())];
		}
		return frames[0];
	}
	
public:
	int currentIndex;
	vector<ofPixels> frames;
};
class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	ofVideoGrabber vidGrabber;
	int camWidth;
	int camHeight;
	
    void keyPressed(int key);
    
	int nDelayFrames;
	
	circularPixelBuffer buffer;
    ofBlendMode blendMode;
    ofImage framesHV;
    
 
};