#ifndef _movie_h
#define _movie_h
#include <string>
#include "customer.h"
#include "movie.h"

using namespace std;

class Movie {
public:
    ///list of all the genres a movie could have
    enum Genre {Drama, Adventure, Family, Action, Sci_Fi, Comedy, Animated, Thriller};
    ///all of the classifications available to a movie
    enum Classification {General, Parental_Guidance, Mature, Mature_Accompanied};

    ///constructor
    Movie(string title, string director, int duration, Genre genre, Classification classi, string release_date);

    ///Checks if the current movie is being rented by anyone
    bool isRented();

    ///Rents the dvd out to the customer
    void rentToCustomer(Customer &c);
    ///Set the dvd as returned
    void setReturned();

    ///Gets the genre and returns it as a string
    string getGenre();
    ///Gets the title as a string
    string getTitle();
    ///gets the director
    string getDirector();
    ///gets the duration in minutes as int
    int getDuration();
    ///Gets the classification as a string
    string getClassification();
    ///Gets the release date
    string getReleaseDate();

    ///Clones the values of the movie into a new movie class
    Movie clone();

    ///Sets the ID for a given movie, for future reference
    void setID(int);
    ///Gets the ID of the movie
    int getID();
private:
    int id;
    string title;
    string director;
    int duration; //in minutes
    Genre genre;
    Classification classification;
    string release_date;
    int customer_id;
};

#endif // _movie_h
