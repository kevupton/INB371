#include "customer.h"

///Constructs the customer class
Customer::Customer(string first_name, string last_name, string phone_number, string address) {

}

///Gets the phone number of the customer
string Customer::getPhoneNumber() {
    return phone_number;
}

///Gets the customer full name
string Customer::getFullName() {
    return first_name + " " + last_name;
}

///Gets the residential address of the customer
string Customer::getAddress() {
    return address;
}

string Customer::getUserID() {
    return last_name + first_name;
}
