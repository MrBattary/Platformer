#pragma once
#include <iostream>	//����
#include "ClassHero.h"
#include "ClassObject.h"
#include <vector>
using namespace std;

void ControlsMainCharacter(Hero &, float);												//���������� ���������� � ����������

void DrawEnvironment(View, vector<vector<vector<Object>>>&, int, int);					//������������ �������� � ������������
void SetLayers(vector<vector<vector<Object>>>&, int, int);								//������� �������� �� ������������ ������� ������� ������ ����
void IntersectionHeroWithEnvironment(Hero &, vector<vector<vector<Object>>>&, int, int);//������� ������������ ����������� ���������� ������� ��������