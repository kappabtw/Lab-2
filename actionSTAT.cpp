#include "actionSTAT.h"
#pragma once

actionEDU::actionEDU(string iname, int ivalue, int ineedstat = 0): action(iname,ivalue,ineedstat) //name value needstat active
{
    stat = "EDU";
}

void actionEDU::chvalue(int num, string change = "EDU")
{
    value = num;
    stat = change;
}

actionSTR::actionSTR(string iname, int ivalue, int ineedstat = 0): action(iname,ivalue,ineedstat) //name value needstat active
{
    stat = "STR";
}

void actionSTR::chvalue(int num, string change = "STR")
{
    value = num;
    stat = change;
}

actionINT::actionINT(string iname, int ivalue, int ineedstat = 0): action(iname,ivalue,ineedstat) //name value needstat active
{
    stat = "INT";
}

void actionINT::chvalue(int num, string change = "INT")
{
    value = num;
    stat = change;
}

actionSTA::actionSTA(string iname, int ivalue, int ineedstat = 0): action(iname,ivalue,ineedstat) //name value needstat active
{
    stat = "STA";
}

void actionSTA::chvalue(int num, string change = "STA")
{
    value = num;
    stat = change;
}