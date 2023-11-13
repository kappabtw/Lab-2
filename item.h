#include <iostream>
using namespace std;

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