#include "itemSTAT.h"

itemINT::itemINT(string iname, int ivalue):item(iname,ivalue)
{
    stat = "INT";
}

itemSTR::itemSTR(string iname, int ivalue):item(iname,ivalue)
{
    stat = "STR";
}

itemEDU::itemEDU(string iname, int ivalue):item(iname,ivalue)
{
    stat = "EDU";
}

itemSTA::itemSTA(string iname, int ivalue):item(iname,ivalue)
{
    stat = "STA";
}