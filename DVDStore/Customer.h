#ifndef _customer_h
#define _customer_h

using namespace std;

class Customer {
public:
    ///Gets the phone number of the customer
    string getPhoneNumber();

    ///Gets the customer full name
    string getFullName();
private:
    string first_name;
    string last_name;
    string phone_number;
};

#endif // _customer_h
