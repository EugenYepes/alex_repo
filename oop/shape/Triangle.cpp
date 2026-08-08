#include "Triangle.hpp"

Triangle::Triangle(double sideLength) : Shape(sideLength, 3) {
}

double Triangle::area(){
    return 0.433 * (getSideLength() * getSideLength());
}
