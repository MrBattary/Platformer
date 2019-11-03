#pragma once

#include "ClassNPC.h"

using namespace sf;
//Класс включающий в себя дружественного NPC
//Отсутствует логика агрессии на персонажа и общения с ним
class NPCFriendly : public NPC 
{
protected:
	int currentAction = 0;				//Номер текущего действия в логике ЛОГИКА
	float currentActionTime = 0;		//Время выполнения текущего действие ЛОГИКА

	float logicReaction;				//Скорость реакции ЛОГИКА
public:
	NPCFriendly() {};
	virtual void Logic(float);													//Логика для союзного NPC
	void Set_currentAction(int value) { currentAction = value; };
};