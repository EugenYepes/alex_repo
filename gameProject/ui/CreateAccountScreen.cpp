#include "CreateAccountScreen.h"


AccountEntity CreateAccountScreen::display() {
	AccountEntity account;
    std::cout << "Please give an email: ";
    string email_input;
    std::cin >> email_input;
    account.setEmail(email_input);

    std::cout << "Please give an username: ";
    string userName_input;
    std::cin >> userName_input;
    account.setUserName(userName_input);

    //fix here
    std::cout << "Please give an account type [1 for Player, 2 for Reviewer]: ";
    int account_input;
    std::cin >> account_input;
    account.setAccountType(account_input == 1 ? accountType_t::PLAYER : accountType_t::REVIEWER);

    std::cout << "Please give an perferred platform: ";
    string prefPlatform_input;
    std::cin >> prefPlatform_input;
    account.setPrefPlatform(prefPlatform_input);


    std::cout << "Please give an outlet: ";
    string outlet_input;
    std::cin >> outlet_input;
    account.setOutletName(outlet_input);

	return account;
}


