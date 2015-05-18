#include "app.h"
#include <iostream>

void App::initialise() {
    cout << "loaded";
}

///Registers a customer in the application.
void App::registerCustomer(Customer &c) {

}

///Removes a customer from the list of registered customers.void App::removeCustomer(Customer &c) {

}

void App::removeCustomer(int) {

}

///Register new movie into movie collection
void App::registerMovie(Movie &m) {

}
///Registers a new movie the same as the existing movie
void App::registerMovieFromExisting(Movie &m) {

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
