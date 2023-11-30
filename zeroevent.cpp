#pragma once
#include "zeroevent.h"
#include "vector.cpp"

zeroevent::zeroevent(std::string ename, zeroevent *somezero):event(ename, 0)
{   
    zeroeventVector zero;
    zero.push(ename);
    delete[] somezero;
    delete somezero;
}