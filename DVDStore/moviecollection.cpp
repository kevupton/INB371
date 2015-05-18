#include "moviecollection.h"
#include "movie.h"
#include <map>

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
* Movie m the movie instance to add to the collection
* throws exception if the movie does not exist
*/
void MovieCollection::removeMovie(Movie &m)  {
    map<int,Movie*>::iterator it;
    it = collection.find(m.getID());
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
map<string, int> MovieCollection::toMap() {
    map<int,Movie*>::iterator it;
    map<string, int> new_map;
    map<string, int>::iterator new_it;
    string title;
    for (it = collection.begin(); it != collection.end(); it++) { ///For each in the current collection
        title = it->second->getTitle();
        new_it = new_map.find(title);
        if (new_it != new_map.end()) { ///exists in new, so plus 1
            new_it->second++;
        } else { ///doesnt exist
            new_map.insert(std::pair<string, int> (title, 1));
        }
    }
    return new_map;
}
