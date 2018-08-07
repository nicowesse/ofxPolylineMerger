//
//  ofxPolylineMerger.h
//  ofxPolylineMerger
//
//  Created by pach on 19/01/15.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxTween.h"

class ofxPolylineMerger{

public:
    ofxPolylineMerger();
    ~ofxPolylineMerger();

    void setup(int resolution);
    void update();
    void draw();

    void setPointCount(int count);
    inline int getPointCount() { return pointCount;};

    inline ofPolyline getPolyline() {return output;};

    void setFrom(ofPolyline & from);
    void setTo(ofPolyline & to);


    void mergePolyline(float interpolation);
    void mergePolyline(ofPolyline &from, ofPolyline &to, float interpolation);

private:
    ofPolyline from;
    ofPolyline to;
    ofPolyline output;

    int pointCount;

    ofxEasingCubic easing;
    float clamp;
    ofxTween::ofxEasingType easingType;

};
