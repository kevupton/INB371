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


/**
* Checks if the customer name already exists.
*
* string name the full name of the customer, ex: "Jack Chappel"
* returns true if the name exists, else false
*/
bool CustomerCollection::nameExists(string name) {
    try { ///Attempt to get the customer with the name.
        get(name);
        return true;
    } catch(exception e) {}
    return false;
}

/**
* Attemps to add the customer to the collection
*
* throws exception if the name already exists
*/
void CustomerCollection::addCustomer(Customer &c) {
    if (!nameExists(c.getFullName())) { ///If the name doesnt exist add it
        collection.push_back(&c);
    }
    throw exception();
}

/**
* Attempts to remove the customer from the collection
*
* throws exception if customer doesnt exist
*/
void CustomerCollection::removeCustomer(Customer &c) {
    if (nameExists(c.getFullName())) { ///if the name exists
        collection.erase(std::remove(collection.begin(), collection.end(), &c), collection.end());
    }
    throw exception();
}
