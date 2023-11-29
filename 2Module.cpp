#include "ini.cpp"

void start()
{
    switch (random(1, 6))
    {
        case 1:
        case 2:
            wakeup.ChangeValue(4);
            std::cout<<"\nYou woke up cheerful and energetic => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<std::endl;
            break;
        case 3:
        case 4:
        case 5:
            wakeup.ChangeValue(2);
            std::cout<<"You woke up and got out of bed. Nothing unusual, you slept for 8 hours => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<std::endl;
            break;
        case 6:
            wakeup.ChangeValue(-2);
            std::cout<<"You slept for 4 hours and feel terrible => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<std::endl;
            break;
    }
    wakeup.DoAction();
    game.newtick();
    wakeup.DoAction();
    game.newtick();
    wakeup.DoAction();
    game.newtick();
}