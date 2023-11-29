#include "ini.cpp"

void test()
{
    std::cout<<"\n\nTesting...\n\nObject \"gre\"...";
    std::cout<<"\n\nName: "<<gre.getName();
    std::cout<<"\n\nStat: "<<gre.getStat();
    std::cout<<"\n\nUsing object \"gre\"...";
    gre.useItem();
    game.newtick();
}