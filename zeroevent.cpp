#include "zeroevent.h"
#include "vector.cpp"

zeroevent::zeroevent(string ename, auto* ptr):event(ename, 0)
{   
    pushzero(ename);
    delete[] ptr;
    delete ptr;
}