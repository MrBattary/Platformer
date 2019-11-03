#pragma once

#include "ClassNPC.h"

using namespace sf;
//����� ���������� � ���� �������������� NPC
//����������� ������ �������� �� ��������� � ������� � ���
class NPCFriendly : public NPC 
{
protected:
	int currentAction = 0;				//����� �������� �������� � ������ ������
	float currentActionTime = 0;		//����� ���������� �������� �������� ������

	float logicReaction;				//�������� ������� ������
public:
	NPCFriendly() {};
	virtual void Logic(float);													//������ ��� �������� NPC
	void Set_currentAction(int value) { currentAction = value; };
};