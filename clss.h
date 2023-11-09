#include <iostream>
using namespace std;

class Person {  
    public:          
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
        int endu = 0;
        int inte = 0;
        int stre = 0;
        int bufinte = 0;
        int bufendu = 1;//кол-во восстанавливаемой стамины
        int bufstre = 0;
        int stamina = 0;
        int basestamina = 0;
        int base = 0;


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
        location(string name): locationname(name)
        {}
        string Name();
    private:
        string locationname;
};

class event//неподконтрольное событие, которое может случается во время newtick
{
    public: 
    event(string ename, int evalue):name(ename), value(evalue)
    {}
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
        item(string iname, int ivalue): name(iname), value(ivalue)
        {}
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
        action(string iname, int ivalue, int ineedstat, int iactive): name(iname), value(ivalue), needstat(ineedstat), active(iactive)// name value needstat active
        {} 
    protected:
        string name;
        string stat;
        int value = 0;
        int needstat = 0;
        int active = 1; //по умолчанию действие увеличивает кол-во тиков на 1;если значение равно 0, то действие пассивное
};

class actionINT : public action
{
    public:
        actionINT(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {
            stat = "INT";
        }
};

class actionSTR : public action
{
     public:
        actionSTR(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {
            stat = "STR";
        }
};

class actionEDU : public action
{
     public:
        actionEDU(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {
            stat = "EDU";
        }
};

class actionSTA : public action
{
     public: 
        actionSTA(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {
            stat = "STA";
        }
};

class itemINT : public item
{   
    public:
        itemINT(string iname, int ivalue):item(iname,ivalue)
        {
            stat = "INT";
        }
      
};

class itemSTR : public item
{
    public:
        itemSTR(string iname, int ivalue):item(iname,ivalue)
        {
            stat = "STR";
        }
};

class itemEDU : public item
{
    public:
            itemEDU(string iname, int ivalue):item(iname,ivalue)
            {
                stat = "EDU";
            }
};

class itemSTA : public item
{
    public:
        itemSTA(string iname, int ivalue):item(iname,ivalue)
        {
            stat = "STA";
        }
};
