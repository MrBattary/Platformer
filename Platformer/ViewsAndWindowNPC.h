#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassNPCFriendly.h"

using namespace std;
using namespace sf;

void SpritesOfNPCFriendly(RenderWindow& window, float time, vector<vector<NPCFriendly*>>& v, int currentMap) 
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		window.draw(v[currentMap][i]->Get_Sprite());
	}
}