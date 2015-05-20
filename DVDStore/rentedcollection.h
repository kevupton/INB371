#ifndef _rentedcollection_h
#define _rentedcollection_h
#include <vector>
#include <string>
#include <map>

using namespace std;

class Customer;
class Movie;
class App;
class RentedCollection {
public:
    RentedCollection(App *a);

    ///Get all customers renting particular movie
    vector<Customer*> getCustomersRentingMovie(string);

    ///Get all movies associated to the customer
    vector<Movie*> getCustomerMovies(Customer &c);

    ///Create a new rental
    void createRental(Movie &m, Customer &c);

    ///Checks to see if the customer is renting the movie
    bool customerIsRentingMovie(int,string);

    ///Set a movie as returned
    void returnMovie(Movie &m);

    ///Checks to see if the movie is currently being rented
    bool isMovieRented(Movie &m);
    bool isMovieRented(int);
private:
    ///Movie_id, Customer collection of videos currently being rented.
    map<int, Customer*> collection;
    //the app instance
    App *app;
};

#endif // _rentedcollection_h
