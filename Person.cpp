#pragma once
#include "Game.cpp"

std::vector<int> *BASESTAMINA = new std::vector<int>(1);

int Game::Person::INT()
{
    int getter = stats.getStat("INT");
    if (getter < 1)
        stats.setStat("INT", 1);
    else if (getter > 5)
        stats.setStat("INT", 5);
    return stats.getStat("INT");
}
int Game::Person::STR()
{
    int getter = stats.getStat("STR");
    if (getter < 1)
        stats.setStat("STR", 1);
    else if (getter > 5)
        stats.setStat("STR", 5);
    return stats.getStat("STR");
}
int Game::Person::EDU()
{
    int getter = stats.getStat("EDU");
    if (getter < 1)
        stats.setStat("EDU", 1);
    else if (getter > 5)
        stats.setStat("EDU", 5);
    return stats.getStat("EDU");
}

int Game::Person::STA()
{
    return (stamina.GET());
}

void Game::Person::BaseStamina::Change(int count)
{
    BASESTAMINA->at(0) = count;
}

void Game::Person::BaseStamina::reboot()
{
    BASESTAMINA -> at(0) = 0;
}

int Game::Person::BaseStamina::GET()
{
    return BASESTAMINA->at(0);
}

void Game::Person::setName(std::string change)
{
    nameperson = change; 
}

std::string Game::Person::getName()
{
    return nameperson;
}

int Game::Person::recoveringSTA()
{
    return (BuffEDU() + BuffSTR() + BuffINT());
}

int Game::Person::BuffEDU() 
{
    if (EDU() == 5)
    {
        Buff.setBuff("EDU", 2);
    }
    else if (EDU() != 5)
    {
        Buff.setBuff("EDU", 1);
    }
    return Buff.getBuff("EDU");
}

int Game::Person::BuffSTR() 
{
    if (STR() == 5)
    {
        Buff.setBuff("STR", 1);
    }
    else if (STR() != 5)
    {
        Buff.setBuff("STR", 0);
    }
    return Buff.getBuff("STR");
}

int Game::Person::BuffINT()  
{
    if (INT() == 5)
    {
        Buff.setBuff("INT", 1);
    }
    else if (INT() != 5)
    {
        Buff.setBuff("INT", 0);
    }
    return Buff.getBuff("INT");
}

void Game::Person::startstamina()
{
    Base.Change(3*EDU() + 2*STR() - 2*INT());
    stamina.Change(Base.GET());
}

void Game::Person::calculate() //высчитывает кол-во стамины после дейсвтия, требующее стамины кол-ва dosome
{ 
    base = STA() - Base.GET(); //считает разницу между базвовой и настоящей стаминой
    Base.Change(3*EDU() + 2*STR() - 2*INT()); //высчитывает базовую стамину
    stamina.reboot();
    stamina.Change(Base.GET() + base); 
}

Game::Person::Person()
{
    base = 0;
}