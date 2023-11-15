#include "stat.cpp"
#include "start.cpp"
#include "gametests.cpp"

int main()
{
    settings();
    stats();
    start();
    test();
    game.endgame(1);
}
