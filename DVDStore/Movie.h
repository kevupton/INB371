#ifndef _movie_h
#define _movie_h
#include <string>

using namespace std;

class App;
class Customer;
class Movie {
public:
    ///list of all the genres a movie could have
    enum Genre {DRAMA, ADVENTURE, FAMILY, ACTION, SCI_FI, COMEDY, ANIMATED, THRILLER, OTHER};
    static const int GENRE_SIZE = 9;
    const static string GENRE_VALUES[];

    ///all of the classifications available to a movie
    enum Classification {GENERAL, PARENTAL_GUIDANCE, MATURE, MATURE_ACCOMPANIED};
    static const int CLASSIFICATION_SIZE = 4;
    const static string CLASSIFICATION_VALUES[];
    ///constructor
    Movie(string title, string director, int duration, Genre genre, Classification classi, string release_date, App *a);

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
    ///Gets the formated version of the duration
    string getFormattedDuration();

    ///Clones the values of the movie into a new movie class
    Movie &clone();

    ///Sets the ID for a given movie, for future reference
    void setID(int);
    ///Gets the ID of the movie
    int getID();

    void addTimeRented();
    int getTimesRented();

    ///Converts the object into a string
    string toString();

    static string parseGenre(Genre);
    static string parseClassification(Classification);
private:
    int id;
    string title;
    string director;
    int duration; //in minutes
    Genre genre;
    Classification classification;
    string release_date;
    int customer_id;
    App *app;
    int times_rented = 0;
};

#endif // _movie_h
