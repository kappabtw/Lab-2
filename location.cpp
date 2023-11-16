#include "location.h"
#pragma once

string location::Name()
{
    return locationname;
}

location::location(string name):locationname(name){}