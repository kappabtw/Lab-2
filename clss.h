#include <iostream>
using namespace std;

class Person {      //todo убрать половину функций - (+-)
    public:         //todo сделать универсальную plusstat(int, stat) 
        void setName(string);   
        string getName();
        int getEndu(); //chars
        void plusInte(int);
        void plusStre(int);
        void plusEndu(int);
        int getInte(); //chars
        int getStre(); //chars
        void calculate(int);
        int getbase();
        int getstamina();
        void plusstamina(int);
        int getebuff();
        void getibuff();
        void getsbuff();
        void startstamina(); //использовать в самом начале для рассчёта базовой стамины

    private: 
        string nameperson;// имя     
        int endu = 0;
        int inte = 0;
        int stre = 0;
        int megastat = 0;
        int minstat = 0; //чтобы балансировать игру(?на будущее?)
        int bufinte = 0;
        int bufendu = 1;//кол-во восстанавливаемой стамины
        int bufstre = 0;
        int stamina = 0;
        int basestamina = 0;
        int base = 0;


};

class Game {
    public: 
        Game(int b):tickcount(b)
        {
            ticks = 0;
        }
        void newtick(int); //создаёт новый тик
        void endgame(int = 0); //конец игры, todo добавить несколько концовок
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
    public: //можно было бы добавить динамический массив, но я совсем забыл про лабу, поэтому пытаюсь быстро её дописать(todo)
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
    protected:
        string name;
        int value;
};

class action // action newaction(name,value,needstat) 
//todo добавить конструктор(done) и виртуальные функции для action и item
{          
    public:
        int getvalue();
        void chvalue(int);
        void act(); //делает дейсвтие пассивным(выносливость всё ещё тратиться)
        void pass(); //делает действие активным
        action(string iname, int ivalue, int ineedstat, int iactive): name(iname), value(ivalue), needstat(ineedstat), active(iactive)// name value needstat active
        {} 
    protected:
        string name;
        int value = 0;
        int needstat = 0;
        int active = 1; //по умолчанию действие увеличивает кол-во тиков на 1;если значение равно 0, то действие пассивное
};

class actionINT : public action
{
    public:
        actionINT(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {}
        bool donew();
};

class actionSTR : public action
{
     public:
        actionSTR(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {}
        bool donew();
};

class actionEDU : public action
{
     public:
        actionEDU(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {}
        bool donew();
};

class actionSTA : public action
{
     public: 
        actionSTA(string iname, int ivalue, int ineedstat, int iactive): action(iname,ivalue,ineedstat,iactive) //name value needstat active
        {}
        bool donew();
};

class itemINT : public item
{   
    public:
        itemINT(string iname, int ivalue):item(iname,ivalue)
        {}
        void use();
      
};

class itemSTR : public item
{
    public:
        itemSTR(string iname, int ivalue):item(iname,ivalue)
        {}
        void use();
};

class itemEDU : public item
{
    public:
            itemEDU(string iname, int ivalue):item(iname,ivalue)
            {}
            void use();
};

class itemSTA : public item
{
    public:
        itemSTA(string iname, int ivalue):item(iname,ivalue)
        {}
        void use();
};
