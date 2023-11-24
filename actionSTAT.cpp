#include "actionSTAT.h"

actionFixedStat::actionFixedStat(Game SomeGame, Person SomePerson, std::string newName,std::string newStat, int newValue, int newNeedStat = 0):action(SomeGame, SomePerson,newName, newStat, newNeedStat)
{}

bool actionFixedStat::DoAction()
{
    if (NeedStatForAction >= Player.getstat(stat)) //если требуемые очки хар-ки >= очкам, которые есть у персонажа, то дейсвие не выполняется 
    {
        return false;
    }
    Player.plusstat(value , stat); //добавляет к очкам статистики stat значение value
    game.newtick(IsActive); //вызывает newtick объекта game с аргументом active
    return true;
}


void actionFixedStat::ChangeValue(int newValue)
{
    value = newValue;
}
