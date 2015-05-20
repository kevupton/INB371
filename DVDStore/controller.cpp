#include "controller.h"
#include "auth.h"
#include "app.h"
#include "customer.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

/**
* Initialises the application
*/
Controller::Controller() {
    app.initialise();
}

void Controller::clearCin() {
    cin.clear();
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n' );
}

/**
* The script to instantiate the interface, and interface loop
*/
void Controller::execute() {
    printHeader();
    int option;
    try {
        findCustomerByMovieRental();
        while (true) {
            if (app.auth.isLoggedIn()) {
                handleInput(requestInput());
            } else {
                attemptAuth();
            }
        }
    } catch(exception e) {}
}

void Controller::printHeader() {
    cout << "######  #     # ######     ######  ####### #     # #######    #    #       \n"
            "#     # #     # #     #    #     # #       ##    #    #      # #   #       \n"
            "#     # #     # #     #    #     # #       # #   #    #     #   #  #       \n"
            "#     # #     # #     #    ######  #####   #  #  #    #    #     # #       \n"
            "#     #  #   #  #     #    #   #   #       #   # #    #    ####### #       \n"
            "#     #   # #   #     #    #    #  #       #    ##    #    #     # #       \n"
            "######     #    ######     #     # ####### #     #    #    #     # ####### \n";
}

void Controller::attemptAuth() {
    string username;
    string password;
    cout << "Please log in \nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    app.auth.attemptLogin(username, password);
}

int Controller::requestInput() {
    if (app.auth.isStaff()) {
        displayStaffMenu();
        int nb = getNumberInput(true);
    } else if (app.auth.isCustomer()) {
        displayCustomerMenu();
        int nb = getNumberInput(true);
    }
}

void Controller::displayStaffMenu() {
      cout << string(8,'\n');
      cout << "Staff Menu \n \n";
     string staffDesc[8] = {
        "Add DVD of a new movie:",
        "Add DVD of an existing movie:",
        "Remove DVD:",
        "Register a new customer:",
        "Remove a customer:",
        "Find a customer's phone number:",
        "Find customers who are currently renting a particular movie:",
        "Log Off:"
    };
    for (int i = 0; i < 7; i++) {
        cout << staffDesc[i] + " {" << i + 1 << "}\n";
    }
    cout << staffDesc[7] + " {" << 0 << "}\n";
    cout << "Please enter an option: ";
}


void Controller::displayCustomerMenu() {
      //cout << string(10,'\n');
      cout << "please select an option \n \n";
    string customerDesc[7] = {
        "Browse all movies:",
        "Display movie information:",
        "Rent a DVD:",
        "Return a DVD:",
        "List current rented movies:",
        "Display top 10:",
        "Log Off:"
    };
    for (int i = 0; i < 6; i++) {
        cout << customerDesc[i] + " {" << i + 1 << "}\n";
    }
    cout << customerDesc[6] + " {" << 0 << "}\n";
    cout << string(14,'\n');
}

void Controller::handleInput(int option) {
    if (app.auth.isStaff()) {
        handleStaffInput(option);
    } else {
        handleCustomerInput(option);
    }
}

void Controller::handleStaffInput(int option) {
    StaffMenu item = (StaffMenu) option;
    switch(item) {
    case S_LOG_OFF:
        app.auth.logout();
        break;
    case ADD_DVD_NEW:
        if (!performAddDVDNew()) return;
        break;
    case ADD_DVD_EXISTING:
        if (!performAddDVDExisting()) return;
        break;

    case REMOVE_DVD:
        if (!performRemoveDVD()) return;
        break;

    case REGISTER_NEW_CUSTOMER:
        if (!registerNewCustomer()) return;
        break;

    case REMOVE_CUSTOMER:
        if (!removeCustomer()) return;
        break;

    case FIND_PHONE_NUMBER:
        if (!findPhoneNumber()) return;
        break;

    case FIND_CUSTOMER_BY_MOVIE_RENTAL:
        if (!findCustomerByMovieRental()) return;
        break;
    }
}

void Controller::handleCustomerInput(int option) {
    CustomerMenu item = (CustomerMenu) option;
    switch(item) {
    case C_LOG_OFF:
        app.auth.logout();
        break;
    case BROWSE_ALL_MOVIES:
        if (!performBrowseAllMovies()) return;
        break;
    case DISPLAY_MOVIE_INFO:
        if (!performDisplayMovieInfo()) return;
        break;

    case RENT_DVD:
        if (!performRentDVD()) return;
        break;

    case RETURN_DVD:
        if (!performReturnDVD()) return;
        break;

    case LIST_CURRENT_RENTED_MOVIES:
        if (!performListCurrentRentedMovies()) return;
        break;

    case DISPLAY_TOP_TEN_MOVIES:
        if (!performDisplayTopTenMovies()) return;
        break;
    }
}
/**
* Attempts to get a number input greater than 0
*
* returns int the number specified on input
* throws exception if they canceled input request
*/
int  Controller::getNumberInput() {
    return getNumberInput(false);
}

