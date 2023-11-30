#pragma once
#include "zeroevent.cpp"
#include <iostream>


class Game {
    public: 

        Game(int newtickcount);
        void interface();
        int getCountOfMaxTicks();
        int input();
        int random(int min, int max);
        void newtick(); 
        void endgame(int NumOfEnd);
        void OnTheStart(std::string newName, int INT, int STR, int EDU);

        class Person {  
            friend class Game;
            public:

                Person();
                void setName(std::string newName);
                int recoveringSTA(); 
                int BuffEDU();
                int BuffSTR();
                int BuffINT();
                std::string getName();
                void calculate();
                void startstamina();

                class BaseStamina: public Stamina
                {
                    public:
                        void Change(int count) override;
                        void reboot() override;
                        int GET() override;
                };
                
            private: 
                std::string nameperson;// имя     
                int INT();
                int STR();
                int EDU();
                int STA();
                int base;
                BuffVector Buff;
                BaseStamina Base;
                Stamina stamina;
                STATS stats;
        };
    private:
        int ticks; //всего тиков
        const int maxtickcount; //через какое количество тиков восстанавливается стамина
        Person Player;
        zeroeventVector zeroEvents;
        location currentloc{"GAMECURRENTLOCATION"};
};