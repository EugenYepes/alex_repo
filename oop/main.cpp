#include "User.hpp"
#include <iostream>

int main() {
	Address address("6240 apt 430", "USA", 90036, "West 3rd Street", "California");

    User user("Eugenio", 20, "eugenio@example.com", address);
	User user1("Alex", 14, "alex@example.com", address);

	address.setCountry("Argentina");

    user.display();
	user1.display();

	std::cout;
	
    return 0;
}


/*
C++98: The first official ISO standard released in 1998, establishing the Standard Template Library (STL).
C++03: A minor revision in 2003 focusing primarily on bug fixes and technical corrections.🚀 Modern 
C++11: A massive milestone release that introduced auto, lambda expressions, smart pointers, and multithreading support.
C++14: A minor update delivering small extensions, generic lambdas, and return type deduction.
C++17: A major upgrade adding std::optional, std::string_view, structured bindings, and filesystem support.
C++20: A foundational shift introducing Concepts, Modules, Coroutines, and the std::format library.
C++23: The standard released with std::print and enhancements to standard library ranges.
C++26: The latest standard finalized in early 2026, introducing features like static reflection and contract programming.

*/