/**
* Attempts to get a number input of any type. Must type q to quit however
*
* returns int the number specified on input
* throws exception if they canceled input request
*/
int  Controller::getNumberInput(bool use_q) {
    int number;
    string value;
    while (true) {
        cin >> value; ///Gets the value
        value = trim(value);
        number = atoi(value.c_str()); ///Converts value to integer
        if (!(number == 0 && value.compare("0") != 0)) { ///Check that it is a valid integer
            if (!use_q && number == 0 || use_q && value.compare("q") == 0) { //if it is 0 or q then break
                throw exception(); //break the operation
            } else {
                return number;
            }
        } else { //invalid integer
            cout << "\nInvalid integer, try again: ";
        }
        clearCin();
    }
}

/**
* Attempts to get a text input of any type. Uses 0 to cancel
*
* returns string the input string 1 line.
* throws exception if they canceled input request
*/
string  Controller::getTextInput() {
    getTextInput(true);
}

/**
* Attempts to get a text input of any type. Uses 0 to cancel. Specify to trim the string
*
* bool trim whether to trim the string or not
* returns string the input string 1 line.
* throws exception if they canceled input request
*/
string  Controller::getTextInput(bool q_trim) {
    string value;
    while (true) {
        cin >> value; ///Gets the value
        if (q_trim) value = trim(value);
        if (value.size() > 0) { //Checks that the value has a length
            if (value.compare("0") == 0) {
                throw new exception();
            }
            return value;
        } else { //invalid integer
            cout << "\nPlease enter a value: ";
        }
        clearCin();
    }
}

/**
* Load a pause in the events, and wait for the enter key to continue.
*/
void  Controller::waitForEnter() {
    cout << "\n\n\n\n\t\tPress ENTER to return... ";
    cin.get();
    cin.clear();
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n' );
}

/**
* Method for confirming the users choice. Will ask the user to input either 'y' or 'n'
* in which case 'y' means yes and 'n' means no
*
* returns bool true if they selected yes, else false if they selected no
* throws exception if they canceled the request
*/
bool Controller::getConfirm() {
    string val;
    //request confirmation
    /// Example request message: "\nAre you sure you want to CLEAR the schedule!? (y/n): "
    //get the exact input either 'y' or 'n'
    while (true) {
        cin >> val;
        ///Check the input value
        if (val.size() == 1) { //has to be of length 1
            if (val[0] ==  'y') {
                return true;
            } else if (val[0] == 'n') {
                return false;
            } else if (val[0] == '0') {
                throw exception();
            }
        }
         //if it wasnt either of those values
        cout << "Please enter either 'y' for Yes, or 'n' for No: ";
        clearCin();
    }
}

/**
* Gets all movies with the title matching what the user inputs
*
* returns vector<Movie*> returns a vector of all the movies matching the title
*/
vector<Movie*> Controller::getMoviesByTitle() {
    string response = getTextInput();
    vector<Movie*> movies;
    try { ///Attempt to get the movies.
        movies = app.getMoviesByTitle(response);
    } catch(exception e) {}
    return movies;
}

/**
* Attempts to get the movie with the ID specified on user input
*
* return Movie the movie instance with the inputed ID
* throws exception if the movie is not found
*/
Movie Controller::getMovieByID() {
    return app.getMovie(getNumberInput());
}

/**
* Trims from the left side of the string
*
* string &s the string to be trimmed
* returns &string the trimmed string
*/
string &Controller::ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

/**
* Trims from the right side of the string
*
* string &s the string to be trimmed
* returns &string the trimmed string
*/
string &Controller::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

/**
* Trims from both sides of the string
*
* string &s the string to be trimmed
* returns &string the trimmed string
*/
string &Controller::trim(std::string &s) {
    return ltrim(rtrim(s));
}


bool Controller::performAddDVDNew() {

}


bool Controller::performAddDVDExisting() {

}


bool Controller::performRemoveDVD(){

}

bool Controller::registerNewCustomer() {

}

bool Controller::removeCustomer() {

}

bool Controller::findPhoneNumber() {

}

