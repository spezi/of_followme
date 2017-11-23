#include "ofApp.h"
void ofApp::setup(){
    
    
    
	camWidth = 1280;  // try to grab at this size.
	camHeight = 720;
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);
	ofSetVerticalSync(true);
	
	nDelayFrames = 100; //Set buffer size
	buffer.setup(nDelayFrames);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofBackground(0, 0, 0);
    
	vidGrabber.update();
	
	if(vidGrabber.isFrameNew()){
		buffer.pushPixels(vidGrabber.getPixels());
	}
	
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    auto rect = ofGetCurrentViewport();
    
    vidGrabber.draw(rect);
    
    //Controlling the framerate with the mouse:
    //int ind = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, nDelayFrames-1, true);
    
    //Speed of the Animation (aka Framerate)
    int ind = nDelayFrames;
    
    //ofDrawBitmapStringHighlight(ofToString(ind), 20, camHeight+40);
    
    //Storage of frames to play ( in dependence to the buffersize)
    
    ofTexture tex;
    
    //Feeding the Instances with Data
    
    
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    //ofSetHexColor(0xffffff);
    
    
    for( int a = 1; a < nDelayFrames  ; a = a + 10 ) {
        
        ofSetColor(255, 255, 255, 128 );
        //cout << "value of a: " << a << endl;
        //tex.loadData(buffer.getDelayedPixels(ind - 5));
        tex.loadData(buffer.getDelayedPixels(ind - a));
        //tex.draw(0, 0, 1024, 768);
        tex.draw(rect);
    }
    
    //Actual playing step by step
    
    

    
    
    
        ofDisableBlendMode();
    
   
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}