#pragma once
#include <iostream>	//����
#include "ClassHero.h"
#include "ClassObject.h"
#include "ClassMobs.h"

void ControlsMainCharacter(Hero &, float);							//���������� ���������� � ����������

void DrawEnvironment(View, Object *, const unsigned short int);						//������������ �������� � ������������
void SetLayers(Object *, const unsigned short int);									//������� �������� �� ������������ ������� ������� ������ ����
void IntersectionHeroWithEnvironment(Hero &, Object *, const unsigned short int);	//������� ������������ ����������� ���������� ������� ��������
void IntersectionHeroWithEnvironmentHM(Hero &, Mobs &,  const unsigned short int);	// ���� ����������� ����� � ����