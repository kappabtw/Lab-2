#pragma once
#include "location.h"

std::vector<std::string> *CURRENTLOCATION = new std::vector<std::string>(1);

std::string location::Name()
{
    return locationname;
}

void location::SetCurrentLocation()
{
    if (locationname != "GAMECURRENTLOCATION")
        CURRENTLOCATION->at(0) = locationname;
}

std::string location::GetCurrentLocation()
{
    return CURRENTLOCATION->at(0);
}

bool location::IsCurrentLocation()
{
    if (CURRENTLOCATION->at(0) == locationname)
    {
        return true;
    }
    else
    {
        return false;
    }
}

location::location(std::string name):locationname(name){}