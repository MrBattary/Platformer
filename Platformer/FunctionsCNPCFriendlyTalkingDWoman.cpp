//Определение всех функций класса "NPCFriendlyTalkingWoman"
#include "ClassNPCFriendlyTalkingDWoman.h"
#include "OptimizedFunctionsAnimation.h"
#include "OptimizedRandom.h"

void NPCFriendlyTalkingWoman::Logic(float time)
{
	switch (currentAction)
	{
	case 1:
		if (currentActionTime > 0) {				//Пока есть время на выполнение анимации
			WomanIdleRight(time);					//Анимация выполняется
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
			WomanIdleLeft(time);					
			currentActionTime -= time;				
		}
		else										
		{
			currentActionTime = 0;				
			currentAction = 0;						
		}
		break;
	default:
		currentAction = RandomBetweenInt(1, 2);		//Определяется, какое действие будет выполняться
		currentActionTime = RandomBetweenDouble(5 / logicReaction, 10 / logicReaction);	//Определяется время, в течении которого действие будет выполняться. А деление на logicReaction необходимо, чтобы потом не пришлось каждый раз currentActionTime -= time*logicReaction;
		break;
	}
}

void NPCFriendlyTalkingWoman::Draw(float time)							//Переопределение, т.к. не двигается и не нужно изменять местоположение итд.
{
	return;																//Затычка, чтобы ничего не происходило
}

int NPCFriendlyTalkingWoman::WomanIdleRight(float time)					//Бездействие вправо
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