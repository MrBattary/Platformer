//Определение всех функций класса "WomanTalkingFriendlyNPC"
#include "ClassNPCFriendlyTalkingWoman.h"
#include "OptimizedFunctionsAnimation.h"


void WomanTalkingFriendlyNPC::WomanDraw(float time)						//Физика на отрисовку NPC, связывает анимацию и физику
{
	//xN = xNReal - xNRealInside;										//Положение виртуальной модели в пространстве не нужно, т.к. не двигается
	//yN = yNReal - yNRealInside;										МБ ДАЖЕ ФУНКЦИЮ DRAW ПОДНЯТЬ ВЫШЕ В ИЕРАРХИИ?ДОПУСТИМ ПОСЛЕ NPC ИЛИ СДЕЛАТЬ ДРУГА
	sprite.setPosition(xNReal, yNReal);									//Установть точку отрисовки на позиции хN,уN относительно физической модели
}

void WomanTalkingFriendlyNPC::WomanIdleRight(float time)				//Бездействие вправо
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.005, 16, sprite, 150, 0, 0, 150, 200);
}

void WomanTalkingFriendlyNPC::WomanIdleLeft(float time)					//Бездействие влево
{
	dirN = 0;
	CycleAnimation(currentFrame, time, 0.005, 16, sprite, 150, 150, 0, -150, 200);
}