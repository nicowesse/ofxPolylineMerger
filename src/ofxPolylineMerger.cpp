//
//  ofxPolylineMerger.cpp
//  ofxPolylineMerger
//
//  Created by pach on 19/01/15.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//


#include "ofxPolylineMerger.h"

ofxPolylineMerger::ofxPolylineMerger(){

}

ofxPolylineMerger::~ofxPolylineMerger(){

}


void ofxPolylineMerger::setup(int resolution) {
    pointCount = resolution;
    easingType = ofxTween::easeInOut;
    clamp = true;
}

void ofxPolylineMerger::update() {

}

void ofxPolylineMerger::draw() {
    from.draw();
    to.draw();
    output.draw();
}

void ofxPolylineMerger::setPointCount(int count){
    pointCount = count;
}

void ofxPolylineMerger::setFrom(ofPolyline &poly){
    if (&poly != NULL && poly.size()>0) {
        from = poly.getResampledByCount(pointCount);
    }
}

void ofxPolylineMerger::setTo(ofPolyline &poly){
    if (&poly != NULL && poly.size() > 0) {
        to = poly.getResampledByCount(pointCount);
    }
}

void ofxPolylineMerger::mergePolyline(float interpolation){
    output.clear();

    ofPoint ptOut;
    for (int i = 0; i < MIN(from.size(), to.size()); i++) {
        ptOut.x = ofxTween::map(interpolation, 0., 1., from[i].x, to[i].x, clamp, easing, easingType);
        ptOut.y = ofxTween::map(interpolation, 0., 1., from[i].y, to[i].y, clamp, easing, easingType);
        output.addVertex(ptOut);
    }

}

void ofxPolylineMerger::mergePolyline(ofPolyline &from, ofPolyline &to, float interpolation){
    setFrom(from);
    setTo(to);

    mergePolyline(interpolation);
}
