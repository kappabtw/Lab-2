#include <iostream>
using namespace std;

class item // item newitem(name, value)
{ 
    public:
        item(string, int);
        virtual void use();
        string getName();
        string getStat();
        int getValue();
    protected:
        string stat;
        string name;
        int value;
};