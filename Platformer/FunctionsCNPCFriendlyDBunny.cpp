//Определение всех функций класса "ClassNPCFriendlyDBunny"
#include "ClassNPCFriendlyDBunny.h"
#include "OptimizedFunctionsAnimation.h"
#include "PhysicsEngine.h"
#include "OptimizedRandom.h"

void NPCFriendlyBunny::Logic(float time)			//Функция логики кролика
{
	switch (currentAction)							//Количество case по количеству анимаций
	{
	case 1:											
		if (currentActionTime > 0) {				//Пока есть время на выполнение анимации
			BunnyEatDown(time);						//Анимация выполняется
			currentActionTime -= time;				//Время на поспроизведение анимации уменьшается
		}
		else										//Если время вышло
		{
			currentActionTime = 0;					//Номер текущего действия сбрасывается в 0 (default)
			currentAction = 0;						//Время на текущее действие сбрасывается в 0 (default)
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
	default:										//Дефолт, при 0 или выходе за пределы:
		currentAction = RandomBetweenInt(1, 8);		//Определяется, какое действие будет выполняться
		currentActionTime = RandomBetweenDouble(2/logicReaction, 10/logicReaction);	//Определяется время, в течении которого действие будет выполняться. А деление на logicReaction необходимо, чтобы потом не пришлось каждый раз currentActionTime -= time*logicReaction;
		break;
	}


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