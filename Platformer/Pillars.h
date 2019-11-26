#pragma once
//������ ���� ������������ ��� ���������� �������, ������� ��������� ��� ������� � ����

#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassNPCFriendly.h"

using namespace std;
using namespace sf;

void SpritesObjectsAndNPCs(RenderWindow&, Hero, vector<vector<Object>>, vector<vector<NPCFriendly>>);	//��� ������� �������� �������� �� ���� ����

void IntersectionObjectsAndNPCs(Hero&, vector<vector<Object>>&, vector<vector<NPCFriendly>>&);			//��� ������� ����������� �� ������������.