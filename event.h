#include <iostream>
using namespace std;
#pragma once

class event//неподконтрольное событие, которое может случается во время newtick
{
    public: 
    event(string, int);
    protected:
        string name;
        int value;
        

};