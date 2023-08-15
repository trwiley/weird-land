#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
    
    void loadAllModels();
    void setInitialPositions();
    void getInitialPositions();
    void loadTextures();
    void recolorWebcamImage();
    void recolorWebcamImageBG();
    void setUpLights();
    
    ofVideoGrabber webcam;
    ofImage distortion;
    ofImage background;
    int avgBrightness;
    
    ofxAssimpModelLoader diamond1;
    ofVec3f d1_sp;
    
    ofxAssimpModelLoader diamond2;
    ofVec3f d2_sp;
    
    ofxAssimpModelLoader rock1;
    ofVec3f r1_sp;
    
    ofxAssimpModelLoader rock2;
    ofVec3f r2_sp;
    
    ofxAssimpModelLoader nubby;
    ofVec3f nub_sp;
    
    ofSpherePrimitive world;
    
    ofEasyCam cam;
    ofLight light;
    ofLight light2;
    ofLight backlight1;
    ofLight backlight2;
    ofLight bottom;
    
    ofTexture tex1;
    ofTexture tex2;
    ofTexture tex3;
    ofTexture worldTex;
    
		
};
