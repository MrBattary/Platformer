//����������� ���� ������� ������ "ClassNPCFriendlyDBunny"
#include <random>
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "PhysicsEngine.h"

void NPCFriendlyBunny::Logic(float time)			//������� ������ �������
{
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