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

    
    if ((stat != "STA")&&(NeedStatForAction >= Stats.getStat(stat)))
    {
        return false;
    }
    if (stat == "STA")
    {
        stamina.Change(value);
        return true;
    }
    else if (stat=="INT"||stat=="EDU"||stat=="STR")
        Stats.plusStat(stat, value); 
        return true;
    std::cerr<<"\nWrong stat in action]\n";
    return false;

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