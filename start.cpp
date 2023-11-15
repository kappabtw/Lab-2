#include "ini.cpp"

void start()
{
    switch (random(1, 6))
    {
        case 1:
        case 2:
            wakeup.chvalue(4);
            cout<<"\nYou woke up cheerful and energetic => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<endl;
            break;
        case 3:
        case 4:
        case 5:
            wakeup.chvalue(2);
            cout<<"You woke up and got out of bed. Nothing unusual, you slept for 8 hours => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<endl;
            break;
        case 6:
            wakeup.chvalue(-2);
            cout<<"You slept for 4 hours and feel terrible => "<<wakeup.getValue()<<" to "<<wakeup.getStat()<<endl;
            break;
    }
    wakeup.donew();
}