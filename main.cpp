#include "ini.cpp" //ядро
#include "1Module.cpp"
#include "2Module.cpp"
#include "test.cpp"

int main()
{
    stats();
    start();
    test();
    game.endgame(1);
}
