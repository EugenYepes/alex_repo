#include "Shape.hpp"

class Square : public Shape {
    private:

    public:
    	Square(double sideLength);
        
	    double area()override;
};