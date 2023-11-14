#include "GamePerson.cpp"
#include <ctime>
#include "voids.cpp"
#include "vector.cpp"

void Game::newtick(int a = 1)
{
    Player.getsbuff();
    Player.getibuff();
    Player.calculate(0);
    if (Player.getstamina() <= 0)
    {
        endgame(0);
    }
    if (delzeroevents("check") == false)
    {
        switch (random(0,1))
        {
            case 1:
                cout<<"...";
                break;
            case 0:
                cout<<endl<<vectorevents->at((random((0),(vectorevents->size() - 1))));
                break;
        }
    }
    if (a != 0)      //каждый tickcount тик восстанавливает стамину(если аргумент передаваемый newtick не равен 0)
    {
        ticks++;
        if (ticks == tickcount)
        {
            Player.plusstat(Player.getebuff(), "STA");
            ticks = 0;
        }
    }
    cout<<"\n----------------------------------------"<<endl;
    cout<<"[STA - "<<Player.getstamina()<<"] [INT - "<<Player.getstat("INT")<<"] [STR - "<<Player.getstat("STR")<<"] [EDU - "<<Player.getstat("EDU")<<"]"<<endl;
    cout<<"----------------------------------------"<<endl;
}

void Game::endgame(int code = 0)
{
    if (delzeroevents("check") == false)
        delzeroevents();
    switch (code)
    {
        case 1:
            cout<<"\nIn development\n";
            break;
        default:    
            cout<<"\nNot enough stamina for life. You dead. Input something to exit([1]Info).\n"; 
            int num = input();
            switch(num)
            {
                case 1:
                    cout<<"\nInfo\n";
                    cout<<Player.getstamina()<<endl<<Player.getbase()<<endl;
            }
    }
    system("pause");
    exit(0);
}

Game::Game(int b):tickcount(b)
{
    ticks = 0;
    srand(time(0));
}
