
#include <string>
#include "Address.hpp"
using namespace std;

class User {
private:
    string name;
    int age;
    string email;
    Address& address;
public:
    User();
    User(const string& name, int age, const string& email, Address& address);

    void setName(const string& name);
    virtual void setAge(int age);
    void setEmail(const string& email);

    bool operator==(const User& other) const;

    string getName() const;
    int getAge() const;
    string getEmail() const;

    virtual void display() const;
    virtual ~User() = default;
};

class Client : public User {
public:
    Client();
    Client(const string& name, int age, const string& email, Address& address);

    void display() const override;
};

class Admin : public User {
public:
    Admin();
    Admin(const string& name, int age, const string& email, Address& address);

    void setAge(int age) override;
    void display() const override;
};
