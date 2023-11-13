#include "location.h"

string location::Name()
{
    return locationname;
}

location::location(string name):locationname(name){}