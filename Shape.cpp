#include "Shape.h"

Shape::Shape(unsigned int l, int x, int y):
	length(l),
	x_pos(x),
	y_pos(y)
{}

void Shape::setLength(int l) {
	length = l;
}

void Shape::setPosX(int x) {
	x_pos = x;
}

void Shape::setPosY(int y) {
	y_pos = y;
}

unsigned int Shape::getLength() const {
	return length;
}

int Shape::getPosX() const {
	return x_pos;
}

int Shape::getPosY() const {
	return y_pos;
}

void Shape::moveShape(int x, int y) {
	x_pos = x_pos + x;
	y_pos = y_pos + y;
}

ostream& operator<<(ostream& os, const Shape& s)
{
	s.print(os);
	return os;
}

