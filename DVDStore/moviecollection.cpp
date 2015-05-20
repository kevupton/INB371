#include "moviecollection.h"
#include "movie.h"
#include <map>
#include <algorithm>
#include "app.h"

/**
* Construct the movie collection with the app instance
*
* App *a the instance of the app
*/
MovieCollection::MovieCollection(App *a) {
    app = a;
}

/**
* Attempts to get the movie with the input id
*
* int id the id of the movie to retrieve
* throws exception if the id is not found
*/
Movie &MovieCollection::get(int id) {
    map<int,Movie*>::iterator it;
    it = collection.find(id);
    if (it != collection.end()) { ///if the value is found
        return *(*it).second;
    }
    throw exception(); ///value not found
}


/**
* Attempts to get the first movie with the specified ID.
*
* string title the title of the movie
* returns Movie a movie instance contain
*/
Movie &MovieCollection::get(string title) {
    map<int, Movie*>::iterator it;
    transform(title.begin(), title.end(), title.begin(), ::tolower); //transform to lower
    string s;
    vector<Movie*> movies; //the list of  movies
    for(it = collection.begin(); it != collection.end(); ++it) { ///check all instances
        s = it->second->getTitle(); //the persons name
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.compare(title) == 0) { ///if the name matches then return the instance
            return *(it->second);
        }
    }
    throw exception();
}

/**
* Adds a movie to the collection
*
* Movie m the movie instance to add to the collection
*/
void MovieCollection::addMovie(Movie &m) {
    m.setID(active_id);
    collection.insert( std::pair<int, Movie*> (active_id, &m));
    active_id++; ///increment the id value
}


/**
* Attempts to remove the movie from the collection
*
* Movie m the movie instance to remove from the collection
* throws exception if the movie does not exist
*/
void MovieCollection::removeMovie(Movie &m)  {
    removeMovie(m.getID());
}

/**
* Attempts to remove the movie from the collection
*
* int id the movie id to remove from the collection
* throws exception if the movie does not exist
*/
void MovieCollection::removeMovie(int id)  {
    map<int,Movie*>::iterator it;
    it = collection.find(id);
    if (it != collection.end()) { ///if the value is found
        collection.erase(it);
    }
    throw exception(); ///value not found
}

/**
* Converts the movie collection into a new map, with the title
* and the total count of movies with that title
*
* returns map<string, int> a map data type containing title and count pair values
*/
map<string, int> MovieCollection::getAllAvailableMoviesAsMap() {
    map<int,Movie*>::iterator it;
    map<string, int> new_map;
    map<string, int>::iterator new_it;
    string title;
    bool is_rented;
    for (it = collection.begin(); it != collection.end(); it++) { ///For each in the current collection
        title = it->second->getTitle();
        new_it = new_map.find(title);
        is_rented = app->rented.isMovieRented(*it->second);
        if (new_it != new_map.end()) { ///exists in new, so plus 1
            if (!is_rented) {
                new_it->second++;
            }
        } else { ///doesnt exist
            new_map.insert(std::pair<string, int> (title, is_rented? 0: 1));
        }
    }
    return new_map;
}


/**
* Get the top ten movies rented by customers
*
* returns map<int, string> a map data type containing title and count pair values
*/
vector<pair<string, int> > MovieCollection::getTopTenMovies() {
    map<int,Movie*>::iterator it;
    map<string, int> new_map;
    map<string, int>::iterator new_it;
    string title;
    bool is_rented;
    for (it = collection.begin(); it != collection.end(); it++) { ///For each in the current collection
        title = it->second->getTitle();
        new_it = new_map.find(title);
        if (new_it != new_map.end()) { ///exists in new, so plus 1
            new_it->second += it->second->getTimesRented();
        } else { ///doesnt exist
            new_map.insert(std::pair<string, int> (title, it->second->getTimesRented()));
        }
    }
    vector<pair<string, int> > top_ten;
    string max_name = "";
    int max_val = 0;

    while (new_map.size() > 0) {
        for (new_it = new_map.begin(); new_it != new_map.end(); new_it++) {
            if (max_name.size() == 0 || new_it->second > max_val) {
                max_name = new_it->first;
                max_val = new_it->second;
            }
        }
        top_ten.push_back(pair<string, int> (max_name, max_val));
        new_map.erase(new_map.find(max_name));
    }

    return top_ten;
}


/**
* Gets all movies with the specified title
*
* string title the title of the movie
* returns vector<Movie*> a vector containing instances of all movies with the same title
*/
vector<Movie*> MovieCollection::getAllMoviesByTitle(string title) {
    map<int, Movie*>::iterator it;
    transform(title.begin(), title.end(), title.begin(), ::tolower); //transform to lower
    string s;
    vector<Movie*> movies; //the list of  movies
    for(it = collection.begin(); it != collection.end(); ++it) { ///check all instances
        s = it->second->getTitle(); //the persons name
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.compare(title) == 0) { ///if the name matches then return the instance
            movies.push_back(it->second);
        }
    }
    return movies;
}
