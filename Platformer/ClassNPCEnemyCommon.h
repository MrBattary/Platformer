#pragma once
#include "ClassNPCEnemy.h"

//TODO: ��������� ��� �������������� � ������� ������������ �� NPCEnemy

class NPCEnemyCommon :public NPCEnemy
{
protected:
	
	int currentAction = 0;				//����� �������� �������� � ������ ������
	float currentActionTime = 0.f;		//����� ���������� �������� �������� ������

	float logicReaction = 0.f;			//�������� ������� ������
public:
	NPCEnemyCommon() {};
	bool Left = false;					//�������� �����
	bool right = true;					//������� ������
	bool lifeDL = false;
	int ch1 = 0;
	void Logic(float) override{};													//������ ���  NPC �� �����
	void Set_currentAction(int value) { currentAction = value; };
};

