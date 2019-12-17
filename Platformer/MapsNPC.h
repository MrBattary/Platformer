#pragma once

/*
��� ��������� ���������� ���� � NPCFriendly.
���� ����� - ���� ������.
*/

#include <vector>
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCEnemyCommonDLight.h"

using namespace std;

//vector[����� ����� �� ������� ��������� ������][����� NPC]

vector < vector < NPC*>> vNPC = {
	{
		new NPCFriendlyTalkingWoman(0,1300,600,100),
		new NPCFriendlyBunny(0,1600,600,10),
		new NPCFriendlyBunny(0,1700,700,10),
		new NPCFriendlyBunny(0,1800,800,10),
		new NPCFriendlyBunny(0,1900,700,10),
		//new NPCEnemyCommonDLight(0,2000,500,100),
		//new NPCEnemyCommonDLight(0,1600,700,100)
	}
};