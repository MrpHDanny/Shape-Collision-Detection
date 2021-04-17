#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

// A circle is a shape; it inherits shape.
class Circle : public Shape {
public:
	using Shape::Shape;
	bool isCollision(Shape& s);
private:
	virtual void print(std::ostream& str) const;
};


#endif
#pragma once
