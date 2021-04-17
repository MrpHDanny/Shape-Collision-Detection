#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

// A square is a shape; it inherits shape.
class Square : public Shape {
public:
	using Shape::Shape;
	bool isCollision(Shape& s);
private:
	virtual void print(std::ostream& str) const;
};


#endif
#pragma once
