#pragma once
#include "zeroevent.h"
#include "vector.cpp"

zeroevent::zeroevent(std::string ename, auto* ptr):event(ename, 0)
{   
    zeroeventVector zero;
    zero.push(ename);
    delete[] ptr;
    delete ptr;
}