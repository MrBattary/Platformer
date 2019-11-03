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

vector < vector < NPCFriendly >> vFriendlyNPC = {
	{
		NPCFriendlyTalkingWoman(1,1400,400,100),
		NPCFriendlyBunny(1,1700,600,10)
	}
}