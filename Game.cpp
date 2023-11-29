#pragma once
#include <ctime>
#include <ctime>
#include <sstream>
#include <limits>
#include "Game.h"

int Game::random(int min, int max) // случайное число от a до b включительно
{
    int output = min + rand() % max;
    return output;
}

int Game::input() // вводимый пользователем символ приобразуется в число
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
int Game::getCountOfMaxTicks()
{
    return maxtickcount;
}


void Game::newtick()
{
    Player.calculate();
    if (Player.stamina.GET() <= 0) //если во время нового тика стамина игрока <= 0, то вызвывается endgame с аргументом 0
    {
        endgame(0);
    }
    if (zeroEvents.DeleteOrCheck("check") == false) //если vectorevents не удалён, то каждый тик происходит случайное событие без влияния на очки статистик
    {
        int index = random(zeroEvents.minIndex() , zeroEvents.maxIndex());
        std::cout<<"\n"<<zeroEvents.getEvent(index); 
    }
    ticks++;
    if (ticks == maxtickcount)
    {
        Player.stamina.Change(Player.recoveringSTA());
        std::cout<<"\nStamina is recovered! ["<<Player.recoveringSTA()<<"]";
        ticks = 0;
    }
    std::cout<<"\nCurrent Location - ["<<currentloc.GetCurrentLocation()<<"]\n";
    std::cout<<"\n----------------------------------------\n";
    std::cout<<"[STA - "<<Player.stamina.GET()<<"] [INT - "<<Player.stats.getStat("INT")<<"] [STR - "<<Player.stats.getStat("STR")<<"] [EDU - "<<Player.stats.getStat("EDU")<<"]\n";
    std::cout<<"----------------------------------------\n";
}

void Game::endgame(int NumOfEnd= 0)
{
        if (zeroEvents.DeleteOrCheck("check") == false)
            zeroEvents.DeleteOrCheck();
    switch (NumOfEnd)
    {
        case 1:
            std::cout<<"\nIn development\n";
            break;
        default:    
            std::cout<<"\nNot enough stamina for life. You dead. Input something to exit([1]Info).\n"; 
            int info = input();
            switch(info)
            {
                case 1:
                    std::cout<<"\nInfo\n";
                    std::cout<<Player.stamina.GET()<<std::endl<<Player.Base.GET()<<std::endl;
            }
    }
    system("pause");
    exit(0);
}

Game::Game(int newtickcount):maxtickcount(newtickcount)
{
    ticks = 0;
    srand(time(0));
}

void Game::OnTheStart(std::string setName, int INT, int STR, int EDU) // работает
{
    Player.Base.reboot();
    Player.stamina.reboot();
    Player.stats.reboot(INT, STR, EDU);
    Player.startstamina();
    
}