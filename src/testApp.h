#pragma once

#include "ofMain.h"
#include "CanonSDKWrapper.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
        void mousePressed(int x, int y, int button);

    
    private:
        CanonSDKWrapper wrapper;
        void onFileAdded(string &fileName);
        ofImage lastImage;
    
        bool fullscreen;
};
