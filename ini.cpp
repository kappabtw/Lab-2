#pragma once
#include "action.cpp"
#include "event.cpp"
#include "item.cpp"
#include "actionSTAT.cpp"
#include "itemSTAT.cpp"
#include "zeroevent.cpp"
#include "location.cpp"
#include "Person.cpp"
#include "Game.cpp"
#include "voids.cpp"
#include <cstring>
Person Player1;
Game game{Player1, 4};
itemSTA gre{game, Player1, "Gre", 4};
location kitchen{"Kitchen"};
actionFixedStat wakeup{game, Player1, "wakeup", "STA", 4};
zeroevent *event1 = new zeroevent{"sometext 1", event1};
zeroevent *event2 = new zeroevent{"sometext 2", event2};
zeroevent *event3 = new zeroevent{"sometext 3", event3};
zeroevent *event4 = new zeroevent{"sometext 4", event4};
zeroevent *event5 = new zeroevent{"sometext 5", event5};
zeroevent *event6 = new zeroevent{"sometext 6", event6};
zeroevent *event7 = new zeroevent{"sometext 7", event7};

void settings() //настройка объектов
{
    wakeup.MakePassive();
}