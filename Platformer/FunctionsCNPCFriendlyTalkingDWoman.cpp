//Определение всех функций класса "NPCFriendlyTalkingWoman"
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "OptimizedFunctionsAnimation.h"


void NPCFriendlyTalkingWoman::Draw(float time)							//Переопределение, т.к. не двигается.
{
	//time = time;
	sprite.setPosition(xNReal, yNReal);									//Установть точку отрисовки на позиции хN,уN относительно физической модели
}

int NPCFriendlyTalkingWoman::WomanIdleRight(float time)				//Бездействие вправо
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.005, 16, sprite, 150, 0, 0, 150, 200);
	return 0;
}

int NPCFriendlyTalkingWoman::WomanIdleLeft(float time)					//Бездействие влево
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.005, 16, sprite, 150, 150, 0, -150, 200);
	return 0;
}