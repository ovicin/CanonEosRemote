#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofAddListener(wrapper.onFileAdded, this, &testApp::onFileAdded);
    wrapper.start();
    ofSetFullscreen(TRUE);
}

void testApp::onFileAdded(string &fileName){
    lastImage.loadImage(fileName);
    cout << ofGetWidth();
    cout << (lastImage.height * ofGetWidth())/lastImage.width;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    if(lastImage.isAllocated()){
        
        lastImage.resize(ofGetHeight()*lastImage.width/lastImage.height, ofGetHeight());
        int offset = (ofGetWidth()-(ofGetHeight()*lastImage.width/lastImage.height))/2;
        lastImage.draw(offset, 0);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(' ' == key){
        if(!wrapper.isStarted()){
            wrapper.start(); //restart if camera was disconnected
        }
        wrapper.takePicture();
    }
    else if ('f' == key){
        ofSetFullscreen(TRUE);
    }
    else if ('m' == key){
        ofSetFullscreen(FALSE);
    }
    else if (264 == key){ /* original F8 presser implementation */
        if(!wrapper.isStarted()){
            wrapper.start(); //restart if camera was disconnected
        }
        wrapper.takePicture();

    }
}