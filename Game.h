#pragma once
#include <iostream>

class Game {
    public: 
        Game(Person SomePerson,int newtickcount);
        void newtick(int); //создаёт новый тик todo создать материнский класс tick для game и item
        void endgame(int); //конец игры, todo добавить несколько концовок
    private:
        Person Player;
        int ticks; //всего тиков
        int tickcount; //через какое количество тиков восстанавливается стамина
};