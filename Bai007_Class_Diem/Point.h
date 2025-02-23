#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    private:
        int x;
        int y;
    public:
        Point(int x=0, int y=0);
        void setValue(int x, int y);
        int getX();
        int getY();
        void display();
        float distanceToOrigin();
        float distanceToAnotherPoint(Point);
        void translate(int dx, int dy);
        Point reflectOX();
        Point reflectOY();
        bool isOverlap(Point);

};

#endif // POINT_H
