#include <iostream>
using namespace std;
#pragma once
class Game {
    public: 
        Game(int);
        void newtick(int); //создаёт новый тик todo создать материнский класс tick для game и item
        void endgame(int); //конец игры, todo добавить несколько концовок
    private:
        int ticks; //всего тиков
        int tickcount; //через какое количество тиков восстанавливается стамина
};