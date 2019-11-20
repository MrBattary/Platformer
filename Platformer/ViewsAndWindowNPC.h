#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassNPC.h"

using namespace std;
using namespace sf;

void SpritesOfNPCFriendly(RenderWindow& window, float time, vector<vector<NPCFriendly*>>& v, int currentMap) 
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		window.draw(v[currentMap][i]->Get_Sprite());
	}
}

//TODO: ”ƒ¿À»“‹, ¿  “ŒÀ‹ Œ –¿«¡≈–”—‹ — »Õ“≈ÀÀ≈ “”¿À‹Õ€Ã» ——€À ¿Ã» » »«¡¿¬Àﬁ—‹ Œ“ -> . ‘”Õ ÷»ŒÕ¿À œ≈–≈≈’¿À ¬ ViewsAndWindow.h