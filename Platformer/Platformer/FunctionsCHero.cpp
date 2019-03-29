﻿/*
Описание всех функций Героя.
*/


#include "ClassHero.h";
#include "OptimizedFunctionsCHero.h"

/*
Функции передвижения героя.
Получаем х и у, локально увеличиваем нужное значение по х/у,
Передаем в функцию карты и проверяем, не ушли ли мы за карту.
Если все ОК, изменяем фактическое положение и спрайт
*/

void Hero::Draw(float time)												//Физика на отрисовку персонажа, связывает анимацию и физику
{
																		/*
																		dirH: РОЗА НАПРАВЛЕНИЙ
																		7 4 8
																		 ↖↑↗
																		3←0→1
																		 ↙↓↘
																		6 2 5
																		*/
	dxH = speedHX; dyH = speedHY;										//Передаем значения ускорения
	xH += dxH * time;													//Физика
	yH += dyH * time;																		

	sprite.setPosition(xH, yH);											//Установть точку отрисовки на позиции хН,уН
}

void Hero::HeroSlideChoise(float time)									//Выбор направления скольжения
{

	switch (dirH)														//Тот самый dirН по розе направлений
	{
	case 1: HeroSlideRight(time); break;
	case 3: HeroSlideLeft(time); break;
	case 5:	HeroSlideRightDown(time); break;
	case 6: HeroSlideLeftDown(time); break;
	case 7: HeroSlideLeftUp(time); break;
	case 8: HeroSlideRightUp(time); break;
	}
}

void Hero::HeroJumpChoise(float time)									//Выбор направления прыжка
{

	switch (dirH)
	{
	case 1: HeroJumpRight(time); break;
	case 3: HeroJumpLeft(time); break;
	case 5:	HeroJumpRightDown(time); break;
	case 6: HeroJumpLeftDown(time); break;
	case 7: HeroJumpLeftUp(time); break;
	case 8: HeroJumpRightUp(time); break;
	}
}

void Hero::HeroJumpLargeChoise(float time)								//Выбор направления мощного прыжка
{

	switch (dirH)
	{
	case 1: HeroJumpLargeRight(time); break;
	case 3: HeroJumpLargeLeft(time); break;
	case 5:	HeroJumpLargeRightDown(time); break;
	case 6: HeroJumpLargeLeftDown(time); break;
	case 7: HeroJumpLargeLeftUp(time); break;
	case 8: HeroJumpLargeRightUp(time); break;
	}
}

int Hero::HeroIdleRight(float time)										//Безделие взгляд вправо
{
	dirH = 0;
	Physics(speedHX, speedHY, 0, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 0, 74, 100, 74);
	return 0;
}

int Hero::HeroIdleCrouchRight(float time)								//Безделие сидя взгляд вправо
{
	dirH = 0;
	Physics(speedHX, speedHY, 0, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 0, 148, 100, 74);
	return 0;
}

int Hero::HeroIdleLeft(float time)										//Безделие взгляд влево
{
	dirH = 0;
	Physics(speedHX, speedHY, 0, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 100, 74, -100, 74);
	return 0;
}

int Hero::HeroIdleCrouchLeft(float time)								//Безделие сидя взгляд влево
{
	dirH = 0;
	Physics(speedHX, speedHY, 0, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 4, sprite, 100, 100, 148, -100, 74);
	return 0;
}
/*
Функции движения вверх/вниз
3 булевские переменные отвечают за скорость движения
*/

int Hero::HeroMoveTop(float time, bool fast,bool slow, bool crouch)		//Бег вверх
{
	dirH = 4; 
	if (fast == true) {
		Physics(speedHX, speedHY, 0, -0.2, 1, 1, 0, 0);
	}
	else if (slow == true) {
		Physics(speedHX, speedHY, 0, -0.04, 1, 1, 0, 0);
	}
	else if (crouch == true) {
		Physics(speedHX, speedHY, 0, -0.07, 1, 1, 0, 0);
	}
	else {
		Physics(speedHX, speedHY, 0, -0.1, 1, 1, 0, 0);
	}
	CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 1110, 100, 74);
	return 0;
}

int Hero::HeroMoveDown(float time, bool fast, bool slow, bool crouch)	//Бег вниз
{
	dirH = 2;
	if (fast == true) {
		Physics(speedHX, speedHY, 0, 0.2, 1, 1, 0, 0);
	}
	else if (slow == true) {
		Physics(speedHX, speedHY, 0, 0.04, 1, 1, 0, 0);
	}
	else if (crouch == true) {
		Physics(speedHX, speedHY, 0, 0.07, 1, 1, 0, 0);
	}
	else {
		Physics(speedHX, speedHY, 0, 0.1, 1, 1, 0, 0);
	}
	CycleAnimation(currentFrame, time, 0.005, 6, sprite, 100, 0, 1184, 100, 74);
	return 0;
}


