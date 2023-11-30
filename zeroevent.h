#pragma once
#include "vector.cpp"

class zeroevent
{
    public:
        zeroevent(std::string ename, zeroevent *somezero):name(ename)
        {   
            zeroeventVector zero;
            zero.push(ename);
            delete[] somezero;
            delete somezero;
        }
    private:
        std::string name;
};