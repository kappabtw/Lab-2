#pragma once
#include "zeroevent.h"
#include "vector.cpp"

zeroevent::zeroevent(string ename, auto* ptr):event(ename, 0)
{   
    zeroeventVector zero;
    zero.push(ename);
    delete[] ptr;
    delete ptr;
}