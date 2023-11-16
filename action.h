#include <iostream>
using namespace std;
#pragma once

class action // action newaction(name,value,needstat) 
{          
    public:
        action(string, int, int);
        bool donew();
        int getValue();
        string getStat();
        string getName();
        virtual void chvalue(int);
        void act(); //делает дейсвтие пассивным(выносливость всё ещё тратиться)
        void pass(); //делает действие активным
    protected:
        string name;
        string stat;
        int value;
        int needstat;
        int active; //по умолчанию действие увеличивает кол-во тиков на 1;если значение равно 0, то действие пассивное
};