#ifndef _moviecollection_h
#define _moviecollection_h
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class App;
class Movie;
class MovieCollection {
public:
    ///The movie collection with the app instance
    MovieCollection(App *a);

    ///Converts the collection into a map containing <title, count>
    map<string, int> toMap();

    ///Adds a movie to the collection
    void addMovie(Movie &m);

    ///Gets the movie by the ID of the movie
    Movie &get(int);

    ///Removes the movie from the collection
    void removeMovie(Movie &m);

    ///Gets all movies with the title
    vector<Movie*> getAllMoviesByTitle(string);
private:
    map<int, Movie*> collection;
    ///The current id for the list
    int active_id = 1;
    App *app;
};

#endif // _moviecollection_h
