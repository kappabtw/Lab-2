#include <clss.h>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

int res = 0;
string in;


Person Player;
Game game;

string arr[10] {};

int random(int a, int b)
{
    int c = a + rand()%b;
    return c;
}

void inf()
{
    cout<<"\n----------------------------------------"<<endl;
    cout<<"[STA - "<<Player.getstamina()<<"] [INT - "<<Player.getInte()<<"] [STR - "<<Player.getStre()<<"] [EDU - "<<Player.getEndu()<<"]"<<endl;
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

void Person::plusInte(int num)
{
    inte += num;
    if (inte > 5)
    {
        megastat += (inte - 5);
        inte = 5;
    }

    if (inte < 1)
    {
        minstat += (1 - inte);
        inte = 1;
    }
}

void Person::plusStre(int num)
{
    stre += num;
    if (stre > 5)
    {
        megastat += (stre - 5);
        stre = 5;
    }
    if (inte < 1)
    {
        minstat += (1 - stre);
        stre = 1;
    }
}

void Person::plusEndu(int num)
{
    endu += num;
    if (inte > 5)
    {
        megastat += (endu - 5);
        endu = 5;
    }
    if (endu < 1)
    {
        minstat += (1 - endu);
        endu = 1;
    }
}

int Person::getInte()
{
    return inte;
}

int Person::getStre()
{
    return stre;
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

void Person::plusstamina(int a)
{
    stamina+=a;
}

int Person::getEndu()
{
    return endu;
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



void Game::newtick(int a)
{
    Player.getsbuff();
    Player.getibuff();
    Player.calculate(0);
    if (Player.getstamina() <= 0)
    {
        endgame();
    }
    switch (random(0,1))
    {
        case 0:
        case 1:
            cout<<endl<<arr[random(0 , size(arr))];
            cout<<"here";
            break;
    }
    if (a != 0)      //каждый tickcount тик восстанавливает стамину(если значение не равно нулю)
    {
        ticks++;
        if (ticks == tickcount)
        {
            Player.plusstamina(Player.getebuff());
            ticks = 0;
        }
    }
    inf();
}


void Game::endgame()
{
    cout<<"Not enough stamina for life. You dead. Input something to exit([1]Info)."; 
    res = input();
    switch(res)
    {
        case 1:
            cout<<"\nInfo\n";
            cout<<Player.getstamina()<<endl<<Player.getbase();
            cin>>res;
    }
    exit(0);
}


string location::Name()
{
    return locationname;
}

void itemINT::use()
{
    Player.plusInte(value);
    game.newtick(0);
}

void itemSTR::use()
{
    Player.plusStre(value);
    game.newtick(0);
}

void itemEDU::use()
{
    Player.plusEndu(value);
    game.newtick(0);
}

void itemSTA::use()
{
    Player.plusstamina(value);
    game.newtick(0);
}

bool actionINT::donew()
{
    Player.plusInte(value);
    game.newtick(active);
    if (needstat << Player.getInte())
    {
        return false;
    }
    return true;
}


bool actionSTR::donew()
{
    Player.plusStre(value);
    game.newtick(active);
    if (needstat << Player.getStre())
    {
        return false;
    }
    return true;
}

bool actionEDU::donew()
{
    Player.plusEndu(value);
    game.newtick(active);
    if (needstat << Player.getEndu())
    {
        return false;
    }
    return true;
}


bool actionSTA::donew()
{
    Player.plusstamina(value);
    game.newtick(active);
    if (needstat << Player.getstamina())
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

event::event(string ename, int evalue):name(ename), value(evalue)
{   
    if (num<<10)
        arr[num] = name;
        num++;
}