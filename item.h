#pragma once
#include "Game.h"
#include "Person.h" 

class item 
{ 
    public:
        item(Game SomeGame, Person SomePerson,std::string newName, int newValue);
        virtual void useItem();
        std::string getName();
        std::string getStat();
        int getValue();
    protected:
        Person Player;
        Game game{Player, 4};
        std::string stat;
        std::string name;
        int value;
};