#include "Square.h"
#include <iostream>

void Square::print(std::ostream& str) const {
	str << "Square(x:" << x_pos << ",y:" << y_pos << ", l:" << length << ')';
}

bool Square::isCollision(Shape& s) {
	if (typeid(s).hash_code() == typeid(Square).hash_code()) {
		// l - top left corner, r - bottom right corner

		// this square
		int l1_x = this->getPosX() - this->getLength() / 2;
		int l1_y = this->getPosY() + this->getLength() / 2;
		int r1_x = this->getPosX() + this->getLength() / 2;
		int r1_y = this->getPosY() - this->getLength() / 2;

		// the other square
		int l2_x = s.getPosX() - s.getLength() / 2;
		int l2_y = s.getPosY() + s.getLength() / 2;
		int r2_x = s.getPosX() + s.getLength() / 2;
		int r2_y = s.getPosY() - s.getLength() / 2;
		
		// If one rectangle is on left side of other 
		if (l1_x > r2_x || l2_x > r1_x)
			return false;

		// If one rectangle is above other 
		if (l1_y < r2_y || l2_y < r1_y)
			return false;

		return true;
	}
	else {
		return s.isCollision(*this);
	}
}

