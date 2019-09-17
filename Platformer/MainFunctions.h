#pragma once
#include <iostream>	//ТЕХН
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassMobs.h"

void ControlsMainCharacter(Hero &, float);							//Управление персонажем с клавиатуры

void DrawEnvironment(View, Object *, const unsigned short int);						//Расположение объектов в пространстве
void SetLayers(Object *, const unsigned short int);									//Функция отвечает за присваивание каждому объекту своего слоя
void IntersectionHeroWithEnvironment(Hero &, Object *, const unsigned short int);	//Функция определяющая пересечение физических моделей объектов
void IntersectionHeroWithEnvironmentHM(Hero &, Mobs &,  const unsigned short int);	// функ пересечения Героя и Бота