int Hero::HeroMoveRight(float time)										//Бег вправо
{
	dirH = 1;
	Physics(speedHX, speedHY, 0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	return 0;
}


int Hero::HeroMoveRightFast(float time)									//Бег вправо быстрый
{
	dirH = 1;
	Physics(speedHX, speedHY, 0.2, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlow(float time)									//Ходьба вправо
{
	dirH = 1;
	Physics(speedHX, speedHY, 0.04, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouch(float time)								//Присед вправо
{
	dirH = 1;
	Physics(speedHX, speedHY, 0.07, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}
int Hero::HeroMoveRightUp(float time)									//Бег вправо/вверх
{
	dirH = 8;
	Physics(speedHX, speedHY, 0.1, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	return 0;
}

int Hero::HeroMoveRightFastUp(float time)								//Бег вправо/вверх быстрый
{
	dirH = 8;
	Physics(speedHX, speedHY, 0.2, -0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlowUp(float time)								//Ходьба вправо/вверх
{
	dirH = 8;
	Physics(speedHX, speedHY, 0.04, -0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouchUp(float time)								//Присед вправо/вверх
{
	dirH = 8;
	Physics(speedHX, speedHY, 0.07, -0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}
int Hero::HeroMoveRightDown(float time)									//Бег вправо/вниз
{
	dirH = 5;
	Physics(speedHX, speedHY, 0.1, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 0, 100, 74);
	return 0;
}

int Hero::HeroMoveRightFastDown(float time)								//Бег вправо/вниз быстрый
{
	dirH = 5;
	Physics(speedHX, speedHY, 0.2, 0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 370, 100, 74);
	return 0;
}

int Hero::HeroMoveRightSlowDown(float time)								//Ходьба вправо/вниз
{
	dirH = 5;
	Physics(speedHX, speedHY, 0.04, 0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 0, 222, 100, 74);
	return 0;
}

int Hero::HeroMoveRightCrouchDown(float time)							//Присед вправо/вниз
{
	dirH = 5;
	Physics(speedHX, speedHY, 0.07, 0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 0, 296, 100, 74);
	return 0;
}

int Hero::HeroMoveLeft(float time)										//Бег влево
{
	dirH = 3;
	Physics(speedHX, speedHY, -0.1, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFast(float time)									//Бег влево быстрый
{
	dirH = 3;
	Physics(speedHX, speedHY, -0.2, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlow(float time)									//Ходьба влево
{	
	dirH = 3;
	Physics(speedHX, speedHY, -0.04, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouch(float time)								// Присед влево
{
	dirH = 3;
	Physics(speedHX, speedHY, -0.07, 0, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftUp(float time)									//Бег влево/вверх
{
	dirH = 7;
	Physics(speedHX, speedHY, -0.1, -0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFastUp(float time)								//Бег влево/вверх быстрый
{
	dirH = 7;
	Physics(speedHX, speedHY, -0.2, -0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlowUp(float time)								//Ходьба влево/вверх
{
	dirH = 7;
	Physics(speedHX, speedHY, -0.04, -0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouchUp(float time)								//Присед влево/вверх
{
	dirH = 7;
	Physics(speedHX, speedHY, -0.07, -0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftDown(float time)									//Бег влево/вниз
{
	dirH = 6;
	Physics(speedHX, speedHY, -0.1, 0.1, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 0, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftFastDown(float time)								//Бег влево/вниз быстрый
{
	dirH = 6;
	Physics(speedHX, speedHY, -0.2, 0.2, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 370, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftSlowDown(float time)								//Ходьба влево/вниз
{
	dirH = 6;
	Physics(speedHX, speedHY, -0.04, 0.04, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.0055, 6, sprite, 100, 100, 222, -100, 74);
	return 0;
}

int Hero::HeroMoveLeftCrouchDown(float time)							//Присед влево/вниз
{
	dirH = 6;
	Physics(speedHX, speedHY, -0.07, 0.07, 1, 1, 0, 0);
	CycleAnimation(currentFrame, time, 0.004, 6, sprite, 100, 100, 296, -100, 74);
	return 0;
}

int Hero::HeroSlideRight(float time)									//Скольжение вправо
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 1, speedHX, speedHY, sprite, 0, 100, 0.1, 0, 0.08, 1, 0.000005, 0, 0.11, 0.3, -0.3, 0.3);
	return 0;
}

int Hero::HeroSlideRightUp(float time)									//Скольжение вправо вверх
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 8, speedHX, speedHY, sprite, 0, 100, 0.1, -0.1, 0.08, 0.08, 0.000005, -0.000005, 0.11, 0.3, -0.3, -0.11);
	return 0;
}

int Hero::HeroSlideRightDown(float time)								//Скольжение вправо вниз
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 5, speedHX, speedHY, sprite, 0, 100, 0.1, 0.1, 0.08, 0.08, 0.000005, 0.000005, 0.11, 0.3, 0.11, 0.3);
	return 0;
}

int Hero::HeroSlideLeft(float time)										//Скольжение влево
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 3, speedHX, speedHY, sprite, 100, -100, -0.1, 0, 0.08, 1, -0.000005, 0,-0.3,-0.11,-0.3, 0.3);
	return 0;
}

int Hero::HeroSlideLeftUp(float time)									//Скольжение влево вверх
{
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 7, speedHX, speedHY, sprite, 100, -100, -0.1, -0.1, 0.08, 0.08, -0.000005, -0.000005,-0.3,-0.11,-0.3,-0.11);
	return 0;
}

int Hero::HeroSlideLeftDown(float time)									//Скольжение влево вниз
{	
	OnlySlideAnimation(currentUncycleFrame, time, cooldownAnimationSlide, 0.5, slideAviable, dirH, 6, speedHX, speedHY, sprite, 100, -100, -0.1, 0.1, 0.08, 0.08, -0.000005, 0.000005,-0.3,-0.11,0.11,0.3);
	return 0;
}

int Hero::HeroJumpRight(float time)										//Прыжок вправо
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 1, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.1, 0, 0.1, 1, 0.005, 0, 0.11, 0.2, -0.2, 0.2);
	return 0;
}

int Hero::HeroJumpRightUp(float time)									//Прыжок вправо вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 8, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.1, -0.1, 0.1, 0.1, 0.005, -0.005, 0.11, 0.2, -0.2, -0.11);
	return 0;
}

int Hero::HeroJumpRightDown(float time)									//Прыжок вправо вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 5, 0.007, speedHX, speedHY, sprite, 0, 518, 100, 5, 0.1, 0.1, 0.1, 0.1, 0.005, 0.005, 0.11, 0.2, 0.11, 0.2);
	return 0;
}

int Hero::HeroJumpLeft(float time)										//Прыжок влево
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 3, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.1, 0, 0.1, 1, -0.005, 0, -0.2, -0.11, -0.2, 0.2);
	return 0;
}

int Hero::HeroJumpLeftUp(float time)									//Прыжок влево вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 7, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.1, -0.1, 0.1, 0.1, -0.005, -0.005, -0.2, -0.11, -0.2, -0.11);
	return 0;
}

int Hero::HeroJumpLeftDown(float time)									//Прыжок влево вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpAviable, dirH, 6, 0.007, speedHX, speedHY, sprite, 100, 518, -100, 5, -0.1, 0.1, 0.1, 0.1, -0.005, 0.005, -0.2, -0.11, 0.11, 0.2);
	return 0;
}

int Hero::HeroJumpLargeRight(float time)								//Мощный прыжок вправо
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 1, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.17, 0, 0.1, 1, 0.00005, 0, 0, 0.3, -0.3, 0.3);
	return 0;
}

int Hero::HeroJumpLargeRightUp(float time)								//Мощный прыжок вправо вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 8, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.17, -0.17, 0.1, 0.1, 0.00005, -0.00005, 0, 0.3, -0.3, 0);
	return 0;
}

int Hero::HeroJumpLargeRightDown(float time)							//Мощный прыжок вправо вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 5, 0.01, speedHX, speedHY, sprite, 0, 444, 100, 10, 0.17, 0.17, 0.1, 0.1, 0.00005, 0.00005, 0, 0.3, 0, 0.3);
	return 0;
}

int Hero::HeroJumpLargeLeft(float time)									//Мощный прыжок влево
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 3, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.17, 0, 0.1, 1, -0.00005, 0, -0.3, 0, -0.3, 0.3);
	return 0;
}

int Hero::HeroJumpLargeLeftUp(float time)								//Мощный прыжок влево вверх
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 7, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.17, -0.17, 0.1, 0.1, -0.00005, -0.00005, -0.3, 0, -0.3, 0);
	return 0;
}

int Hero::HeroJumpLargeLeftDown(float time)								//Мощный прыжок влево вниз
{
	OnlyJumpsAnimation(currentUncycleFrame, time, cooldownAnimationJump, 0.5, jumpLargeAviable, dirH, 6, 0.01, speedHX, speedHY, sprite, 100, 444, -100, 10, -0.17, 0.17, 0.1, 0.1, -0.00005, 0.00005, -0.3, 0, 0, 0.3);
	return 0;
}

/*
Функция получения урона персонажем.
*/
void Hero::HeroGetDamage()
{
}
