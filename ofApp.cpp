#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");
	
	ofBackground(239);
	ofSetColor(39);
	
	int size = 40;
	ofColor color;
	for (int x = 0; x < ofGetWidth(); x += size) {

		for (int y = 0; y < ofGetHeight(); y += size) {

			if (y % (size * 2) == 0) {

				this->locations.push_back(ofPoint(x + size * 0.5, y + size * 0.5));
			}
			else {

				this->locations.push_back(ofPoint(x, y + size * 0.5));
			}
		}
	}
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int i = 0; i < this->locations.size(); i++) {
		
		float noise_value = ofNoise(this->locations[i].x * 0.001, this->locations[i].y * 0.001, ofGetFrameNum() * 0.0001);
		float noise_deg = noise_value * 720;
		ofPoint target = ofPoint(200 * cos(noise_deg * DEG_TO_RAD), 200 * sin(noise_deg * DEG_TO_RAD)) + ofPoint(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

		ofDrawCircle(this->locations[i], 3);
		ofDrawLine(this->locations[i], target);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}