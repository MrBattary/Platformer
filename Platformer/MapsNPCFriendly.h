#pragma once

/*
��� ��������� ���������� ���� � NPCFriendly.
���� ����� - ���� ������.
*/

#include <vector>
#include "ClassNPCFriendlyTalkingWoman.h"

using namespace std;

//vector[����� ����� �� ������� ��������� ������][����� NPC]

vector < vector < NPCFriendly >> vFriendlyNPC = {
	{
		NPCFriendlyTalkingWoman(1,1400,400,100)
	}
}