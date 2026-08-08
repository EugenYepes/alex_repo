#include "Shape.hpp"

class Triangle : public Shape {
    private:

    public:
    	Triangle(double sideLength);
        
	    double area()override;
};