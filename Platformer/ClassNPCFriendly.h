#pragma once

#include "ClassNPC.h"

using namespace sf;
//����� ���������� � ���� �������������� NPC
//����������� ������ �������� �� ��������� � ������� � ���
class NPCFriendly : public NPC {
private:
	int currentAction;					//������������ ����� �� �������� ������

	float currentActionTime = 0;		//����� ���������� �������� �������� ������
public:
	NPCFriendly() {};
	virtual void Logic(float);													//������ ��� �������� NPC
};