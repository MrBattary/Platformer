#pragma once
#include "ClassNPCEnemy.h"
class NPCEnemyCommon :public NPC
{
protected:
	
	int currentAction = 0;				//����� �������� �������� � ������ ������
	float currentActionTime = 0;		//����� ���������� �������� �������� ������

	float logicReaction;				//�������� ������� ������
public:
	NPCEnemyCommon() {};
	bool Left = false;					//�������� �����
	bool right = true;					//������� ������
	bool lifeDL = false;
	int ch1 = 0;
	virtual void Logic(float);													//������ ���  NPC �� �����
	void Set_currentAction(int value) { currentAction = value; };
};

