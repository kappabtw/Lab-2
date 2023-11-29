#include "itemSTAT.h"

itemINT::itemINT(std::string iname, int ivalue):item(iname,ivalue)
{
    stat = "INT";
}

itemSTR::itemSTR(std::string iname, int ivalue):item(iname,ivalue)
{
    stat = "STR";
}

itemEDU::itemEDU(std::string iname, int ivalue):item(iname,ivalue)
{
    stat = "EDU";
}

itemSTA::itemSTA(std::string iname, int ivalue):item(iname,ivalue)
{
    stat = "STA";
}