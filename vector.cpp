#include <iostream>
using namespace std;
#include <vector>
#pragma once

vector<string>* vectorevents = new vector<string>;
bool vdel = false;

void push(string text = "")
{   
    if (text.empty())
    {
        cerr<<"text of event is empty";
    }
    if (text.empty() == false)
    {
        vectorevents->push_back(text);
    }
}

bool delzeroevents(string arg = "delete")
{
    if ((arg != "delete")&&(arg != "check"))
    {
        cerr<<"Wrong argument in delevents["<<arg<<"]";
    }
    if (arg == "check")
    {
        return vdel;
    }
    if (arg == "delete")
    {
        free(vectorevents);
        vdel = true;
        return vdel;
    }
}