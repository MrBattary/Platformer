#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"
#include <vector>
using namespace std;
using namespace sf;

void SpitesOfEnvironmentUncrossable(RenderWindow & window, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)//Отрисовка объектов на пространство того, с чем герой не может взаимодействовать впринципе
{					
	for (unsigned short int j = 10000; j > 0; j--) {																			//Важный момент: отрисовка тут идет снизу вверх!
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i][0].Get_frames(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == false)
				{
					window.draw(v[currentMap][i][l].Get_Sprite());
				}
			}
		}
	}
}

void SpitesOfEnvironmentBeforeHero(RenderWindow & window, float Yhero, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)		//Отрисовка объектов на пространство до героя
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = 0; j < heroY; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i][0].Get_frames(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == true)
				{
					window.draw(v[currentMap][i][l].Get_Sprite());
				}
			}
		}
	}
}

void SpitesOfEnvironmentAfterHero(RenderWindow & window, float Yhero, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)			//Отрисовка объектов на пространство после героя
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = heroY; j < 5000; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i][0].Get_frames(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == true)
				{
					window.draw(v[currentMap][i][l].Get_Sprite());
				}
			}
		}
	}
}

void ViewXYfromClassHero(View & MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }						//Удержание центра камеры на герое

//Еще миникарту сюда надо будет написать