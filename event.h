#include <iostream>
#pragma once

class event//неподконтрольное событие, которое может случается во время newtick
{
    public: 
    event(std::string ename, int evalue):name(ename), value(evalue){}
    protected:
        std::string name;
        int value;
        

};