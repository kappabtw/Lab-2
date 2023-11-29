#include <iostream>
using namespace std;
#pragma once

class event//неподконтрольное событие, которое может случается во время newtick
{
    public: 
    event(string ename, int evalue):name(ename), value(evalue){}
    protected:
        string name;
        int value;
        

};