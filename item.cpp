#include "item.h"
#include "GamePerson.cpp"
#pragma once
void item::use()
{
    Player.plusstat(value, stat);
    game.newtick(0);
}

item::item(string iname, int ivalue): name(iname), value(ivalue){}