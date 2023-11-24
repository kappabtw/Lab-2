#pragma once
#include "item.h"

void item::useItem()
{
    Player.plusstat(value, stat);
    game.newtick(0);
}

std::string item::getName()
{
    return name;
}

std::string item::getStat()
{
    return stat;
}

int item::getValue()
{
    return value;
}

item::item(Game SomeGame,Person SomePerson, std::string newName, int newValue): name(newName), value(newValue)
{
    this->game = SomeGame;
    this->Player = SomePerson;
}