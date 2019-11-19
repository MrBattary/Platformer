#pragma once
#include "ClassNPCFriendly.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCFriendlyTalkingDWoman.h"

using namespace std;

void DrawFriendlyNPC(View, float, vector<vector<NPCFriendly*>>&, int);							//Расположение дружественных NPC в пространстве
void FriendlyNPCLogic(float, vector<vector<NPCFriendly*>>&, int);								//Логика дружественных NPC