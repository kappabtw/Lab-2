#include "item.cpp"

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