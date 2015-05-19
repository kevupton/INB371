#ifndef _app_h
#define _app_h
#include "auth.h"
#include "customer.h"
#include "customercollection.h"
#include "movie.h"
#include "moviecollection.h"
#include "rentedcollection.h"
#include <vector>
#include <map>

using namespace std;

/**
The main application class used to interact with the sub application classes
*/
class App {
public:
    ///Setup method to initialise all the default values in memory
    void initialise();

    ///Registers a customer in the application.
    void registerCustomer(string first_name, string last_name, string phone, string address);

    ///Removes a customer from the list of registered customers.    void removeCustomer(Customer &c);

    ///Register new movie into movie collection
    void registerMovie(string title, string director, int duration, Movie::Genre genre, Movie::Classification classi, string release_date);
    ///Registers a new movie the same as the existing movie
    void registerMovieFromExisting(Movie &m);

    ///Removes a movie from the movie collection
    void removeMovie(Movie &m);
    void removeMovie(int);

    ///Gets the Customer from the registered customer collection based on
    ///Either name or id
    Customer &getCustomer(string);
    Customer &getCustomerByLogin(string);

    ///Gets the Movie from the register movie collection based on id or name
    Movie &getMovie(int);

    ///Get all movies which have the specific title
    vector<Movie*> getMoviesByTitle(string);

    ///Gets all movies in alphabetical order with title as key and count as value.
    ///In ascending order
    map<string, int> getAllMovies();

    CustomerCollection customers = CustomerCollection(this);
    MovieCollection movies = MovieCollection(this);
    RentedCollection rented = RentedCollection(this);
private:
    Auth auth = Auth(this);
};

#endif // _app_h
