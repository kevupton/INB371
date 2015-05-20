#include "movie.h"
#include "app.h"

/**
* The constructor for the movie, used to set it up
*
* string title the title
* string director the director
* int duration the duration in minutes
* Genre genre the genre of the movie
* Classification classi the classification of the movie (M, MA15+, etc)
* string release_date the date of release
* App *a the instance of the app
*/
Movie::Movie(string title, string director, int duration, Genre genre, Classification classi, string release_date, App *a) {
    this->title = title;
    this->director = director;
    this->duration = duration;
    this->genre = genre;
    this->classification = classi;
    this->release_date = release_date;
    app = a;
}

/**
* Checks if the movie is currently being rented
*
* returns bool true if it is being rented, else false
*/
bool Movie::isRented() {
    return (app->rented.isMovieRented(*this));
}

/**
* Rent the movie to the customer
*
* Customer &c the instance of the customer to rent the movie to
*/
void Movie::rentToCustomer(Customer &c) {
    app->rented.createRental(*this, c);
}

/**
* Sets the movie as returned
*/
void Movie::setReturned() {
    try {
        app->rented.returnMovie(*this);
    } catch(exception e) {}
}

/**
* Gets the genre of the movie
*
* returns string the string formated value for Genre
*/
string Movie::getGenre() {
    switch(genre) {
    case DRAMA:
        return "Drama";
        break;
    case ADVENTURE:
        return "Adventure";
        break;
    case FAMILY:
        return "Family";
        break;
    case ACTION:
        return "Action";
        break;
    case SCI_FI:
        return "Sci-Fi";
        break;
    case COMEDY:
        return "Comedy";
        break;
    case ANIMATED:
        return "Animated";
        break;
    case THRILLER:
        return "Thriller";
        break;
    case OTHER:
        return "Other";
        break;
    }
}

/**
* Gets the title of the movie
*
* returns string the title of the movie
*/
string Movie::getTitle() {
    return title;
}

/**
* Gets the director of the movie
*
* returns string the director of the movie
*/
string Movie::getDirector() {
    return director;
}

/**
* Gets the duration of the movie
*
* returns int the duration of the movie
*/
int Movie::getDuration() {
    return duration;
}

/**
* Gets the classification of the movie, ex: MA15+
*
* returns string the director of the movie
*/
string Movie::getClassification() {
    switch(classification) {
    case GENERAL:
        return "G";
        break;
    case PARENTAL_GUIDANCE:
        return "PG";
        break;
    case MATURE:
        return "M15+";
        break;
    case MATURE_ACCOMPANIED:
        return "MA15+";
        break;
    }
}

/**
* Gets the release date of the movie
*
* returns string the release date of the movie
*/
string Movie::getReleaseDate() {
    return release_date;
}

/**
* Clones the current movie class, for duplicate insertion
*
* returns Movie a new instance of the movie class
*/
Movie Movie::clone() {
    return *new Movie(title,director,duration,genre,classification,release_date,app);
}

/**
* Sets the movie ID for the movie. (Cannot be set in constructor)
*
* int id the id of the movie
*/
void Movie::setID(int id) {
    this->id = id;
}

/**
* Gets the movie ID associated with this movie
*
* returns int the movie ID.
*/
int Movie::getID() {
    return id;
}

/**
* Converts the movie object into a readable, printable string
*
* returns string the string instance of the movie
*/
string Movie::toString() {
    return getTitle() + " " + getClassification() + ", " + getReleaseDate() + ", " + getDirector() + ", " + getGenre();
}
