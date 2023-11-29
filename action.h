#pragma once
#include <iostream>
#include "vector.cpp"

class action 
{
    public:
        action(std::string newName,std::string newStat,int newValue, int newNeedStat);
        bool DoAction();
        int getValue();
        std::string getStat();
        std::string getName();
        void ChangeValue(int newValue);
        void ChangeStat(std::string newStat);
        void MakeActive(); 
        void MakePassive();

        STATS Stats; 
    protected:
        std::string name;
        std::string stat;
        int value;
        int NeedStatForAction;
        int IsActive;
};
