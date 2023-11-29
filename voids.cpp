#include <iostream>
#include <sstream>
#include <limits>
#pragma once

int input() // вводимый пользователем символ приобразуется в число
{
    std::string in;
    int out;
    std::stringstream container; // check
    std::cin.clear();            // на случай, если предыдущий ввод завершился с ошибкой
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
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
