#include "action.h"

class actionFixedStat : public action
{
    public:
        bool DoAction();
        void ChangeValue(int newValue);
        actionFixedStat(Game SomeGame, Person SomePerson, std::string newName,std::string newStat, int newValue, int newNeedStat);
        
};
