#pragma once
#include "vector.cpp"

class item 
{ 
    public:
        item(std::string newName, int newValue);
        void useItem();
        std::string getName();
        std::string getStat();
        int getValue();
        STATS StatVector;
    protected:
        std::string stat;
        std::string name;
        int value;
};