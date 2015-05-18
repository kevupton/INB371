#include "moviecollection.h"
#include <map>

///Gets the movie by the ID of the movie
Movie &MovieCollection::get(int id) {
    map<int,Movie*>::iterator it;
    it = collection.find(id);
    return *(*it).second;
}
