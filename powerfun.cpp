#include "powerfun.h"

long long power(int base, int exp) {
    long long result = 1;
	if (exp == 0) {
		return 0;
	}
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}