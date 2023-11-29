#pragma once
#include <ctime>
#include "voids.cpp"
#include "Game.h"

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
    if (ticks == tickcount)
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

void Game::endgame(int code = 0)
{
        if (zeroEvents.DeleteOrCheck("check") == false)
            zeroEvents.DeleteOrCheck();
    switch (code)
    {
        case 1:
            std::cout<<"\nIn development\n";
            break;
        default:    
            std::cout<<"\nNot enough stamina for life. You dead. Input something to exit([1]Info).\n"; 
            int num = input();
            switch(num)
            {
                case 1:
                    std::cout<<"\nInfo\n";
                    std::cout<<Player.stamina.GET()<<std::endl<<Player.Base.GET()<<std::endl;
            }
    }
    system("pause");
    exit(0);
}

Game::Game(int newtickcount):tickcount(newtickcount)
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