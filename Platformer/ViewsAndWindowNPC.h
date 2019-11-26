#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassNPC.h"
//#include "ClassNPCFriendly.h"

using namespace std;
using namespace sf;

void SpritesOfNPCFriendly(RenderWindow& window, float time, vector<vector<NPCFriendly*>>& v, int currentMap) 
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		window.draw(v[currentMap][i]->Get_Sprite());
	}
}

//TODO: Исключить этот файл как только разберусь с интеллектуальными ссылками и избавлюсь от -> . функционал переехал в ViewsAndWindow.h