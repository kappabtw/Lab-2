#include "action.h"
void action::ChangeValue()
{}

bool action::DoAction()
{}
void action::MakeActive() //делает действие активным
{
    IsActive = 1;
}

void action::MakePassive()
{
    IsActive = 0; //делает действие пассивным
}

int action::getValue()
{
    return value; //возвращает значение value
}

std::string action::getName()
{
    return name; //возвращение значение name
}

std::string action::getStat()
{
    return stat; //возвращает значение stat
}

action::action(Game SomeGame, Person SomePerson,std::string newName = "Undefinded", std::string newStat = "", int newNeedStat = 0): name(newName), NeedStatForAction(newNeedStat), stat(newStat)
{
    this->game = SomeGame;
    this->Player = SomePerson;
}