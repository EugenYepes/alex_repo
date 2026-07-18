#include <iostream>
#include <string>

using namespace std;


class Address{
    private:
    string country;
    string state;
    int zipCode;
    string street;
    string homeAddress;

    public:
    Address();
    Address(string homeAddress, string country, int zipCode, string street, string state);

    void setCountry(string country) {this->country = country;};

    friend ostream& operator<<(ostream &os, const Address &address);
};