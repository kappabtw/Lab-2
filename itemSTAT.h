#include "item.cpp"

class itemINT : public item
{   
    public:
        itemINT(Game SomeGame,Person SomePerson,std::string NewName, int newValue);
      
};

class itemSTR : public item
{
    public:
        itemSTR(Game SomeGame,Person SomePerson,std::string NewName, int newValue);
};

class itemEDU : public item
{
    public:
        itemEDU(Game SomeGame,Person SomePerson,std::string NewName, int newValue);
};

class itemSTA : public item
{
    public:
        itemSTA(Game SomeGame,Person SomePerson,std::string NewName, int newValue);
};