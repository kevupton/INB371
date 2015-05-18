#ifndef _moviecollection_h
#define _moviecollection_h
#include "movie.h"
#include <map>
#include <set>

using namespace std;
/*
struct MovieSorting {
    bool operator() (Movie& lhs, Movie& rhs) const{
        return lhs.getID() < rhs.getID();
    }
};*/
class MovieCollection {
public:
    ///Converts the collection into a map containing <title, count>
    map<string, int> toMap();

    ///Adds a movie to the collection
    void addMovie(Movie &m);

    ///Gets the movie by the ID of the movie
    Movie &get(int);

    ///Removes the movie from the collection
    void removeMovie(Movie &m);
private:
    map<int, Movie*> collection;
    ///The current id for the list
    int active_id = 1;
};

#endif // _moviecollection_h
