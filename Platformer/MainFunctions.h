#pragma once
#include <iostream>	//ТЕХН
#include "ClassHero.h"
#include "ClassObject.h"
#include <vector>
using namespace std;

void ControlsMainCharacter(Hero &, float);												//Управление персонажем с клавиатуры

void DrawEnvironment(View, vector<vector<vector<Object>>>&, int, int);					//Расположение объектов в пространстве
void SetLayers(vector<vector<vector<Object>>>&, int, int);								//Функция отвечает за присваивание каждому объекту своего слоя
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//Функция определяющая пересечение физических моделей объектов