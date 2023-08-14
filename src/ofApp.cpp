#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    webcam.setup(ofGetWindowWidth(), ofGetWindowHeight());
    //ofDisableAlphaBlending();
  
 
    diamond1.loadModel("diamond_stone.obj");
    
    diamond2.loadModel("diamond_stone.obj");
    rock1.loadModel("rock_1.obj");
    rock2.loadModel("rock_2.obj");
    nubby.loadModel("wavy_dude.obj");
    

    diamond1.setPosition(-1500, -100, -1000);
    diamond2.setPosition(1500, -100, -1000);
    rock1.setPosition(-600, 0, -250);
    rock2.setPosition(600, 0, -250);
    nubby.setRotation(0, 180, 0, 0, 1);
    nubby.setPosition(0, -300, 250);
   
    cam.setDistance(1500);
    
 
 
    ofDisableArbTex();
    ofLoadImage(tex1, "178.jpg");
    ofLoadImage(tex2, "139.jpg");
    ofLoadImage(tex3, "wavy_dude_material.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
    distortion.setFromPixels(webcam.getPixels());
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < webcam.getWidth(); i++){
        for(int j = 0; j < webcam.getHeight(); j++){
            ofColor oldColor = webcam.getPixels().getColor(i, j);
            int brightness = oldColor.getBrightness();
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


    distortion.update();
    distortion.draw(0, 0);


    cam.begin();
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
    
    backlight2.enable();
    backlight2.setPointLight();
    backlight2.setPosition(-800, 300, -600);
    backlight2.setDiffuseColor((ofColor(255, 121, 174)));
    backlight2.setSpecularColor((ofColor(255)));
    
    bottom.enable();
    bottom.setPointLight();
    bottom.setPosition(0, 0, 250);
    bottom.setDiffuseColor((ofColor(255)));
    bottom.setSpecularColor((ofColor(255)));
    
    ofEnableDepthTest();
    tex1.bind();
    diamond1.drawFaces();
    diamond2.drawFaces();
    tex1.unbind();
    tex2.bind();
    rock1.drawFaces();
    rock2.drawFaces();
    tex2.unbind();
    tex3.bind();
    nubby.drawFaces();
    tex3.unbind();
    light.disable();
    light2.disable();
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
