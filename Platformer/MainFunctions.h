#pragma once
#include <iostream>	//ТЕХН
#include <vector>
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassNPCFriendly.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCFriendlyTalkingDWoman.h"

using namespace std;

void ControlsMainCharacter(Hero &, float,float &);										//Управление персонажем с клавиатуры

void DrawEnvironment(View, float, vector<vector<vector<Object>>>&, int, int);			//Расположение объектов в пространстве
void DetermineLayers(vector<vector<vector<Object>>>&, int, int);						//Функция отвечает за присваивание каждому объекту своего слоя
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//Функция определяющая пересечение физических моделей объектов и персонажа

void DrawFriendlyNPC(View, float, vector<vector<NPCFriendly*>>&, int);							//Расположение дружественных NPC в пространстве
void FriendlyNPCLogic(float, vector<vector<NPCFriendly*>>&, int);								//Логика дружественных NPC