#ifndef _auth_h
#define _auth_h
#include "app.h"
#include "customer.h"

using namespace std;

/**
Used for handling the authentication of the application
*/
class Auth {
public:
    enum UserType {CUSTOMER, STAFF, NONE};

    ///The constructor containing the app instance
    Auth(App &a);

    ///Attempt to log the user in. If success return true, else false
    bool attemptLogin(string, string);

    ///Gets the logged in user type
    UserType getUserType();

    ///Checks to see if the user is logged in
    bool isLoggedIn();

    ///Gets the customer object if and only if it is a customer logged in
    Customer &getCustomer();

    ///Log the user out of the current session
    void logout();
private:
    const string STAFF_ID = "staff";
    const string STAFF_PASSWORD = "today123";
    App *app;
    UserType user_type = NONE;
    Customer *customer;
};

#endif // _auth_h