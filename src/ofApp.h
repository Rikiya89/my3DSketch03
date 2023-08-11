#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        const int NUM_SPHERES = 100;
        vector<ofVec3f> positions;
        vector<ofVec3f> velocities; // For sphere movement
        vector<float> radii;
        vector<ofColor> colors;
        vector<float> originalRadii;
        float scale = 1.0;
        ofVec3f mousePos3D; // 3D position estimate for mouse
        bool mouseIsPressed = false;
        ofLight light; // Light source
};
