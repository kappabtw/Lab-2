#include "ini.cpp"
#include "stat.cpp"
#include "start.cpp"
#include "test.cpp"

int main()
{
    settings();
    stats();
    start();
    //test();
    game.endgame(1);
}
