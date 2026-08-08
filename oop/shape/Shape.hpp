
#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
private:
	double sideLength;
	int sideQuantity;
public:
	Shape(double sideLength, int sideQuantity);

	double perimeter();
	virtual double area() = 0;

	double getSideLength() {return this->sideLength;}
	double getSideQuantity() {return this->sideQuantity;}
};

#endif

