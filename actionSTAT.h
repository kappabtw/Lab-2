#include "action.h"

class actionEDU : public action
{
     public:
        actionEDU(string, int, int);
        void chvalue(int, string);
};

class actionINT : public action
{
    public:
        actionINT(string, int, int);
        void chvalue(int, string); 
};

class actionSTA : public action
{
     public: 
        actionSTA(string, int, int);
        void chvalue(int, string); 
};

class actionSTR : public action
{
     public:
        actionSTR(string, int, int);
        void chvalue(int, string); 
};