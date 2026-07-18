#include "User.hpp"

#include <iostream>

using namespace std;

namespace {
    Address& defaultAddress() {
        static Address address;
        return address;
    }
}

User::User() : address(defaultAddress()) {
	this->name = "";
	this->age = 0;
	this->email = "";
}

User::User(const string& name, int age, const string& email, Address& address) : address(address)
{
	this->name = name;
	this->age = age;
	this->email = email;
}

void User::setName(const string& name) {
    this->name = name;
}

void User::setAge(int age) {
    this->age = age;
}

void User::setEmail(const string& email) {
    this->email = email;
}

bool User::operator==(const User& other) const {
    return this->name == other.name &&
           this->age == other.age &&
           this->email == other.email;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "Name: " << user.name
       << "\nAge: " << user.age
       << "\nEmail: " << user.email << "\n"
	   << user.address;
    return os;
}

string User::getName() const {
    return this->name;
}

int User::getAge() const {
    return this->age;
}

string User::getEmail() const {
    return this->email;
}

Client::Client() : User() {}

Client::Client(const string& name, int age, const string& email, Address& address) : User(name, age, email, address) {

}

Admin::Admin() : User() {}

Admin::Admin(const string& name, int age, const string& email, Address& address) : User(name, age, email, address) {}

void Admin::setAge(int age) {
    if (age >= 30) {
        User::setAge(age);
    } else {
        cout << "Admin must be at least 30 years old." << endl;
    }
}
