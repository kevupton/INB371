#ifndef _customer_h
#define _customer_h
#include <string>
#include <vector>

using namespace std;

class App;
class Movie;
class Customer {
public:
    ///Constructs the customer class
    Customer(string first_name, string last_name, string phone_number, string address, App *a);

    ///Gets the phone number of the customer
    string getPhoneNumber();

    ///Gets the customer full name
    string getFullName();

    ///Gets the residential address of the customer
    string getAddress();

    ///Gets the customers userid, used to login
    string getUserID();

    ///Gets the rented movies for the specific customer
    vector<Movie*> getRentedMovies();
private:
    string first_name;
    string last_name;
    string phone_number;
    string address;
    App *app;
};

#endif // _customer_h
