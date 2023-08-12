#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    webcam.setup(1024, 768);
    ofDisableAlphaBlending();
   //ofEnableDepthTest();
    //light.enable();
    //light.setPosition(ofVec3f(100,100,200));
    diamond1.loadModel("diamond_stone.obj");
    
    diamond2.loadModel("diamond_stone.obj");
    rock1.loadModel("rock_1.obj");
    rock2.loadModel("rock_2.obj");
    nubby.loadModel("wavy_dude.obj");
    

    diamond1.setPosition(-1500, -100, -1000);
    diamond2.setPosition(1500, -100, -1000);
    rock1.setPosition(-600, 0, -250);
    rock2.setPosition(600, 0, -250);
    nubby.setPosition(0, 100, 250);
    cam.setDistance(1500);
    
 
 
    ofDisableArbTex();
    ofLoadImage(tex1, "178.jpg");
    
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
    
    tex1.bind();
    diamond1.drawFaces();
    diamond2.drawFaces();
    tex1.unbind();
    
//    rock1.drawFaces();
//    rock2.drawFaces();
//    nubby.drawFaces();
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
