#include "ofApp.h"

void ofApp::loadAllModels(){
    //diamond1.loadModel("diamond_stone.obj");
    //diamond2.loadModel("diamond_stone.obj");
    rock1.loadModel("rock_1.obj");
    rock2.loadModel("rock_2.obj");
    nubby.loadModel("wavy_dude.obj");
    world.setRadius(1100);
}

void ofApp::setInitialPositions(){
    //diamond1.setPosition(-1200, -100, -1500);
    //diamond2.setPosition(1500, -100, -1500);
    rock1.setPosition(-1100, 0, -250);
    rock2.setPosition(1100, 0, -250);
    nubby.setPosition(0, -500, -150);
    world.setPosition(0, 0, -1400);
}

void ofApp::getInitialPositions(){
    //d1_sp = diamond1.getPosition();
    //d2_sp = diamond2.getPosition();
    
    r1_sp = rock1.getPosition();
    r2_sp = rock2.getPosition();
    
    nub_sp = nubby.getPosition();
}

void ofApp::loadTextures(){
    ofDisableArbTex();
    ofLoadImage(tex1, "178.JPG");
    ofLoadImage(tex2, "139.JPG");
    ofLoadImage(tex3, "wavy_dude_material.png");
}

void ofApp::recolorWebcamImage(){
    int sumBrightness = 0;
    for(int i = 0; i < webcam.getWidth(); i++){
        for(int j = 0; j < webcam.getHeight(); j++){
            ofColor oldColor = webcam.getPixels().getColor(i, j);
            int brightness = oldColor.getBrightness();
            sumBrightness = sumBrightness += brightness;
            ofColor newColor;
            
            if(brightness <= 63) {
                newColor.set(0, 8, 113);
            }
            else if(brightness > 64 && brightness <= 127){
                newColor.set(136, 84, 243);
            }
            else if(brightness > 128 && brightness <= 192){
                newColor.set(255, 121, 174);
            }
            else {
                newColor.set(255, 249, 130);
            }
            distortion.setColor(i, j, newColor);
        }
    }
    avgBrightness = sumBrightness / (webcam.getWidth() * webcam.getHeight());
    
}
void ofApp::recolorWebcamImageBG(){
    for(int i = 0; i < webcam.getWidth(); i++){
        for(int j = 0; j < webcam.getHeight(); j++){
            ofColor oldColor = webcam.getPixels().getColor(i, j);
            int brightness = oldColor.getBrightness();
            ofColor newColor;
            
            if(brightness <= 63) {
                newColor.set(0);
            }
            else if(brightness > 64 && brightness <= 127){
                newColor.set(0);
            }
            else if(brightness > 128 && brightness <= 192){
                newColor.set(255);
            }
            else {
                newColor.set(255);
            }
            background.setColor(i, j, newColor);
        }
    }
}

void ofApp::setUpLights(){
    light.enable();
    light.setPointLight();
    light.setPosition(ofVec3f(200,300,600));
    light.setSpecularColor((ofColor(255)));
    light.setDiffuseColor((ofColor(255, 121, 174)));
    
    light2.enable();
    light2.setPointLight();
    light2.setPosition(-200, 300, 600);
    light2.setSpecularColor((ofColor(255)));
    
    backlight1.enable();
    backlight1.setPointLight();
    backlight1.setPosition(800, 300, -600);
    backlight1.setDiffuseColor((ofColor(255, 121, 174)));
    backlight1.setSpecularColor((ofColor(255)));
    
    //backlight2.enable();
    //backlight2.setPointLight();
    //backlight2.setPosition(-800, 300, -600);
    //backlight2.setDiffuseColor((ofColor(255, 121, 174)));
    //backlight2.setSpecularColor((ofColor(255)));
    
    //bottom.enable();
    //bottom.setPointLight();
    //bottom.setPosition(0, 0, 250);
    //ottom.setDiffuseColor((ofColor(255)));
    //bottom.setSpecularColor((ofColor(255)));
}
//--------------------------------------------------------------
void ofApp::setup(){
    webcam.setDeviceID(4);
    webcam.setup(640, 480);
    ofSetBackgroundColor(255, 77, 230);
    
    loadAllModels();
    setInitialPositions();
    getInitialPositions();
    
    cam.setDistance(1300);
    
    
    loadTextures();
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
    distortion.setFromPixels(webcam.getPixels());
    //background.setFromPixels(webcam.getPixels());
}

//--------------------------------------------------------------
void ofApp::draw(){
    //recolorWebcamImage();
    //recolorWebcamImageBG();
    distortion.update();
    //background.update();
    
    //background.draw(ofGetWidth() / 2 - webcam.getWidth() / 2,ofGetHeight() / 2 - webcam.getHeight() / 2);
    
    world.rotate(1.5, 0.0, 1.0, 0.0);

    cam.begin();
    
    setUpLights();
    
    
    float sin_time = sin(ofGetElapsedTimef());
    float cos_time = cos(ofGetElapsedTimef());
    float noise = ofNoise(ofGetElapsedTimef());
    int rotation = (ofGetElapsedTimeMillis() / 10) % 360;
    //diamond1.setPosition((d1_sp.x * sin_time) / noise, d1_sp.y * 20 * noise, d1_sp.z);
    //diamond2.setPosition(d2_sp.x * sin_time, (d2_sp.y / noise) * -1, d2_sp.z);
    
    rock1.setRotation(0, rotation, 0, 1, 0);
    rock1.setPosition(r1_sp.x, 200 * sin_time, r1_sp.z);
    
    rock2.setRotation(0, rotation, 0, 1, 0);
    rock2.setPosition(r2_sp.x, 200 * sin_time, r1_sp.z);
    
    nubby.setPosition(4 * avgBrightness + -200, nub_sp.y, nub_sp.z + avgBrightness);
    nubby.setRotation(0, 180, 0, 0, 1);
    nubby.setRotation(1, rotation, 0, 1, 1);
    
    ofEnableDepthTest();
    //tex1.bind();
    //diamond1.drawFaces();
    //diamond2.drawFaces();
    //tex1.unbind();
    tex2.bind();
    rock1.drawFaces();
    rock2.drawFaces();
    tex2.unbind();
    tex3.bind();
    nubby.drawFaces();
    tex3.unbind();
    
    distortion.getTexture().bind();
    world.draw();
    distortion.getTexture().unbind();
    
    ofDisableDepthTest();
    ofDisableLighting();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
