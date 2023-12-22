#include "item.cpp"
/* Выглядит как странный костыль или способ набрать побольше классов. Я считаю
 * класс предмета должен быть один и позволять добавлять несколько характеристик
 * а не одну. */
class itemINT : public item
{   
    public:
        itemINT(std::string NewName, int newValue);
      
};

class itemSTR : public item
{
    public:
        itemSTR(std::string NewName, int newValue);
};

class itemEDU : public item
{
    public:
        itemEDU(std::string NewName, int newValue);
};

class itemSTA : public item
{
    public:
        itemSTA(std::string NewName, int newValue);
};