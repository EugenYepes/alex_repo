#include "Square.h"

Square::Square(int side) {
	this->side = side;
}

int Square::getArea() {
	return power(this->side, 2);
}
