#include <iostream>
using namespace std;
#include <sstream>
#include <limits>
#pragma once

int input() //todo сделать проверку для каждого вводимого символа, пока что любой символ(кроме чисел) является нулем 
{   
    string in;
    int out;
    stringstream container; //check
    cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin>>in;
    if (in.empty())
    {
        return false;
    }
    container<<in; 
    container>>out;
    container.clear();
    return out;
} 

int random(int a, int b)
{
    int c = a + rand()%b;
    return c;
}
