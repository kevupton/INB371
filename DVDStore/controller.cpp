#include "controller.h"

/**
* Initialises the application
*/
Controller::Controller() {
    App a; app = &a;
    app->initialise();
}
