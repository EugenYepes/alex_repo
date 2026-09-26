#include "MainManuScreen.h"

/*
Screen();
~Screen();
void display();
*/

int MainManuScreen::display(){
    std::cout << "Enter 1 for Profile Management" << std::endl;
	std::cout << "Enter 2 for Catalog Management" << std::endl;
    std::cout << "Enter 3 for Backlog Assignment" << std::endl;
    std::cout << "Enter 4 for Progress Tracking" << std::endl;
    std::cout << "Enter 5 for Review Posting" << std::endl;
    std::cout << "Enter 6 for Reports" << std::endl;

	int user_input;
	std::cin >> user_input;
    return user_input;
}