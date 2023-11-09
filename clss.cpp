#include <clss.h>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <ctime>
using namespace std;

int res = 0;
string in;
string* arr;
string* arr2;
int num = 0;

Person Player;
Game game{4};


int random(int a, int b)
{
    int c = a + rand()%b;
    return c;
}

void inf()
{
    cout<<"\n----------------------------------------"<<endl;
    cout<<"[STA - "<<Player.getstamina()<<"] [INT - "<<Player.getstat("INT")<<"] [STR - "<<Player.getstat("STR")<<"] [EDU - "<<Player.getstat("EDU")<<"]"<<endl;
    cout<<"----------------------------------------"<<endl;
}

int input() //todo сделать проверку для каждого вводимого символа, пока что любой символ(кроме чисел) является нулем 
{   
    stringstream container;
    cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, in);
    container<<in; 
    container>>res;
    container.clear();
    return res;
} 

void Person::setName(string name1)
{
    nameperson = name1;
}

string Person::getName()
{
    return nameperson;
}

void Person::plusstat(int value, string stat) //(int) value, (str) stat
{
    if (stat == "INT")
    {
        inte += value;
        if (inte > 5)
            {
                inte = 5;
            }
        if (inte < 1)
        {
            inte = 1;
        }
        return;
    }
    if (stat == "STR")
    {
        stre += value;
        if (stre > 5)
            {
                stre = 5;
            }
        if (stre < 1)
        {
            stre = 1;
        }
        return;
    }
    if (stat == "EDU")
    {
        
        endu += value;
        if (endu > 5)
            {
                endu = 5;
            }
        if (endu < 1)
        {
            endu = 1;
        }
        return;
    }
    if (stat == "STA")
    {
        stamina += value;
        return;
    }
    cerr<<"Wrong in plusstat("<<stat<<"), returned 0";
}

int Person::getstat(string stat)
{
    if (stat == "INT")
    {
        return inte;
    }
    if (stat == "STR")
    {
        return stre;
    }
    if (stat == "EDU")
    {
        return endu;
    }
    if (stat == "STA")
    {
        return stamina;
    }
    cerr<<"Wrong in getstat("<<stat<<"), returned 0";
    return 0;
}

int Person::getstamina()

{
    return stamina;
}

int Person::getebuff()
{
    if (endu == 5)
    {
        bufendu = 2;
    }
    else
    {
        bufendu = 1;
    }
    return bufendu;
}

void Person::getibuff()
{
    if (inte == 5)
    {
        bufinte = 1;
    }
    else 
    {
        bufinte = 0;
    }
}

void Person::getsbuff()
{
    if (stre == 5)
    {
        bufstre = 1;
    }
    else 
    {
        bufstre = 0;
    }
}

void Person::startstamina() //работает
{
    basestamina = 3*endu + 2*stre - 2*inte;
    stamina = basestamina;
}

int Person::getbase() //написал для проверки логики
{
    return basestamina;
}

void Person::calculate(int dosome)
{ 
    base = stamina - basestamina;
    basestamina = 3*endu + 2*stre - 2*inte;
    if (dosome >> 0)
    {
        dosome -= bufinte;
        dosome -= bufstre;
        if (dosome <= 0)
        {
            dosome = 1;
        }
        base -= dosome;
    
    }
    stamina = basestamina + base;
}


Game::Game(int b):tickcount(b)
{
    ticks = 0;
    srand(time(0));
}


void Game::newtick(int a = 0)
{
    Player.getsbuff();
    Player.getibuff();
    Player.calculate(0);
    if (Player.getstamina() <= 0)
    {
        endgame(0);
    }
    switch (random(0,1))
    {
        case 1:
            cout<<"...";
            break;
        case 0:
            cout<<endl<<arr[(random((0),(num - 1)))];
            break;
    }
    if (a != 0)      //каждый tickcount тик восстанавливает стамину(если значение не равно нулю)
    {
        ticks++;
        if (ticks == tickcount)
        {
            Player.plusstat(Player.getebuff(), "STA");
            ticks = 0;
        }
    }
    inf();
}

void Game::endgame(int code = 0)
{
    switch (code)
    {
        case 1:
            cout<<"\nIn development\n";
            break;
        default:    
            cout<<"\nNot enough stamina for life. You dead. Input something to exit([1]Info).\n"; 
            res = input();
            switch(res)
            {
                case 1:
                    cout<<"\nInfo\n";
                    cout<<Player.getstamina()<<endl<<Player.getbase()<<endl;
            }
    }
    system("pause");
    exit(0);
}


string location::Name()
{
    return locationname;
}

void item::use()
{
    Player.plusstat(value, stat);
    game.newtick(0);
}

bool action::donew()
{
    Player.plusstat(value , stat);
    game.newtick(active);
    if (needstat << Player.getstat(stat))
    {
        return false;
    }
    return true;
}

void action::chvalue(int a) 
{
    value = a;
}

void action::act()
{
    active = 1;
}

void action::pass()
{
    active = 0;
}

int action::getvalue()
{
    return value;
}  

zeroevent::zeroevent(string ename):event(ename, 0)
{   
    num++;
    arr2 = new string[num];
    for (int i = 0; i < (num - 1); i++)
        arr2[i] = arr[i];
    arr2[num - 1] = name;
    delete[] arr;
    arr = arr2;
}
