#include "event.h"

class zeroevent: public event //событие без изменений stat
{
    public:
        zeroevent(std::string ename, auto* ptr);
};