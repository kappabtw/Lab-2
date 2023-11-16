#include <iostream>
using namespace std;
#include <sstream>
#include <limits>
#pragma once

int input() // вводимый пользователем символ приобразуется в число
{
    string in;
    int out;
    stringstream container; // check
    cin.clear();            // на случай, если предыдущий ввод завершился с ошибкой
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> in;
    if (in.empty())
    {
        return false;
    }
    container << in;
    container >> out;
    container.clear();
    return out;
}

int random(int a, int b) // случайное число от a до b включительно
{
    int c = a + rand() % b;
    return c;
}
