#include "ini.cpp"

void stats()
{
    int res;
    string in;
    int freestat = 10;
    int stat = 0;
    cout<< "Enter your nickname:\n" << endl;
    cin>>in;
    while (in.empty())
    {
        getline(cin,in);
    }
    Player.setName(in);
    cout<< "\nYou have 10 free stat points. \nThere are three main characteristics: intelligence, strength and endurance." << endl;
    cout << "They will change as the game progresses, but now you can choose the initial characteristics [min 1 , max 5]." << endl;
    while (stat != 1)
    {
        cin.clear();
        cout<<"\nEnter your intelligence [1-5]:\n" << endl;
        res = input();
        switch(res)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                Player.plusstat(res, "INT");
                freestat -= res;
                stat++;
                break;
            default: 
                cout << "\nError. Try again" << endl;
                break;
        }
    }

    while (stat != 2) //Stre
    {
        cout<<"\nEnter your strenght [1-5]:\n"<<endl;
        res = input();
        switch(res)
        {
            case 1:
            case 2:
            case 3:
            case 4:
                if ((freestat - res)<= 5)
                {
                    Player.plusstat(res, "STR");
                    freestat -= res;
                    stat++;
                    break;
                }
                else
                {
                    cout<<"\nYou need more strenght...\n";
                    break;
                }
            case 5:
                if (freestat>>5)
                {
                    Player.plusstat(res, "STR");
                    freestat -= res;
                    stat++;
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
    Player.plusstat(freestat, "EDU");
    Player.startstamina();
    game.newtick(0);
}
