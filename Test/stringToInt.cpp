#include <iostream>
using namespace std;

int converter(string input);
long long power(int base, int exp);

int main() {
	cout << "converter " << converter("123") << endl;

}

int converter(string input){ // 123
    int value = 0;
    for (int i = 0; i < input.size(); i++){
        value += (input[i] - '0') * power(10, input.size() - i - 1);// '123' -> 1 * 100 + 2 * 10 + 3 * 1 
        // '123' -> 1 * 10 ^ 2 + 2 * 10 ^ 1  + 3 * 10 ^ 0
    }
    return value;
}

long long power(int base, int exp) {
    long long result = 1;
	if (exp == 0) {
		return 1;
	}
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}