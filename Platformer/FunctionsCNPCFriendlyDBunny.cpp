//����������� ���� ������� ������ "ClassNPCFriendlyDBunny"
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "PhysicsEngine.h"
#include "OptimizedRandom.h"

void NPCFriendlyBunny::Logic(float time)			//������� ������ �������
{
	switch (currentAction)							//���������� case �� ���������� ��������
	{
	case 1:											
		if (currentActionTime > 0) {				//���� ���� ����� �� ���������� ��������
			BunnyEatDown(time);						//�������� �����������
			currentActionTime -= time;				//����� �� ��������������� �������� �����������
		}
		else										//���� ����� �����
		{
			currentActionTime = 0;					//����� �������� �������� ������������ � 0 (default)
			currentAction = 0;						//����� �� ������� �������� ������������ � 0 (default)
		}
		break;
	case 2:
		if (currentActionTime > 0) {
			BunnyEatLeft(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 3:
		if (currentActionTime > 0) {
			BunnyEatRight(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 4:
		if (currentActionTime > 0) {
			BunnyEatTop(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 5:
		if (currentActionTime > 0) {
			BunnyMoveDown(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 6:
		if (currentActionTime > 0) {
			BunnyMoveLeft(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 7:
		if (currentActionTime > 0) {
			BunnyMoveRight(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	case 8:
		if (currentActionTime > 0) {
			BunnyMoveTop(time);
			currentActionTime -= time;
		}
		else
		{
			currentActionTime = 0;
			currentAction = 0;
		}
		break;
	default:										//������, ��� 0 ��� ������ �� �������:
		currentAction = RandomBetweenInt(1, 8);		//������������, ����� �������� ����� �����������
		currentActionTime = RandomBetweenDouble(2/logicReaction, 10/logicReaction);	//������������ �����, � ������� �������� �������� ����� �����������. � ������� �� logicReaction ����������, ����� ����� �� �������� ������ ��� currentActionTime -= time*logicReaction;
		break;
	}


	//�������� ������������� currentAction, ����� ����������� ������������ ��������, ���� currentActionTime<currentAction, ����� ����� ������������� currentAction ���
	//��������, ����� �� ���������� random �� ����� ��� ����� ������� ���� optimizedrandomfunctions.h, ��� ����������� ������������ currentAction...
}

int NPCFriendlyBunny::BunnyMoveRight(float time)	//������ ��������� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 70, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveLeft(float time)		//������ ��������� �����
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 105, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveTop(float time)		//������ ��������� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 35, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveDown(float time)		//������ ��������� ����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 0, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatRight(float time)		//������ ��� ������
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 210, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatLeft(float time)		//������ ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 245, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatTop(float time)		//������ ��� �����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 180, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatDown(float time)		//������ ��� ����
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 145, 35, 35);
	return 0;
}