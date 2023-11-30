#include <iostream>

class zeroeventVector
{
    public:
        zeroeventVector():IsDelete(false), minindex(0){};
        bool DeleteOrCheck(std::string argument);
        void push(std::string object);
        std::string getEvent(int INDEX);
        int maxIndex();
        int minIndex() const;
    private:
        bool IsDelete;
        const int minindex;

};

class BuffVector
{
    public:
        BuffVector();
        int getBuff(std::string STAT);
        void setBuff(std::string STAT, int VALUE);
};

class Stamina
{
    public:
        virtual void Change(int count);
        virtual void reboot();
        virtual int GET();
        

};

class STATS
{
    public:
        int getStat(std::string STAT);
        void plusStat(std::string STAT, int count);
        void setStat(std::string STAT, int value);
        void reboot(int INT, int STR, int EDU);
    private:
        int converteSTAT(std::string STAT);

};