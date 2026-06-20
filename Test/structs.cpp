#include <iostream>

using namespace std;

typedef struct {
	int number1;
	int number2;
	char op;
} Operation;


Operation splitOperation();

int main() {

	Operation op = splitOperation();


	cout << op.number1 << endl;
	cout << op.number2 << endl;
	cout << op.op << endl;
	return 0;
}

Operation splitOperation() {
	Operation oper1;

	oper1.number1 = 10;
	oper1.number2 = 20;
	oper1.op = '+';

	return oper1;
}