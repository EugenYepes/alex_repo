#include <iostream>
#include "powerfun.h"
#include "Square.h"
using namespace std;


void swap(int* a, int* b);
void maskIpAdress(int* ipAddress);


int main() {
	Square square(5);
	cout << "Area of the square: " << square.getArea() << endl;
	return 0;
}

void swap(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
	printf("memory address of a inside function: %p\n", a);
	printf("memory address of b inside function: %p\n", b);
	cout << "After swap inside the function: a = " << *a << ", b = " << *b << endl;
}

void maskIpAdress(int* ipAddress) {
	int mask = 0xFF000000;
	*ipAddress = (*ipAddress) & mask;
}

