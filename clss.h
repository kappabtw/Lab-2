#include <iostream>
using namespace std;

class Person {  
    public:       
        Person();   
        void setName(string);   
        string getName();
        void calculate(int);
        int getbase();
        int getstat(string);
        int getstamina();
        void plusstat(int, string);
        int getebuff();
        void getibuff();
        void getsbuff();
        void startstamina(); //использовать в самом начале для рассчёта базовой стамины

    private: 
        string nameperson;// имя     
        int endu;
        int inte;
        int stre;
        int bufinte;
        int bufendu;//кол-во восстанавливаемой стамины
        int bufstre;
        int stamina;
        int basestamina;
        int base;


};

class Game {
    public: 
        Game(int);
        void newtick(int); //создаёт новый тик
        void endgame(int); //конец игры, todo добавить несколько концовок
    private:
        int ticks; //всего тиков
        int tickcount; //через какое количество тиков восстанавливается стамина
};

class location
{
    public:
        location(string);
        string Name();
    private:
        string locationname;
};

class event//неподконтрольное событие, которое может случается во время newtick
{
    public: 
    event(string, int);
    protected:
        string name;
        int value;
        

};

class zeroevent: public event //событие без изменений stat
{
    public:
        zeroevent(string ename);
};


class item // item newitem(name, value)
{ 
    public:
        item(string, int);
        void use();
    protected:
        string stat;
        string name;
        int value;
};

class action // action newaction(name,value,needstat) 
{          
    public:
        bool donew();
        int getvalue();
        void chvalue(int);
        void act(); //делает дейсвтие пассивным(выносливость всё ещё тратиться)
        void pass(); //делает действие активным
        action(string, int, int);
    protected:
        string name;
        string stat;
        int value;
        int needstat;
        int active; //по умолчанию действие увеличивает кол-во тиков на 1;если значение равно 0, то действие пассивное
};

class actionINT : public action
{
    public:
        actionINT(string, int, int);
};

class actionSTR : public action
{
     public:
        actionSTR(string, int, int);
};

class actionEDU : public action
{
     public:
        actionEDU(string, int, int);
};

class actionSTA : public action
{
     public: 
        actionSTA(string, int, int);
};

class itemINT : public item
{   
    public:
        itemINT(string, int);
      
};

class itemSTR : public item
{
    public:
        itemSTR(string, int);
};

class itemEDU : public item
{
    public:
        itemEDU(string, int);
};

class itemSTA : public item
{
    public:
        itemSTA(string, int);
};
