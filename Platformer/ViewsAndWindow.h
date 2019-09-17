#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"

using namespace sf;

void SpitesOfEnvironmentUncrossable(RenderWindow & window, Object * arrObj, const int length_arrObj)					//Отрисовка объектов на пространство того, с чем герой не может взаимодействовать впринципе
{					
	for (unsigned short int j = 10000; j > 0; j--) {																	//Важный момент: отрисовка тут идет снизу вверх!
		for (int i = 0; i < length_arrObj; i++) {
			if (arrObj[i].Get_layer() == j && arrObj[i].Get_crossable() == false)
			{
				window.draw(arrObj[i].Get_Sprite());
			}
		}
	}
}

void SpitesOfEnvironmentBeforeHero(RenderWindow & window, float Yhero, Object * arrObj, const int length_arrObj)		//Отрисовка объектов на пространство до героя
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = 0; j < heroY; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			if (arrObj[i].Get_layer() == j && arrObj[i].Get_crossable() == true) 
			{ 
				window.draw(arrObj[i].Get_Sprite()); 
			}
		}
	}
}
void SpitesOfEnvironmentBeforeMobs(RenderWindow & window, float YMobs, Object * arrObj, const int length_arrObj)		//Отрисовка объектов на пространство до бота
{
	int MobsY = roundf(YMobs);
	for (unsigned short int j = 0; j < MobsY; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			if (arrObj[i].Get_layer() == j && arrObj[i].Get_crossable() == true)
			{
				window.draw(arrObj[i].Get_Sprite());
			}
		}
	}
}

void SpitesOfEnvironmentAfterHero(RenderWindow & window, float Yhero, Object * arrObj, const int length_arrObj)			//Отрисовка объектов на пространство после героя
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = heroY; j < 5000; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			
			if (arrObj[i].Get_layer() == j && arrObj[i].Get_crossable() == true) 
			{ 
				window.draw(arrObj[i].Get_Sprite()); 
			}
		}
	}
}
void SpitesOfEnvironmentAfterMobs(RenderWindow & window, float YMobs, Object * arrObj, const int length_arrObj)			//Отрисовка объектов на пространство после бота
{
	int MobsY = roundf(YMobs);
	for (unsigned short int j = MobsY; j < 5000; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {

			if (arrObj[i].Get_layer() == j && arrObj[i].Get_crossable() == true)
			{
				window.draw(arrObj[i].Get_Sprite());
			}
		}
	}
}

void ViewXYfromClassHero(View & MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }						//Удержание центра камеры на герое

//Еще миникарту сюда надо будет написать