#include "customercollection.h"
#include <vector>
#include <algorithm>
#include "customer.h"

/**
* Attempts to retrieve the customer with the given name.
*
* string name is the full name of the customer, ex: "Jack Chappel"
* returns Customer the instance of the customer with the matching name
* throws exception if no customer is found
*/
Customer &CustomerCollection::get(string name) {
    vector<Customer*>::iterator it;
    transform(name.begin(), name.end(), name.begin(), ::tolower); //transform to lower
    string s;
    for(it = collection.begin(); it != collection.end(); ++it) { ///check all instances
        s = (*it)->getFullName(); //the persons name
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.compare(name) == 0) { ///if the name matches then return the instance
            return **it;
        }
    }
    throw exception(); ///throw exception if not found
}

/**
* Attempts to retrieve the customer with the given userid.
*
* string userid is the userid of the customer, ex: "ChappelJack"
* returns Customer the instance of the customer with the matching userid
* throws exception if no customer is found
*/
Customer &CustomerCollection::getByLogin(string userid) {
    vector<Customer*>::iterator it;
    transform(userid.begin(), userid.end(), userid.begin(), ::tolower); //transform to lower
    string s;
    for(it = collection.begin(); it != collection.end(); ++it) {
        s = (*it)->getUserID(); //the persons name
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.compare(userid) == 0) {  ///if the name matches then return the instance
            return **it;
        }
    }
    throw exception(); ///throw exception if not found
}
