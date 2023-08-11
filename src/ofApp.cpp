#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    ofEnableDepthTest();

    light.enable();
        light.setPointLight();

        // Set the light to a central position at the start
        light.setPosition(0, 0, -300); // Closer to the viewer

        // Set the diffuse color to a bright white
        light.setDiffuseColor(ofFloatColor(1.0f, 1.0f, 1.0f));

        // Set the specular color to a bright white for pronounced highlights
        light.setSpecularColor(ofFloatColor(1.0f, 1.0f, 1.0f));

        // Set an even brighter ambient color for the light
        light.setAmbientColor(ofFloatColor(1.0f, 1.0f, 1.0f));

        // Reduce attenuation further
        light.setAttenuation(0.05, 0.0005, 0.000005);

        // Set a stronger global ambient light to brighten everything even more
        ofSetGlobalAmbientColor(ofColor(150, 150, 150));

        // Set a very bright background color
        ofBackground(255);

    for(int i = 0; i < NUM_SPHERES; i++){
        // Adjusted the range to keep spheres more centralized
        positions.push_back(ofVec3f(ofRandom(-ofGetWidth()/4, ofGetWidth()/4),
                                    ofRandom(-ofGetHeight()/4, ofGetHeight()/4),
                                    ofRandom(-250, 250)));
        velocities.push_back(ofVec3f(ofRandom(-0.5,0.5), ofRandom(-0.5,0.5), ofRandom(-0.5,0.5)));
        radii.push_back(ofRandom(10, 50));
        colors.push_back(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
        originalRadii.push_back(radii[i]);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();

    for(int i = 0; i < NUM_SPHERES; i++){
        radii[i] = originalRadii[i] + 10 * sin(0.5 * time + i);

        // Update positions based on velocities
        positions[i] += velocities[i];

        // If spheres move too far out, reverse their velocity to bring them back
        if(abs(positions[i].x) > ofGetWidth()/2 || abs(positions[i].y) > ofGetHeight()/2 || abs(positions[i].z) > 250){
            velocities[i] = -velocities[i];
        }

        // If mouse is pressed, attract spheres towards mouse position
        if(mouseIsPressed){
            ofVec3f attractionDir = mousePos3D - positions[i];
            attractionDir.normalize();
            velocities[i] += attractionDir * 0.5;
            velocities[i] *= 0.97;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofRotateXDeg(ofGetFrameNum() * 0.3);
    ofRotateYDeg(ofGetFrameNum() * 0.5);
    ofRotateZDeg(ofGetFrameNum() * 0.2);

    for(int i = 0; i < NUM_SPHERES; i++){
        ofSetColor(colors[i].getLerped(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)), 0.01));
        ofDrawSphere(positions[i], radii[i] * scale);
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
    scale = ofMap(y, 0, ofGetHeight(), 0.5, 2.0);
    // Adjust the z-position to ensure the light is more towards the viewer and illuminates the spheres better
    mousePos3D.set(x - ofGetWidth()/2, y - ofGetHeight()/2, -500);
    light.setPosition(mousePos3D);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseIsPressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouseIsPressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
