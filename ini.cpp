#include "action.cpp"
#include "event.cpp"
#include "item.cpp"
#include "actionSTAT.cpp"
#include "itemSTAT.cpp"
#include "zeroevent.cpp"
#include "location.cpp"
#include "Person.cpp"
#include "Game.cpp"
#include "GamePerson.cpp"
#include "voids.cpp"
#include <cstring>
#pragma once

//инициализация объектов используемых в игре
location kitchen{"Kitchen"};
itemSTA gre{"Grechka dada", 2};
actionSTA wakeup{"Wakeup", 0};
zeroevent *event1 = new zeroevent{"sometext 1", event1};
zeroevent *event2 = new zeroevent{"sometext 2", event2};
zeroevent *event3 = new zeroevent{"sometext 3", event3};
zeroevent *event4 = new zeroevent{"sometext 4", event4};
zeroevent *event5 = new zeroevent{"sometext 5", event5};
zeroevent *event6 = new zeroevent{"sometext 6", event6};
zeroevent *event7 = new zeroevent{"sometext 7", event7};

void settings() //настройка объектов
{
    wakeup.pass();
}