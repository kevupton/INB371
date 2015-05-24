#ifndef _controller_h
#define _controller_h
#include "app.h"

using namespace std;

/**
The class for the interface of the application.
Directly interacts with the App class
*/

class Movie;
class Controller {
public:
    ///Sets up everything to do with the application
    Controller();
    ///Runs the while loop which runs the interface
    void execute();

    enum StaffMenu{S_LOG_OFF, ADD_DVD_NEW, ADD_DVD_EXISTING, REMOVE_DVD, REGISTER_NEW_CUSTOMER, REMOVE_CUSTOMER, FIND_PHONE_NUMBER, FIND_CUSTOMER_BY_MOVIE_RENTAL};
    enum CustomerMenu{C_LOG_OFF, BROWSE_ALL_MOVIES, DISPLAY_MOVIE_INFO, RENT_DVD, RETURN_DVD, LIST_CURRENT_RENTED_MOVIES, DISPLAY_TOP_TEN_MOVIES};
    /// trim from start
    static string &ltrim(string &s);
    /// trim from end
    static string &rtrim(string &s);
    /// trim from both ends
    static string &trim(string &s);

private:
    //The app instance
    App app;
    /// clears the cin memory
    void clearCin();

    void printHeader();

    void createHeaderContent(string title);

    void attemptAuth();

    int requestInput();

    void displayStaffMenu();
    void displayCustomerMenu();

    void handleInput(int option);
    void handleStaffInput(int option);
    void handleCustomerInput(int option);

    ///gets an input that is a number not 0. uses 0 to cancel
    int getNumberInput();
    ///gets an input that is a number. uses q to cancel. if the bool is false
    int getNumberInput(bool);

    ///Gets a text input or 0 to cancel
    string getTextInput();
    ///gets the text input either trimming or not
    string getTextInput(bool);

    string getFirstNameInput();
    string getLastNameInput();
    string getPhoneNumberInput();
    string getAddressInput();

    ///Waits for the enter key
    void waitForEnter();

    ///Gets a confirmation from the user
    bool getConfirm();

    ///Creates an input request, which returns all movies with specified title
    vector<Movie*> getMoviesByTitle();

    ///Creates an input request, which returns the movie with the specified id
    Movie getMovieByID();

    Movie::Genre getGenreInput();
    Movie::Classification getClassificationInput();

    bool performAddDVDNew();
    bool performAddDVDExisting();
    bool performRemoveDVD();
    bool registerNewCustomer();
    bool removeCustomer();
    bool findCustomerByName();
    bool findCustomersByMovieRental();


    bool performBrowseAllMovies();
    bool performDisplayMovieInfo();
    bool performRentDVD();
    bool performReturnDVD();
    bool performListCurrentRentedMovies();
    bool performDisplayTopTenMovies();

        /**
    Make all the controller methods private :)
    **/
};

#endif // _controller_h
