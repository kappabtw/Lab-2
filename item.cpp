#include "item.h"
#include "GamePerson.cpp"
#pragma once

void item::use()
{
    Player.plusstat(value, stat);
    game.newtick(0);
}

string item::getName()
{
    return name;
}

string item::getStat()
{
    return stat;
}

int item::getValue()
{
    return value;
}

item::item(string iname, int ivalue): name(iname), value(ivalue){}