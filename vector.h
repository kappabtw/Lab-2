#include <iostream>

/* Люто странный класс, неизвестна причина его существования. 
 * Тем более, что называется он вектор, но данные не хранит. Твоя
 * задача, как программиста, создавать классы, которые удобно использовать
 * с уже существующей функциональностью c++, а не переписывать под себя то,
 * что и так хорошо работает. */
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

/* Семантика всего этого в коде прослеживается очень плохо, потому что плохо
 * связано с предметной областью. Почитай что-нибудь про предметно-ориентированное
 * программирование. Я вот считаю, что Buff должен быть отдельным классом, который
 * просто будет храниться в обычном векторе где-то у персонажа, который этот Buff
 * получил. */
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
/* Твоя функция reboot -- это чистой воды сеттер, что вообще-то плохо,
 * потому что нарушает инкапсуляцию. Потом в этом классе совершенно непонятно,
 * что за статы. Плохо такие вещи представлять обычным стрингом, название статов
 * должны быть enum class */
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