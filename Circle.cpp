#include "Circle.h"
#include <math.h>
#include <iostream>

void Circle::print(std::ostream& str) const {
	str << "Circle(x:" << x_pos << ",y:" << y_pos << ",d:" << length << ')';
}

bool Circle::isCollision(Shape& s) {
	if (typeid(s).hash_code() == typeid(Circle).hash_code()) {
		int xDif = (this->getPosX() - s.getPosX());
		int yDif = (this->getPosY() - s.getPosY());
		double distance = sqrt(pow(xDif,2) + pow(yDif,2));
		int radiusSum = this->getLength() / 2 + s.getLength() / 2;
		
		if (distance <= radiusSum)
			return true;
		return false;
	}
	else {
		// Circle - Square collision
		float testX = this->getPosX();
		float testY = this->getPosY();

		// Circle
		int cx = this->getPosX();
		int cy = this->getPosY();
		int r = this->getLength() / 2;

		// Square
		int sx = s.getPosX();
		int sy = s.getPosY();
		int sw = s.getLength() / 2; 
		int sh = sw;

		// which edge is closest?
		if (cx < sx) testX = sx - sw; // Test left edge
		else if (cx > sx + sw) testX = sx + sw; // Test right edge
		if (cy < sy) testY = sy - sh; // Test bottom edge
		else if (cy > sy + sh) testY = sy + sh; // Test Top edge

		// get distance from closes edges
		int distX = cx - testX;
		int distY = cy - testY;
		float distance = sqrt(pow(distX, 2) + pow(distY, 2));
		// if the distance is less than the radius we have a collision
		if (distance <= r) {
			return true;
		}
		return false;	
	}	
}