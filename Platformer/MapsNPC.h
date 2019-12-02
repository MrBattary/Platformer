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

vector < vector < NPC*>> vNPC = {
	{
		new NPCFriendlyTalkingWoman(0,1400,400,100),
		new NPCFriendlyBunny(0,1200,600,10)
	}
};