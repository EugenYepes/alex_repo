#include "User.hpp"
#include <iostream>

int main() {
    User user("Alice", 20, "alice@example.com");
	User user1("Alice", 20, "alice@example.com");

	if (user == user1) {
		std::cout << "Users are equal." << std::endl;
	} else {
		std::cout << "Users are not equal." << std::endl;
	}
    user.display();
    return 0;
}
