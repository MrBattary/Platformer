//Определение всех функций класса "ClassNPCFriendlyDBunny"
#include <random>
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "PhysicsEngine.h"

void NPCFriendlyBunny::Logic(float time)			//Функция логики кролика
{
	//Случайно выбрасывается currentAction, потом выполняется определенная анимация, пока currentActionTime<currentAction, потом снова выбрасывается currentAction итд
	//Возможно, чтобы не подключать random по много раз стоит создать файл optimizedrandomfunctions.h, где реализовать выбрасывание currentAction...
}

int NPCFriendlyBunny::BunnyMoveRight(float time)	//Кролик двигается вправо
{
	Physics(speedNX, speedNY, time, clutchObj, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 70, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveLeft(float time)		//Кролик двигается влево
{
	Physics(speedNX, speedNY, time, clutchObj, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 105, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveTop(float time)		//Кролик двигается вверх
{
	Physics(speedNX, speedNY, time, clutchObj, 0, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 35, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyMoveDown(float time)		//Кролик двигается вниз
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 0, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatRight(float time)		//Кролик ест вправо
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 210, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatLeft(float time)		//Кролик ест влево
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 245, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatTop(float time)		//Кролик ест вверх
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 180, 35, 35);
	return 0;
}

int NPCFriendlyBunny::BunnyEatDown(float time)		//Кролик ест вниз
{
	Physics(speedNX, speedNY, time, clutchObj, 0, 0, 2, 2, 0, 0);
	CycleAnimation(currentFrame, time, 0.055, 4, sprite, 35, 0, 145, 35, 35);
	return 0;
}