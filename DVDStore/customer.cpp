#include "customer.h"
#include "app.h"

/**
* The constructor for the customer
*
* string first_name the first name
* string last_name the last name
* string phone_number the contact number
* string address the residential address
* App *a the app instance
*/
Customer::Customer(string first_name, string last_name, string phone_number, string address, App *a) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->phone_number = phone_number;
    this->address = address;
    app = a;
}

/**
* Gets the phone number of the customer
*
* returns string the phone number for the customer
*/
string Customer::getPhoneNumber() {
    return phone_number;
}

/**
* Gets the full name of the customer. (first_name + " " + last_name)
*
* returns string the full name
*/
string Customer::getFullName() {
    return first_name + " " + last_name;
}

/**
* Gets the address of the customer
*
* returns string the address
*/string Customer::getAddress() {
    return address;
}

/**
* Gets the userid of the customer. (last_name + first_name)
*
* returns string the userid
*/
string Customer::getUserID() {
    return last_name + first_name;
}

/**
* Converts the Customer object into a readable, printable string
*
* returns string the string instance of the Customer
*/
string Customer::toString() {
    return getFullName() + ", " + getPhoneNumber() + ", " + getAddress();
}
