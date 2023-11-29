#include <iostream>

class location
{
    public:
        location(std::string);
        std::string Name();
        std::string GetCurrentLocation();
        void SetCurrentLocation();
        bool IsCurrentLocation();
    private:
        std::string locationname;
};