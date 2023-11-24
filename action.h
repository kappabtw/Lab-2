#include <iostream>
<<<<<<< Updated upstream
using namespace std;
#pragma once
=======
#include "Person.h"
#pragma once
#include "Game.h"
>>>>>>> Stashed changes

class action 
{
    public:
<<<<<<< Updated upstream
        action(string, int, int);
        virtual bool donew();
        int getValue();
        string getStat();
        string getName();
        virtual void chvalue(int);
        void act(); //делает дейсвтие пассивным(выносливость всё ещё тратиться)
        void pass(); //делает действие активным
=======
        action(Game SomeGame, Person SomePerson, std::string newName,std::string newStat, int newNeedStat);
        virtual bool DoAction();
        int getValue();
        std::string getStat();
        std::string getName();
        virtual void ChangeValue();
        void MakeActive(); 
        void MakePassive(); 
>>>>>>> Stashed changes
    protected:
        Person Player;
        Game game{Player,4};
        std::string name;
        std::string stat;
        int value;
        int NeedStatForAction;
        int IsActive;
};
