#pragma once
#include <iostream>	//����
#include <vector>
#include "ClassHero.h"
#include "ClassObject.h"

using namespace std;

void ControlsMainCharacter(Hero &, float,float &);										//���������� ���������� � ����������

void DrawEnvironment(View, float, vector<vector<vector<Object>>>&, int, int);			//������������ �������� � ������������
void SetLayers(vector<vector<vector<Object>>>&, int, int);								//������� �������� �� ������������ ������� ������� ������ ����
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//������� ������������ ����������� ���������� ������� ��������