#include "Pentagon.hpp"

Pentagon::Pentagon(double sideLength) : Shape(sideLength, 5) {
}

double Pentagon::area(){
    return 1.72048 * (getSideLength() * getSideLength());
}