#ifndef _customercollection_h
#define _customercollection_h
#include <string>
#include <vector>

using namespace std;

class App;
class Customer;
class CustomerCollection {
public:
    CustomerCollection(App *a);

    ///Get customer by name or login
    Customer &get(string);
    Customer &getByLogin(string);

    ///Check if name exists
    bool nameExists(string);

    ///Add a customer to the collection
    void addCustomer(Customer &c);

    ///Removes a customer from the collection
    void removeCustomer(Customer &c);
private:
    vector<Customer*> collection;
    App *app;
};

#endif // _customercollection_h
