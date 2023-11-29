#include "ini.cpp"

void stats()
{

    int res;
    std::string newName;
    int freestat = 10;
    int stat = 0;
    int newINT;
    int newSTR;
    cout<< "Enter your nickname:\n" << endl;
    cin>>newName;
    while (newName.empty())
    {
        getline(cin,newName);
    }
    cout<< "\nYou have "<<freestat<<" free stat points. \nThere are three main characteristics: intelligence, strength and endurance." << endl;
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
                newINT = res;
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
                    newSTR = res;
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
                    newSTR = res;
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
    game.OnTheStart(newName, newINT, newSTR, freestat);
    game.newtick();
    
}

