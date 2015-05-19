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
private:
    //The app instance
    App app;
    /// clears the cin memory
    void clearCin();
    /**
    Make all the controller methods private :)
    **/
};

#endif // _controller_h
