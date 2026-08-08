#include "Square.hpp"

Square::Square(double sideLength) : Shape(sideLength, 4) {
}

double Square::area(){
    return getSideLength() * getSideLength();
}
