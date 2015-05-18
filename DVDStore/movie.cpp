#include "movie.h"
#include "app.h"

///constructor
Movie::Movie(string title, string director, int duration, Genre genre, Classification classi, string release_date, App *a) {

}

///Checks if the current movie is being rented by anyone
bool Movie::isRented() {}

///Rents the dvd out to the customer
void Movie::rentToCustomer(Customer &c) {}
///Set the dvd as returned
void Movie::setReturned() {}

///Gets the genre and returns it as a string
string Movie::getGenre() {}
///Gets the title as a string
string Movie::getTitle() {}
///gets the director
string Movie::getDirector() {}
///gets the duration in minutes as int
int Movie::getDuration() {}
///Gets the classification as a string
string Movie::getClassification() {}
///Gets the release date
string Movie::getReleaseDate() {}

///Clones the values of the movie into a new movie class
Movie Movie::clone() {}

///Sets the ID for a given movie, for future reference
void Movie::setID(int) {}
///Gets the ID of the movie
int Movie::getID() {}
