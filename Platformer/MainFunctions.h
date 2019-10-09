#pragma once
#include <iostream>	//ТЕХН
#include <vector>
#include "ClassHero.h"
#include "ClassObject.h"

using namespace std;

void ControlsMainCharacter(Hero &, float,float &);										//Управление персонажем с клавиатуры

void DrawEnvironment(View, float, vector<vector<vector<Object>>>&, int, int);			//Расположение объектов в пространстве
void SetLayers(vector<vector<vector<Object>>>&, int, int);								//Функция отвечает за присваивание каждому объекту своего слоя
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//Функция определяющая пересечение физических моделей объектов