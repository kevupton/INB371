#ifndef _customer_h
#define _customer_h
#include <string>

using namespace std;

class Customer {
public:
    ///Constructs the customer class
    Customer(string first_name, string last_name, string phone_number, string address);

    ///Gets the phone number of the customer
    string getPhoneNumber();

    ///Gets the customer full name
    string getFullName();

    ///Gets the residential address of the customer
    string getAddress();

    ///Gets the customers userid, used to login
    string getUserID();
private:
    string first_name;
    string last_name;
    string phone_number;
    string address;
};

#endif // _customer_h
