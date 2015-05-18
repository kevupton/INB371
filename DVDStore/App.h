#ifndef _app_h
#define _app_h
#include "customer.h"

using namespace std;

/**
The main application class used to interact with the sub application classes
*/
class App {
public:
    ///Registers a customer in the application.
    void registerCustomer(Customer &c);

    ///Removes a customer from the list of registered customers.    void removeCustomer(Customer &c);
    void removeCustomer(int);

    ///Register new movie into movie collection
    void registerMovie(Movie &m);
    ///Registers a new movie the same as the existing movie
    void registerMovieFromExisting(Movie &m);

    ///Removes a movie from the movie collection
    void removeMovie(Movie &m);
    void removeMovie(int);

    ///Gets the Customer from the registered customer collection based on
    ///Either name or id
    Customer getCustomer(string);
    Customer getCustomer(int);
private:
    CustomerCollection customers;
};

#endif // _app_h
