#pragma once
#include "ClassNPC.h"
class NPCEnemy :public NPC
{
public:
	bool Left = false;					//Двмижняк влеко
	bool right = true;					//Движняк вправо
	NPCEnemy() {};
};

