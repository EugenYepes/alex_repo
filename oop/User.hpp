#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name;
    int age;
    string email;
public:
    User();
    User(const string& name, int age, const string& email);

    void setName(const string& name);
    virtual void setAge(int age);
    void setEmail(const string& email);

    bool operator==(const User& other) const;

    friend ostream& operator<<(ostream& os, const User& user);

    string getName() const;
    int getAge() const;
    string getEmail() const;

    virtual void display() const;
    virtual ~User() = default;
};

class Client : public User {
public:
    Client();
    Client(const string& name, int age, const string& email);

    void display() const override;
};

class Admin : public User {
public:
    Admin();
    Admin(const string& name, int age, const string& email);

    void setAge(int age) override;
    void display() const override;
};

#endif
