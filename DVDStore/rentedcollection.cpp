#include "rentedcollection.h"
#include "movie.h"
#include "customer.h"
#include "app.h"
#include <string>

/**
* Construct the rented collection with the app instance
*
* App *a the instance of the app
*/
RentedCollection::RentedCollection(App *a) {
    app = a;
}

/**
* Gets all customers renting movies with the title specified
*
* string title the title of the movie
* returns vector<Customer*> a vector containing instances of all customers renting the specified movie
* throws exception if there were no movies matching the value
*/
vector<Customer*> RentedCollection::getCustomersRentingMovie(string title) {
    vector<Movie*> movies = app->movies.getAllMoviesByTitle(title);
    map<int,Customer*>::iterator map_iterator;
    vector<Movie*>::iterator it;
    vector<Customer*> customers;
    int movie_id;
    if (movies.size() > 0) { ///check to see if there are actually movies to process
        for (it = movies.begin(); it != movies.end(); it++) { ///foreach movie
            movie_id = (*it)->getID();
            map_iterator = collection.find(movie_id);
            if (map_iterator != collection.end()) { ///if the id is being rented then add to the customers vector
                customers.push_back(map_iterator->second);
            }
        }
    } else { ///No movies with that title were found
        throw exception();
    }
}

/**
* Get all the movies that a specific customer has rented out
*
* Customer &c the instance of the customer to check for
* returns vector<Movie*> a vector of all instances of movies that are rented out by the specific customer
*/
vector<Movie*> RentedCollection::getCustomerMovies(Customer &c) {
    map<int,Customer*>::iterator it;
    vector<Movie*> movies;
    for (it = collection.begin(); it != collection.end(); it++) { ///foreach movie
        if (it->second == &c) { ///If they are the same customer
            movies.push_back(&app->movies.get(it->first)); ///Add the movie to the list
        }
    }
    return movies;
}

/**
* Checks to see if the movie record instance has been rented out
*
* Movie &m the movie instance to check for
*/
bool RentedCollection::isMovieRented(Movie &m) {
    return isMovieRented(m.getID());
}

/**
* Construct the rented collection with the app instance
*
* App *a the instance of the app
*/
bool RentedCollection::isMovieRented(int id) {
    map<int, Customer*>::iterator it;
    it = collection.find(id);
    return (it != collection.end()); ///if the rented record exists
}
