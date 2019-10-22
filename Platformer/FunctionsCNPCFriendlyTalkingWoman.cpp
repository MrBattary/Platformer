//Определение всех функций класса "WomanTalkingFriendlyNPC"
#include "ClassNPCFriendlyTalkingWoman.h"
#include "OptimizedFunctionsAnimation.h"


void WomanTalkingFriendlyNPC::Draw(float time)							//Физика на отрисовку NPC, связывает анимацию и физику
{
	//xN = xNReal - xNRealInside;										//Положение виртуальной модели в пространстве не нужно, т.к. не двигается
	//yN = yNReal - yNRealInside;									
	//МБ функцию Draw поднять выше в иерархии?Допустим после NPC или сделать как друга. Но вообще, если объект статичен, но setPosition вообще можно прописывать в конструктор ведь ничего не поменяется.
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