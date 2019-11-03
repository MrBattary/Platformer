#pragma once

/*
Тут находятся объявления карт с NPCFriendly.
Одна карта - один массив.
*/

#include <vector>
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "ClassNPCFriendlyDBunny.h"

using namespace std;

//vector[Номер карты на которой находится объект][Номер NPC]

vector < vector < NPCFriendly >> vFriendlyNPC = {
	{
		NPCFriendlyTalkingWoman(1,1400,400,100),
		NPCFriendlyBunny(1,1700,600,10)
	}
}