#include "Shape.hpp"

class Pentagon : public Shape {
    private:

    public:
    	Pentagon(double sideLength);
        
	    double area()override;
};
