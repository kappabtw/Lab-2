#pragma once
#include "Game.cpp"

int Game::Person::INT()
{
    return stats.getStat("INT");
}
int Game::Person::STR()
{
    return stats.getStat("STR");
}
int Game::Person::EDU()
{
    return stats.getStat("EDU");
}
int Game::Person::STA()
{
    return (stamina.GET());
}

void Game::Person::BaseStamina::Change(int count)
{
    ALLSTAMINA->at(index) = count;
}

void Game::Person::setName(string change)
{
    nameperson = change; 
}

string Game::Person::getName()
{
    return nameperson;
}

int Game::Person::recoveringSTA() //если выносливость достигает максимального значения, то bufendu присваивается значение 2
{
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

void Game::Person::startstamina() //считает базовую стамину, после чего присваивает значение базовой текущей стамине
{
    base = 3*EDU() + 2*STR() - 2*INT();
    stamina.Change(base);
}

void Game::Person::calculate(int dosome) //высчитывает кол-во стамины после дейсвтия, требующее стамины кол-ва dosome
{ 
    
    base = stamina.GET() - Base.GET(); //считает разницу между базвовой и настоящей стаминой
    Base.Change(3*EDU() + 2*STR() - 2*INT()); //высчитывает базовую стамину
    if (dosome > 0) //если dosome больше нуля, то...
    {
        dosome -= BuffINT(); //от dosome высчитывается bufinte
        dosome -= BuffSTR(); //от dosome высчитывается bufinte
        if (dosome <= 0) //если dosome получился равным нулю или меньше, то dosome приравнивается 1
        {
            dosome = 1;
        }
        base -= dosome; //от base высчитывается значение dosome
    
    }
    stamina.reboot();
    stamina.Change(Base.GET() + base); //стамина приравнивается сумме базовой стамины и получившийся base
}

Game::Person::Person()
{
    base = 0;
}