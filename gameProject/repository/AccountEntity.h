#ifndef ACCOUNTENTITY_H
#define ACCOUNTENTITY_H

#include <iostream>


using namespace std;

typedef enum {
	PLAYER,
	REVIEWER
} accountType_t;

class AccountEntity {
private:
    int id;
    string email;
    string userName;
    accountType_t accountType;
	string prefPlatform; 
    string outletName;
public:
	int getId() const {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
    }

    // Email Getters & Setters
    string getEmail() const {
        return this->email;
    }

    void setEmail(const string& email) {
        this->email = email;
    }

    string getUserName() const {
        return this->userName;
    }

    void setUserName(const string& userName) {
        this->userName = userName;
    }

    accountType_t getAccountType() const {
        return this->accountType;
    }

    string getAccountTypeString() {
		switch (this->accountType)
		{
		case accountType_t::PLAYER:
			return "player";
		case accountType_t::REVIEWER:
			return "reviewer";
		default:
			return "";
		}
	}

    void setAccountType(accountType_t accountType) {
        this->accountType = accountType;
    }

    string getPrefPlatform() const {
        return this->prefPlatform;
    }

    void setPrefPlatform(const string& prefPlatform) {
        this->prefPlatform = prefPlatform;
    }

    string getOutletName() const {
        return this->outletName;
    }

    void setOutletName(const string& outletName) {
        this->outletName = outletName;
    }
};

#endif