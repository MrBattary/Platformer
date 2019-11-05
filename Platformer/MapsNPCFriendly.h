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

vector < vector < NPCFriendly*>> vFriendlyNPC = {
	{
		new NPCFriendlyTalkingWoman(0,1400,400,100),
		new NPCFriendlyBunny(0,1700,600,10)
	}
};