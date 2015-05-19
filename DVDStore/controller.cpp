#include "controller.h"
#include "auth.h"
#include "app.h"
#include "customer.h"
#include <iostream>
#include <limits>

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
    /**
    * Print title when program is first opened.
    */
    cout << "######  #     # ######     ######  ####### #     # #######    #    #       \n"
            "#     # #     # #     #    #     # #       ##    #    #      # #   #       \n"
            "#     # #     # #     #    #     # #       # #   #    #     #   #  #       \n"
            "#     # #     # #     #    ######  #####   #  #  #    #    #     # #       \n"
            "#     #  #   #  #     #    #   #   #       #   # #    #    ####### #       \n"
            "#     #   # #   #     #    #    #  #       #    ##    #    #     # #       \n"
            "######     #    ######     #     # ####### #     #    #    #     # ####### \n";
    string username;
    string password;
    string tempBecauseJackIsBadAtProgramming;
    cout << "\n\n\n\n"
            "Please log in \nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    cout << "temp bypass of authentication, 1 for staff 2 for customer 3 for fail";
    cin >> tempBecauseJackIsBadAtProgramming;

    //cin >> Auth.attemptLogin(username, password);
    string staffDesc[8] = {
        "Add DVD:",
        "Add movie:",
        "Remove DVD:",
        "Register a new customer:",
        "Remove a customer:",
        "Find a customer's phone number:",
        "Find customers who are currently renting a particular movie:",
        "Log Off:"
    };

     string customerDesc[7] = {
        "Browse all movies:",
        "Display movie information:",
        "Rent a DVD:",
        "Return a DVD:",
        "List current rented movies:",
        "Display top 10:",
        "Log Off:"
    };
    int option;
    if (tempBecauseJackIsBadAtProgramming == "1") {
        for (int i = 0; i < 8; i++) {
            cout << staffDesc[i] + " {" << i << "}\n";
        }
        while (!(cin >> option) ||!(option >= 0 && option < 8)) {
        cout << "Please enter a valid menu number: ";
        clearCin();
    }
    clearCin();
    }

    if (tempBecauseJackIsBadAtProgramming == "2") {
        for (int i = 0; i < 7; i++) {
            cout << customerDesc[i] + " {" << i << "}\n";
        }
    }

    if (tempBecauseJackIsBadAtProgramming == "3") {
        cout << "login failed";
    }
    /**
    Create some kind of while loop
    **/
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





