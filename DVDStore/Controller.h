#ifndef _controller_h
#define _controller_h
#include "app.h"

using namespace std;

/**
The class for the interface of the application.
Directly interacts with the App class
*/
class Controller {
public:
    ///Sets up everything to do with the application
    Controller();
    ///Runs the while loop which runs the interface
    void execute();

    enum StaffMenu{ADD_DVD_NEW, ADD_DVD_EXISTING, REMOVE_DVD, REGISTER_NEW_CUSTOMER, REMOVE_CUSTOMER, FIND_PHONE_NUMBER, FIND_CUSTOMER_BY_MOVIE_RENTAL, LOG_OFF};
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

    void attemptAuth();

    int requestInput();

    void displayStaffMenu();
    void displayCustomerMenu();

    void handleInput(int option);

    ///gets an input that is a number not 0. uses 0 to cancel
    int getNumberInput();
    ///gets an input that is a number. uses q to cancel. if the bool is false
    int getNumberInput(bool);

    ///Gets a text input or 0 to cancel
    string getTextInput();

    ///Waits for the enter key
    void waitForEnter();

    ///Gets a confirmation from the user
    bool getConfirm();

    ///Creates an input request, which returns all movies with specified title
    vector<Movie*> getMoviesByTitle();

    ///Creates an input request, which returns the movie with the specified id
    Movie getMovieByID();

    bool performAddDVDNew();
    bool performAddDVDExisting();
    bool performRemoveDVD();
    bool registerNewCustomer();
    bool removeCustomer();
    bool findPhoneNumber();
    bool findCustomerByMovieRental();

        /**
    Make all the controller methods private :)
    **/
};

#endif // _controller_h
