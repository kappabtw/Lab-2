#pragma once
#include <iostream>
#include <vector>
#include "vector.h"

std::vector<std::string> *zerovector = new std::vector<std::string>;
std::vector<int> *buffvector = new std::vector<int>(3);
std::vector<int> *ALLSTAMINA = new std::vector<int>(2);
std::vector<int> *ALLSTATS = new std::vector<int>(3);


BuffVector::BuffVector()
{
    buffvector->at(0) = 0; //INT
    buffvector->at(1) = 0; //STR
    buffvector->at(2) = 1; //EDU
}

bool zeroeventVector::DeleteOrCheck(std::string argument = "delete")
{
    if (argument == "check")
    {
        return IsDelete;
    }
    else if (argument == "delete")
    {
        free(zerovector); //очищает память, выделенную под zerovector
        IsDelete = true;
        return true;
    }
    std::cerr<<"Wrong argument in delzeroevents["<<argument<<"], nothing is deleted, returned "<<IsDelete;
    return IsDelete;
}

void zeroeventVector::push(std::string object = "") //добавляет в вектор текст (если введена не пустая строка)
{   

    if (object.empty())
    {
        std::cerr<<"text of event is empty";
    }
    else if (DeleteOrCheck("check") == false)
    {
        zerovector->push_back(object);
    }
}

int zeroeventVector::maxIndex()
{
    return (zerovector->size() - 1);
}

int zeroeventVector::minIndex() const
{
    return minindex;
}

std::string zeroeventVector::getEvent(int INDEX)
{

    return (zerovector->at(INDEX));
}

void BuffVector::setBuff(std::string STAT, int VALUE)
{   
    if (STAT == "INT")
        buffvector->at(0) = VALUE;
    else if (STAT == "STR")
        buffvector->at(1) = VALUE;
    else if (STAT == "EDU")
        buffvector->at(2) = VALUE;
}

int BuffVector::getBuff(std::string STAT)
{   
    if (STAT == "INT")
        return (buffvector->at(0));
    else if (STAT == "STR")
        return (buffvector->at(1));
    else if (STAT == "EDU")
        return (buffvector->at(2));
    std::cerr<<"Bad argument in getBuff(STAT), returning zero...";
    return 0;
}

void Stamina::Change(int count)
{
    int beforeSTA= ALLSTAMINA -> at(index);
    int sum = beforeSTA+count;
    ALLSTAMINA->at(index) = sum;
}

int Stamina::GET()
{
    return ALLSTAMINA->at(index);
}

void Stamina::reboot()
{
    ALLSTAMINA -> at(0) = 0;
}

void STATS::reboot(int INT, int STR, int EDU)
{
    ALLSTATS ->at(0) = INT;
    ALLSTATS ->at(1) = STR;
    ALLSTATS ->at(2) = EDU;
}

int STATS::converteSTAT(std::string STAT)
{
    if (STAT == "INT")
        return 0;
    else if (STAT == "STR")
        return 1;
    else if (STAT == "EDU")
        return 2;
    else 
        std::cerr<<"Wrong STAT in coverteSTAT, returned -1";
        return -1;
}

void STATS::plusStat(std::string STAT, int count)
{
    int beforeStat = ALLSTATS->at(converteSTAT(STAT));
    ALLSTATS->at(converteSTAT(STAT)) = (count + beforeStat);
}

void STATS::setStat(std::string STAT, int value)
{
    ALLSTATS->at(converteSTAT(STAT)) = value;
}

int STATS::getStat(std::string STAT)
{
    return (ALLSTATS->at(converteSTAT(STAT)));
}



