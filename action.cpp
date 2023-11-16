#include "action.h"
#include "GamePerson.cpp"   
bool action::donew() 
{
    if (needstat >= Player.getstat(stat)) //если требуемые очки хар-ки >= очкам, которые есть у персонажа, то дейсвие не выполняется 
    {
        return false;
    }
    Player.plusstat(value , stat); //добавляет к очкам статистики stat значение value
    game.newtick(active); //вызывает newtick объекта game с аргументом active
    return true;
}

void action::chvalue(int a) //изменяет значение value
{
    value = a;
}

void action::act() //делает действие активным
{
    active = 1;
}

void action::pass()
{
    active = 0; //делает действие пассивным
}

int action::getValue()
{
    return value; //возвращает значение value
}

string action::getName()
{
    return name; //возвращение значение name
}

string action::getStat()
{
    return stat; //возвращает значение stat
}

action::action(string iname, int ivalue, int ineedstat = 0): name(iname), value(ivalue), needstat(ineedstat)
{
    active = 1; //при вызове конструктора автоматически делает действие активным
} 