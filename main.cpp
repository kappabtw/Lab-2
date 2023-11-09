#include <D:\Code\Project\lab1\lab2\Lab2\clss.cpp>
#include <cstring>
#include <math.h>

//инициализация

location kitchen{"Kitchen"};
itemINT gre{"Grechka dada", 2};
actionSTA wakeup{"Wakeup", 0, 0, 0};
zeroevent event1{"event1"};
zeroevent event2{"event2"};
zeroevent event3{"event3"};
zeroevent event4{"event4"};
zeroevent event5{"event5"};
zeroevent event6{"event6"};
zeroevent event7{"event7"};

void stats()
{
    int freestat = 10;
    int chars = 0;
    cout<< "Enter your name:\n" << endl;
    getline(cin, in);
    Player.setName(in);
    cout<< "\nYou have 10 free stat points. \nThere are three main characteristics: intelligence, strength and endurance." << endl;
    cout << "They will change as the game progresses, but now you can choose the initial characteristics [min 1 , max 5]." << endl;
    while (chars != 1) //Inte
    {
        cout<<"\nEnter your intelligence [1-5]:\n" << endl;
        res = input();
        switch(res)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                Player.plusInte(res);
                freestat -= res;
                chars++;
                break;
            default: 
                cout << "\nError. Try again" << endl;
                break;
        }
    }

    while (chars != 2) //Stre
    {
        cout<<"\nEnter your strenght [1-5]:\n" << endl;
        res = input();
        switch(res)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                if ((freestat - res)<= 5)
                {
                    Player.plusStre(res);
                    freestat -= res;
                    chars++;
                    break;
                }
                else
                {
                    cout<<"\nYou need more strenght...\n";
                    break;
                }
            case 5:
                if (freestat>5)
                {
                    Player.plusStre(res);
                    freestat -= res;
                    chars++;
                    break;
                }
                else 
                {
                    cout<<"You need some free stat points to endurance";
                    break;
                }   
            
            default:
                cout << "\nError. Try again" << endl;
                break;
        }   
    }
    Player.plusEndu(freestat);
    Player.startstamina();
    game.newtick(0);
}

void start()
{
    res = random(1, 7);
    switch (res)
    {
        case 1:
        case 2:
        case 3:
            wakeup.chvalue(4);
            cout<<"\nYou woke up cheerful and energetic [+"<<wakeup.getvalue()<<" to STA]"<<endl;
            break;
        case 4:
        case 5:
        case 6:
            wakeup.chvalue(2);
            cout<<"You woke up and got out of bed. Nothing unusual, you slept for 8 hours [+"<<wakeup.getvalue()<<" to STA]"<<endl;
            break;
        case 7:
            wakeup.chvalue(-2);
            cout<<"You slept for 4 hours and feel terrible ["<<wakeup.getvalue()<<" to STA]"<<endl;
            break;
    }
    wakeup.donew();
}

int main()
{
    stats();
    start();
    game.endgame(1);
}