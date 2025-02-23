#include "Point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
void Point::setValue(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Point::getX()
{
    return this->x;
}
int Point::getY()
{
    return this->y;
}
void Point::display()
{
    cout << "(" << this->x << ";" << y << ")";
}
float Point::distanceToOrigin()
{
    return sqrt(this->x*this->x + this->y*this->y);
}
float Point::distanceToAnotherPoint(Point anotherPoint)
{
    return sqrt(pow(this->x - anotherPoint.x, 2) + pow(this->y - anotherPoint.y, 2));
}
void Point::translate(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}
Point Point::reflectOX()
{
    Point reflectPoint;
    reflectPoint.x = this->x;
    reflectPoint.y = -(this->y);

    return reflectPoint;
}
Point Point::reflectOY()
{
    Point reflectPoint;
    reflectPoint.x = -(this->x);
    reflectPoint.y = this->y;

    return reflectPoint;
}
bool Point::isOverlap(Point anotherPoint)
{
    return ((this->x == anotherPoint.x) && (this->y == anotherPoint.y));
}
