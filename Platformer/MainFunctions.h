#pragma once
#include <iostream>	//����
#include <vector>
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassNPCFriendly.h"
#include "ClassNPCFriendlyDBunny.h"
#include "ClassNPCFriendlyTalkingDWoman.h"

using namespace std;

void ControlsMainCharacter(Hero &, float,float &);										//���������� ���������� � ����������

void DrawEnvironment(View, float, vector<vector<vector<Object>>>&, int, int);			//������������ �������� � ������������
void DetermineLayers(vector<vector<vector<Object>>>&, int, int);						//������� �������� �� ������������ ������� ������� ������ ����
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//������� ������������ ����������� ���������� ������� �������� � ���������

void DrawFriendlyNPC(View, float, vector<vector<NPCFriendly*>>&, int);							//������������ ������������� NPC � ������������
void FriendlyNPCLogic(float, vector<vector<NPCFriendly*>>&, int);								//������ ������������� NPC