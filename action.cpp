#include "action.h"
void action::ChangeValue(int newValue)
{
    value = newValue;
}

void action::ChangeStat(std::string newStat)
{
    stat = newStat;
}

bool action::DoAction()
{
    
    if (NeedStatForAction >= Stats.getStat(stat))
    {
        return false;
    }
    Stats.plusStat(stat, value); 
    return true;

}
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

action::action(std::string newName, std::string newStat,int newValue = 0,int newNeedStat = 0): name(newName), NeedStatForAction(newNeedStat), stat(newStat), value(newValue)
{}