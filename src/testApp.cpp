#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofAddListener(wrapper.onFileAdded, this, &testApp::onFileAdded);
    wrapper.start();
    fullscreen = TRUE;
    ofSetFullscreen(fullscreen);
    
}


void testApp::onFileAdded(string &fileName){
    
    lastImage.loadImage(fileName);
    /* rename now the file */
    ofFile file(fileName);
    string dateFileName;
    dateFileName.append(ofToString(ofGetYear()));
    dateFileName.append(ofToString(ofGetMonth()));
    dateFileName.append(ofToString(ofGetDay()));
    dateFileName.append(ofToString(ofGetHours()));
    dateFileName.append(ofToString(ofGetMinutes()));
    dateFileName.append(ofToString(ofGetSeconds()));
    dateFileName.append(".jpg");
    cout << dateFileName;
    file.renameTo(dateFileName);
    file.close();

    
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
        fullscreen = !fullscreen;
        ofSetFullscreen(fullscreen);
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

void testApp::mousePressed(int x, int y, int button){
    if (2 == button ){
        fullscreen = !fullscreen;
        ofSetFullscreen(fullscreen);
    }

}
