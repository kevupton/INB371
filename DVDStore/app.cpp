#include "app.h"
#include <string>
#include "customer.h"
#include <iostream>

/**
* Initialise all of the default values to be in our memory base
*/
void App::initialise() {
    registerCustomer("Kevin","Upton","0417605052","3608/108 Albert St Brisbane");
    registerCustomer("JackestOF","Chappells","RARAR","Who knows? Jesus knows...");
    registerMovie("TEST","Kevin",200,Movie::ACTION,Movie::GENERAL,"2014");
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

/**
* Registers a movie duplicating the specified movie instance
*
* Movie &m the movie instance of which to duplicate
*/
void App::registerMovieFromExisting(Movie &m) {
    Movie clone = m.clone();
    movies.addMovie(clone);
}

/**
* Removes the specified movie instance from the collection
*
* Movie &m the movie instance to remove
* throws exception if the movie doesnt exist in the collection
*/
void App::removeMovie(Movie &m) {
    movies.removeMovie(m);
}

/**
* Removes the specified movie instance from the collection
*
* int id the movie ID to remove
* throws exception if the movie doesnt exist in the collection
*/
void App::removeMovie(int id) {
    movies.removeMovie(id);
}

/**
* Gets the customer by going by their fullname (first_name + " " +  last_name)
*
* string fullname the full name of the customer, including first_name and last_name
* returns Customer the customer instance in the memory
*/
Customer &App::getCustomer(string fullname) {
    return *&customers.get(fullname);
}

/**
* Gets the customer by userid/loginid
*
* string userid their userid which they use to login
* returns Customer the customer instance
* throws exception if the userid is not found
*/
Customer &App::getCustomerByLogin(string userid) {
    return *&customers.getByLogin(userid);
}

/**
* Gets the movie based on the movie id
*
* int id the movie id to search for
* returns Movie the movie instance of movie id searched for
* throws exception if movie id is not found
*/
Movie &App::getMovie(int id) {
    return *&movies.get(id);
}

/**
* Gets all movies with the movie title specified
*
* string title the movie title to search for
* returns vector<Movie*> a vector containing an instance  of all movies with the title
*/
vector<Movie*> App::getMoviesByTitle(string title) {
    return movies.getAllMoviesByTitle(title);
}

/**
* Gets all available movies (i.e. not rented out) sorted in alphabetical order by their title,
* along with the count.
*
* returns map<string, int> a map of the title, count relationship of available movies
*/
map<string, int> App::getAllAvailableMovies() {
    return movies.getAllAvailableMoviesAsMap();
}

/**
* Gets all customers who are renting a particular movie
*
* string title the movie title to search for
* returns vector<Customer*> the a vector containing the instances of  all customers
* throws exception if movie title isnt found
*/
vector<Customer*> App::getAllCustomersRentingMovie(string title) {
    return rented.getCustomersRentingMovie(title);
}
