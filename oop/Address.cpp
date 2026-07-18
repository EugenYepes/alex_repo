#include "Address.hpp"

Address::Address(){
    this->homeAddress = "";
    this->country = "";
    this->zipCode = 0;
    this->street = "";
    this->state = "";
}

Address::Address(string homeAddress, string country, int zipCode, string street, string state){
    this->homeAddress = homeAddress;
    this->country = country;
    this->zipCode = zipCode;
    this->street = street;
    this->state = state;
}

ostream& operator<<(ostream &os, const Address &address) {
    os << "Country: " << address.country << endl;
    os << "State: " << address.state << endl;
    os << "Zip Code: " << address.zipCode << endl;
    os << "Street: " << address.street << endl;
    os << "Home Address: " << address.homeAddress << endl;
    return os;
}