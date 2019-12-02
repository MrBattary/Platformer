#pragma once

/*
��� ��������� ���������� ���� � NPCFriendly.
���� ����� - ���� ������.
*/

#include <vector>
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "ClassNPCFriendlyDBunny.h"

using namespace std;

//vector[����� ����� �� ������� ��������� ������][����� NPC]

vector < vector < NPC*>> vNPC = {
	{
		new NPCFriendlyTalkingWoman(0,1400,400,100),
		new NPCFriendlyBunny(0,1200,600,10)
	}
};