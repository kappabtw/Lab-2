#pragma once
#include "item.h"

void item::useItem()
{
    if (stat == "STA")
    {
        StaminaVector.Change(value);
        return;
    }
    if((stat== "INT")&&(stat == "STR")&&(stat == "EDU"))
        StatVector.plusStat(stat, value);
        return;
    std::cout<<"Nothing if used, wrong stat in item";
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