#include "itemSTAT.h"

itemINT::itemINT(Game SomeGame, Person SomePerson,std::string iname, int ivalue):item(SomeGame,SomePerson,iname,ivalue)
{
    stat = "INT";
}

itemSTR::itemSTR(Game SomeGame, Person SomePerson,std::string iname, int ivalue):item(SomeGame,SomePerson,iname,ivalue)
{
    stat = "STR";
}

itemEDU::itemEDU(Game SomeGame, Person SomePerson,std::string iname, int ivalue):item(SomeGame,SomePerson,iname,ivalue)
{
    stat = "EDU";
}

itemSTA::itemSTA(Game SomeGame, Person SomePerson,std::string iname, int ivalue):item(SomeGame,SomePerson,iname,ivalue)
{
    stat = "STA";
}