#include "auth.h"
#include <algorithm>
#include <string>
#include "app.h"
#include "customer.h"
#include <cstdlib>

/**
* Creates the Auth application with
*
* App &a is the instance of the application
*/
Auth::Auth(App *a) {
    app = a;
}

/**
* Attempts to log the user in using the userid and password
*
* string userid the userid to identify the account
* string password the password to verify the account
*/
bool Auth::attemptLogin(string userid, string password) {
    ///Determine if it is a staff account or user account
    transform(userid.begin(), userid.end(), userid.begin(), ::tolower);
    if (userid.compare(STAFF_ID) == 0) {
        if (password.compare(STAFF_PASSWORD) == 0) { ///Staff details correct
            user_type = STAFF;
            return true;
        }
    } else { ///Verifiy customer account
        try { ///Attempt to get a user with the userid
            if (validPassword(password)) { ///password is 4 numbers long
                customer = &app->getCustomerByLogin(userid);
                user_type = CUSTOMER;
                return true;
            }
        } catch(exception e) { }
    }
    user_type = NONE;
    ///Invalid details
    return false;
}

/**
* Gets the user type. NONE if not logged in, else returns Customer or Staff.
*/
Auth::UserType Auth::getUserType() {
    return user_type;
}

/**
* Checks whether or not the user is logged in or not
*/
bool Auth::isLoggedIn() {
    return (user_type != NONE);
}

/**
* If the user is a customer and logged in, then return the customer value
*/
Customer &Auth::getCustomer() {
    return *customer;
}

/**
* Logs the current user out of the session
*/
void Auth::logout() {
    user_type = NONE;
}

/**
* Checks if the current user is logged in as staff
*
* returns bool true if the current user is staff, else false
*/
bool Auth::isStaff() {
    return (user_type == STAFF);
}

/**
* Checks if the current user is logged in as staff
*
* returns bool true if the current user is staff, else false
*/
bool Auth::isCustomer() {
    return (user_type == CUSTOMER);
}

/**
* Validates a string, determining whether it is a valid password or not
*
* string password the password to validate
* returns bool true if it is a valid password, else returns false
*/
bool Auth::validPassword(string password) {
    int n;
    ///Check the password length
    if (password.size() != 4) return false;
    ///Loop through each character checking if it is a number
    for (int i = 0; i < password.size(); i++) {
        n = atoi(password.substr(i,1).c_str());
        if (n == 0 && password[i] != '0') {
            return false;
        }
    }
    return true;
}
