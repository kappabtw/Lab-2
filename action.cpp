#include "action.h"
#include "GamePerson.cpp"   
bool action::donew()
{
    Player.plusstat(value , stat);
    game.newtick(active);
    if (needstat < Player.getstat(stat))
    {
        return false;
    }
    return true;
}

void action::chvalue(int a) 
{
    value = a;
}

void action::act()
{
    active = 1;
}

void action::pass()
{
    active = 0;
}

int action::getValue()
{
    return value;
}

string action::getName()
{
    return name;
}

string action::getStat()
{
    return stat;
}

action::action(string iname, int ivalue, int ineedstat): name(iname), value(ivalue), needstat(ineedstat)
{
    active = 1;
} 