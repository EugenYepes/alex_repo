#include "User.hpp"

#include <iostream>

using namespace std;

User::User() {
	this->name = "";
	this->age = 0;
	this->email = "";
}

User::User(const string& name, int age, const string& email) {
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

string User::getName() const {
    return this->name;
}

int User::getAge() const {
    return this->age;
}

string User::getEmail() const {
    return this->email;
}

void User::display() const {
    cout << "Name: " << this->name << "\n"
              << "Age: " << this->age << "\n"
              << "Email: " << this->email << endl;
}

Client::Client() : User() {}

Client::Client(const string& name, int age, const string& email) : User(name, age, email) {

}

void Client::display() const {
    cout << "Role: Client" << endl;
    User::display();
}

Admin::Admin() : User() {}

Admin::Admin(const string& name, int age, const string& email) : User(name, age, email) {}

void Admin::setAge(int age) {
    if (age >= 30) {
        User::setAge(age);
    } else {
        cout << "Admin must be at least 30 years old." << endl;
    }
}

void Admin::display() const {
    cout << "Role: Admin" << endl;
    User::display();
}
