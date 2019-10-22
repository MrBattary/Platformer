#pragma once

/*
Тут находятся объявления карт с NPCFriendly.
Одна карта - один массив.
*/

#include <vector>
#include "ClassNPCFriendlyTalkingWoman.h"

using namespace std;

//vector[Номер карты на которой находится объект][Номер NPC]

vector < vector < NPCFriendly >> vFriendlyNPC = {
	{
		NPCFriendlyTalkingWoman(1,1400,400,100)
	}
}