#pragma once
#include "Person.h"
void Person::setName(string change)
{
    nameperson = change; 
}

string Person::getName()
{
    return nameperson;
}

void Person::plusstat(int value, string stat) //Добавляет значение value к очкам характеристик stat
{
    if (stat == "INT")
    {
        inte += value;
        if (inte > 5)
            {
                inte = 5;
            }
        if (inte < 1)
        {
            inte = 1;
        }
        return;
    }
    if (stat == "STR")
    {
        stre += value;
        if (stre > 5)
            {
                stre = 5;
            }
        if (stre < 1)
        {
            stre = 1;
        }
        return;
    }
    if (stat == "EDU")
    {
        
        endu += value;
        if (endu > 5)
            {
                endu = 5;
            }
        if (endu < 1)
        {
            endu = 1;
        }
        return;
    }
    if (stat == "STA")
    {
        stamina += value;
        return;
    }
    cerr<<"Wrong in plusstat("<<stat<<"), nothing is changed";
}

int Person::getstat(string stat) //возвращает значение очков характетеристики stat
{
    if (stat == "INT")
    {
        return inte;
    }
    if (stat == "STR")
    {
        return stre;
    }
    if (stat == "EDU")
    {
        return endu;
    }
    if (stat == "STA")
    {
        return stamina;
    }
    cerr<<"Wrong in getstat("<<stat<<"), returned 0";
    return 0;
}

int Person::getstamina() //возвращает количесво стамины

{
    return stamina;
}

int Person::getebuff() //если выносливость достигает максимального значения, то bufendu присваивается значение 2
{
    if (endu == 5)
    {
        bufendu = 2;
    }
    else
    {
        bufendu = 1;
    }
    return bufendu;
}

void Person::getibuff() //если интеллект достигает максимального значения, то bufendu присваивается значение 2
{
    if (inte == 5)
    {
        bufinte = 1;
    }
    else 
    {
        bufinte = 0;
    }
}

void Person::getsbuff()  //если силы достигает максимального значения, то bufendu присваивается значение 2
{
    if (stre == 5)
    {
        bufstre = 1;
    }
    else 
    {
        bufstre = 0;
    }
}

void Person::startstamina() //считает базовую стамину, после чего присваивает значение базовой текущей стамине
{
    basestamina = 3*endu + 2*stre - 2*inte;
    stamina = basestamina;
}

int Person::getbase() //возвращает базовую стамину
{
    return basestamina;
}

void Person::calculate(int dosome) //высчитывает кол-во стамины после дейсвтия, требующее стамины кол-ва dosome
{ 
    base = stamina - basestamina; //считает разницу между базвовой и настоящей стаминой
    basestamina = 3*endu + 2*stre - 2*inte; //высчитывает базовую стамину
    if (dosome > 0) //если dosome больше нуля, то...
    {
        dosome -= bufinte; //от dosome высчитывается bufinte
        dosome -= bufstre; //от dosome высчитывается bufinte
        if (dosome <= 0) //если dosome получился равным нулю или меньше, то dosome приравнивается 1
        {
            dosome = 1;
        }
        base -= dosome; //от base высчитывается значение dosome
    
    }
    stamina = basestamina + base; //стамина приравнивается сумме базовой стамины и получившийся base
}

Person::Person()
{
    endu = 0;
    inte = 0;
    stre = 0;
    bufinte = 0;
    bufendu = 1;
    bufstre = 0;
    stamina = 0;
    basestamina = 0;
    base = 0;
}