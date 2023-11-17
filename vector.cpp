#include <iostream>
using namespace std;
#include <vector>
#pragma once

vector<string>* vectorevents = new vector<string>;

bool zerodel = false; //true - vectorevents удален, false - не удалён

bool delzeroevents(string arg = "delete")
{
    if (arg == "check")
    {
        return zerodel;
    }
    if (arg == "delete")
    {
        free(vectorevents); //очищает память, выделенную под vectorevents 
        zerodel = true;
        return true;
    }
    cerr<<"Wrong argument in delzeroevents["<<arg<<"], nothing is deleted, returned "<<zerodel;
    return zerodel;
}

void pushzero(string text = "") //добавляет в вектор текст (если введена не пустая строка)
{   
    if (text.empty())
    {
        cerr<<"text of event is empty";
        return;
    }
    if (delzeroevents("check") == false)
    {
        vectorevents->push_back(text);
    }
}