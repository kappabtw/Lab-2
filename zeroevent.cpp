#include "zeroevent.h"
#include "vector.cpp"

zeroevent::zeroevent(string ename):event(ename, 0)
{   
    push(ename);
}