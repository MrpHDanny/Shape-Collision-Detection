#ifndef SHAPE_H
#define SHAPE_H

#include <ostream>
using namespace std;


class Shape {
public:
    /* Coordinates x and y are the center coordinates.
    Length is the diameter of a circle and either side of a square. */
    Shape(unsigned int l, int x, int y);
    void setLength(int l);
    void setPosX(int x);
    void setPosY(int y);
    unsigned int getLength() const;
    int getPosX() const;
    int getPosY() const;
    void moveShape(int x, int y);
    friend ostream& operator<<(ostream& os, const Shape& s);
    virtual bool isCollision(Shape& s) = 0;
protected:
    virtual void print(std::ostream& str) const = 0;
    unsigned int length;
    int x_pos;
    int y_pos;
};

#endif
#pragma once
