#include <vector>
#include "Math.h"
#include "MainFunctions.h"
using namespace std;

void DrawFriendlyNPC(View view, float time, vector<vector<NPCFriendly*>>& v, int currentMap)
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		//Работает некорректно!
		v[currentMap][i]->Draw(time);
	}
}

void FriendlyNPCLogic(float time, vector<vector<NPCFriendly*>>& v, int currentMap)
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		//Работает некорректно!
		v[currentMap][i]->Logic(time);
	}
}