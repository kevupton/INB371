#include "app.h"
#include <string>
#include "customer.h"
#include <iostream>

/**
* Initialise all of the default values to be in our memory base
*/
void App::initialise() {
    registerCustomer("Kevin","Upton","0417605052","3608/108 Albert St Brisbane");
    registerCustomer("JackestOF","Chappels","RARAR","Who knows? Jesus knows...");
}

/**
* Register a new customer in our system with the given values
*
* string first_name the first name
* string last_name the last_name,
* string phone the phone
* string address the address
* throws exception if the name already exists
*/
void App::registerCustomer(string first_name, string last_name, string phone, string address) {
    Customer *c = new Customer(first_name, last_name, phone, address, this);
    customers.addCustomer(*c);
}

/**
* Removes a customer from the memory base
*
* Customer &c the customer to be removed
* throws exception if the user doesnt exist
*/void App::removeCustomer(Customer &c) {
    customers.removeCustomer(c);
}

/**
* Registers a movie in the memory base
*
* string title the title  of the movie
* string director the director of them movie
* int duration the duration in minutes
* Movie::Genre genre the genre of the movie
* Movie::Classification classi the classification of the movie (MA15+, G, PG)
* string release_date the date of release
*/
void App::registerMovie(string title, string director, int duration, Movie::Genre genre, Movie::Classification classi, string release_date) {
    Movie *m = new Movie(title, director, duration, genre, classi, release_date, this);
    movies.addMovie(*m);
}


void App::registerMovieFromExisting(Movie &m) {
    Movie clone = m.clone();
    movies.addMovie(clone);
}

///Removes a movie from the movie collection
void App::removeMovie(Movie &m) {

}

void App::removeMovie(int) {

}

///Gets the Customer from the registered customer collection based on
///Either name or id
Customer &App::getCustomer(string fullname) {
    return *&customers.get(fullname);
}

///Gets the Customer from the registered customer collection based on
///Either name or id
Customer &App::getCustomerByLogin(string userid) {
    return *&customers.getByLogin(userid);
}

///Gets the Movie from the register movie collection based on id or name
Movie &App::getMovie(int id) {
    return *&movies.get(id);
}

///Get all movies which have the specific title
vector<Movie*> App::getMoviesByTitle(string) {
    return vector<Movie*>();
}

///Gets all movies in alphabetical order with title as key and count as value.
///In ascending order
map<string, int> App::getAllMovies() {
    return map<string, int>();
}
