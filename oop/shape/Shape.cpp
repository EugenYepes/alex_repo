#include "Shape.hpp"

Shape::Shape(double sideLength, int sideQuantity) {
	this->sideLength = sideLength;
	this->sideQuantity = sideQuantity;
}

double Shape::perimeter() {
	return sideLength * sideQuantity;
}