#include "Person.h"
void Person::setName(string change)
{
    nameperson = change;
}

string Person::getName()
{
    return nameperson;
}

void Person::plusstat(int value, string stat) //(int) value, (str) stat
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

int Person::getstat(string stat)
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

int Person::getstamina()

{
    return stamina;
}

int Person::getebuff()
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

void Person::getibuff()
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

void Person::getsbuff()
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

void Person::startstamina() //работает
{
    basestamina = 3*endu + 2*stre - 2*inte;
    stamina = basestamina;
}

int Person::getbase() //написал для проверки логики
{
    return basestamina;
}

void Person::calculate(int dosome)
{ 
    base = stamina - basestamina;
    basestamina = 3*endu + 2*stre - 2*inte;
    if (dosome > 0)
    {
        dosome -= bufinte;
        dosome -= bufstre;
        if (dosome <= 0)
        {
            dosome = 1;
        }
        base -= dosome;
    
    }
    stamina = basestamina + base;
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