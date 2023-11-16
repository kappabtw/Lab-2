#include "Game.h"
#include "Person.h"
#include <iostream>
using namespace std;
#pragma once

Person Player; //Player - объект, за которого играют
Game game{4}; //game - сама игра, где каждые 4 тика восстанавливается стамина