#include "ini.cpp"

void stats()
{
    kitchen.SetCurrentLocation();
    int res;
    std::string newName;
    int freestat = 10;
    int stat = 0;
    int newINT;
    int newSTR;
    std::cout<< "Enter your nickname:\n\n";
    std::cin>>newName;
    while (newName.empty())
    {
        getline(std::cin,newName);
    }
    std::cout<< "\nYou have "<<freestat<<" free stat points. \nThere are three main characteristics: intelligence, strength and endurance.\n";
    std::cout<< "Stamina will be restored every "<<game.getCountOfMaxTicks()<<" ticks.\n";
    std::cout<< "For each characteristic that reaches its maximum value[5], 1 more stamina is restored\n";
    std::cout << "They will change as the game progresses, but now you can choose the initial characteristics [min 1 , max 5].\n";
    while (stat != 1)
    {
        std::cin.clear();
        std::cout<<"\nEnter your intelligence [1-5]:\n\n";
        res = game.input();
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
                std::cout << "\nError. Try again\n";
                break;
        }
    }

    while (stat != 2) //Stre
    {
        std::cout<<"\nEnter your strenght [1-5]:\n\n";
        res = game.input();
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
                    std::cout<<"\nYou need more strenght...\n";
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
                    std::cout<<"You need some free stat points to endurance";
                    break;
                }   
            
            default:
                std::cout << "\nError. Try again\n";
                break;
        }   
    }
    game.OnTheStart(newName, newINT, newSTR, freestat);
    game.newtick();
    
}

