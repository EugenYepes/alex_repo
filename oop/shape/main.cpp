#include "Triangle.hpp"
#include "Square.hpp"
#include "Pentagon.hpp"
#include <iostream>

using namespace std;

int main(){
    Triangle triangle(10);
    cout << triangle.area() << endl;
	cout << triangle.perimeter() << endl;

    Square square(40);
    cout << square.area() << endl;
	cout << square.perimeter() << endl;

    Pentagon pentagon(40);
    cout << pentagon.area() << endl;
	cout << pentagon.perimeter() << endl;
}