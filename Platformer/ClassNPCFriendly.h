#pragma once

#include "ClassNPC.h"

using namespace sf;
//Класс включающий в себя дружественного NPC
//Отсутствует логика агрессии на персонажа и общения с ним
class NPCFriendly : public NPC {
private:
	int currentAction;					//Максимальное время на действие ЛОГИКА

	float currentActionTime = 0;		//Время выполнения текущего действие ЛОГИКА
public:
	NPCFriendly() {};
	virtual void Logic(float);													//Логика для союзного NPC
};