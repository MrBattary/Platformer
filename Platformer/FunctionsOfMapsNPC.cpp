#include <vector>
#include "Math.h"
#include "MapsNPCFunctions.h"
using namespace std;

void DrawNPC(View view, float time, vector<vector<NPC*>>& v, int currentMap)
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		v[currentMap][i]->Draw(time);
	}
}

void NPCLogic(float time, vector<vector<NPC*>>& v, int currentMap)
{
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		v[currentMap][i]->Logic(time);
	}
}