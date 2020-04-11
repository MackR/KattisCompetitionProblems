//
//  main.cpp
//  TargetsShot
//
//  Created by Mack Ragland on 9/25/19.
//  Copyright © 2019 KattisPracticeProblems. All rights reserved.
//
//  Original Problem Found at: https://open.kattis.com/problems/hittingtargets
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class circle {
private:
    
    int xCirc,yCirc,radius;
    
public:
    
    circle ( int circX, int circY, int radius1){
        radius = radius1;
        xCirc = circX;
        yCirc = circY;
    }
    
    int getRadius (){return radius;}
    int getX(){return xCirc;}
    int getY (){return yCirc;}
    
    bool isInsideCircle(int pointX, int pointY){
        if (sqrt(pow((pointX - getX()), 2) + pow((pointY - getY()), 2))<= getRadius())
        {return true;}
        else return false;
    }
};
class rectangle {
private:
    int x1, x2, y1, y2;
    
public:
    
    rectangle (int x1, int y1, int x2, int y2){
        this-> x1 = x1;
        this-> x2 = x2;
        this-> y1 = y1;
        this-> y2 = y2;
    }
    
    int getX1(){return x1;}
    int getX2(){return x2;}
    int gety1(){return y1;}
    int gety2(){return y2;}
    
    
    bool isInsideRectangle(int pointX, int pointY){
        if ((x1 <= pointX && pointX <= x2)&&(y1 <= pointY && pointY <= y2))
        
        {return true;}
        
        else return false;}
    
};

vector<circle> circles;
vector<circle> ::iterator itc;
vector<rectangle> rects;
vector<rectangle> ::iterator itr;

/*
void incrementIfInside(circle cir, int x, int y){
    if (cir.isInsideCircle(x, y)) {
        *counter++;
    }
}
void incrementIfInside(rectangle rect, int x, int y){
    if (rect.isInsideRectangle(x, y)) {
        *counter++;
    }
} */


int main(int argc, const char * argv[]) {
    
    int counter = 0;
    int* pcounter = 0;
    pcounter = &counter;
    
    

    int objectNum, shotNum;
    string shape;
    int circX, circY, rad;
    int x1, y1, x2, y2;
    int xPoint, yPoint;
    
    
    cin >> objectNum;
    
    for (int i = 0; i < objectNum; i++) {
        cin >> shape;
        if (shape == "rectangle") {
            cin >> x1 >> y1 >> x2 >> y2;
            rects.push_back(rectangle(x1, y1, x2, y2));
        }
        if (shape == "circle") {
            cin >> circX >> circY >> rad;
            circles.push_back(circle(circX,circY,rad));
        }
    }
    cin >> shotNum;
    for (int i = 0; i < shotNum; i++) {
        cin >> xPoint >> yPoint;
        for( itc = circles.begin(); itc != circles.end(); itc++){
            if (itc->isInsideCircle(xPoint, yPoint)) {
                (*pcounter)++;
            }
        }
        for( itr = rects.begin(); itr != rects.end(); itr++){
            if (itr->isInsideRectangle(xPoint, yPoint)) {
                (*pcounter)++;
            }
        }
        cout << *pcounter << endl;
        *pcounter = 0;
    }
    circles.clear();
    rects.clear();
    
    
    return 0;
}