bool Controller::findCustomerByMovieRental() {
    cout << "\nPlease input the movie title: ";
    string title = getTextInput();
    vector<Customer*> customers = app.getAllCustomersRentingMovie(title);
    vector<Customer*>::iterator it;
    cout << "\n\n\n";
    for (it = customers.begin(); it != customers.end(); it++) {
        cout << (*it)->toString() << endl;
    }
}



bool Controller::performBrowseAllMovies() {
}
bool Controller::performDisplayMovieInfo(){
}
bool Controller::performRentDVD(){
}
bool Controller::performReturnDVD(){
}
bool Controller::performListCurrentRentedMovies(){
}
bool Controller::performDisplayTopTenMovies(){
}


/***
    ,o888888o.        ,o888888o.
   8888     `88.   . 8888     `88.
,8 8888       `8. ,8 8888       `8b
88 8888           88 8888        `8b
88 8888           88 8888         88
88 8888           88 8888         88
88 8888   8888888 88 8888        ,8P
`8 8888       .8' `8 8888       ,8P
   8888     ,88'   ` 8888     ,88'
    `8888888P'        `8888888P'

    ,o888888o.    8 888888888o.            .8.           8888888888',8888' `8.`8888.      ,8'
   8888     `88.  8 8888    `88.          .888.                 ,8',8888'   `8.`8888.    ,8'
,8 8888       `8. 8 8888     `88         :88888.               ,8',8888'     `8.`8888.  ,8'
88 8888           8 8888     ,88        . `88888.             ,8',8888'       `8.`8888.,8'
88 8888           8 8888.   ,88'       .8. `88888.           ,8',8888'         `8.`88888'
88 8888           8 888888888P'       .8`8. `88888.         ,8',8888'           `8. 8888
88 8888           8 8888`8b          .8' `8. `88888.       ,8',8888'             `8 8888
`8 8888       .8' 8 8888 `8b.       .8'   `8. `88888.     ,8',8888'               8 8888
   8888     ,88'  8 8888   `8b.    .888888888. `88888.   ,8',8888'                8 8888
    `8888888P'    8 8888     `88. .8'       `8. `88888. ,8',8888888888888         8 8888
          .         .
         ,8.       ,8.           ,o888888o. 8888888 8888888888 8 8888        8 8 8888888888   8 888888888o.
        ,888.     ,888.       . 8888     `88.     8 8888       8 8888        8 8 8888         8 8888    `88.
       .`8888.   .`8888.     ,8 8888       `8b    8 8888       8 8888        8 8 8888         8 8888     `88
      ,8.`8888. ,8.`8888.    88 8888        `8b   8 8888       8 8888        8 8 8888         8 8888     ,88
     ,8'8.`8888,8^8.`8888.   88 8888         88   8 8888       8 8888        8 8 888888888888 8 8888.   ,88'
    ,8' `8.`8888' `8.`8888.  88 8888         88   8 8888       8 8888        8 8 8888         8 888888888P'
   ,8'   `8.`88'   `8.`8888. 88 8888        ,8P   8 8888       8 8888888888888 8 8888         8 8888`8b
  ,8'     `8.`'     `8.`8888.`8 8888       ,8P    8 8888       8 8888        8 8 8888         8 8888 `8b.
 ,8'       `8        `8.`8888.` 8888     ,88'     8 8888       8 8888        8 8 8888         8 8888   `8b.
,8'         `         `8.`8888.  `8888888P'       8 8888       8 8888        8 8 888888888888 8 8888     `88.

8 8888888888   8 8888      88     ,o888888o.    8 8888     ,88' 8 8888888888   8 888888888o.
8 8888         8 8888      88    8888     `88.  8 8888    ,88'  8 8888         8 8888    `88.
8 8888         8 8888      88 ,8 8888       `8. 8 8888   ,88'   8 8888         8 8888     `88
8 8888         8 8888      88 88 8888           8 8888  ,88'    8 8888         8 8888     ,88
8 888888888888 8 8888      88 88 8888           8 8888 ,88'     8 888888888888 8 8888.   ,88'
8 8888         8 8888      88 88 8888           8 8888 88'      8 8888         8 888888888P'
8 8888         8 8888      88 88 8888           8 888888<       8 8888         8 8888`8b
8 8888         ` 8888     ,8P `8 8888       .8' 8 8888 `Y8.     8 8888         8 8888 `8b.
8 8888           8888   ,d8P     8888     ,88'  8 8888   `Y8.   8 8888         8 8888   `8b.
8 8888            `Y88888P'       `8888888P'    8 8888     `Y8. 8 888888888888 8 8888     `88.

***/
///SWAGLORD KEVIN -- COBLAMO --





