#pragma once
#include "item.h"

void item::useItem()
{
    StatVector.plusStat(stat , value);
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

item::item(std::string newName, int newValue): name(newName), value(newValue)
{}