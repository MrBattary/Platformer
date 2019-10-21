#pragma once

#include "PhysicsEngine.h"

/*
Функция воспроизведения анимации скольжения,сначала воспроизводится нециклическая анимация, затем циклическая, затем снова не циклическая анимация
cooldown		-куладун скольжения увеличивается на значение cooldownValue
direction		-направление скольжения
directionValue	-значение направления Смотри "розу направлений"
currentFrameUN	-текущий кадр
time			-часы
animationSpeed	-скорость анимации
frames			-количество кадров в анимации
sprite			-спрайт
y2				-положение нижней точки по Y	
x11				-нужен для отражения
aviable			-возвращает значение, выполняется ли еще эта анимация
fHX,sHX,fHY,SHY -ограничения скорости
msX,msY,clutchX,clutchY,clutchObj,addX,addY - нужны для движка физики
*/

void OnlySlideAnimation(float & currentFrameUN, float time, float& cooldown, float cooldownValue, bool & avaible, int & direction, int directionValue, float & speedHX, float & speedHY, Sprite & sprite, int x11, int x2, float msX, float msY, float clutchX, float clutchY, float clutchObj, float addX, float addY, double fHX, double sHX, double fHY, double sHY) {
	cooldown += cooldownValue*time;
	direction = directionValue;
	currentFrameUN += 0.007 * time; 
	bool minusFrames = false;
	if (currentFrameUN < 2) {
		sprite.setTextureRect(IntRect(100 * int(currentFrameUN)+ x11, 592, x2, 74));
		//if (speedHX < (sHX + addX * time)) speedHX += addX * time;
		//if (speedHY < (sHY + addY * time)) speedHY += addY * time;
		speedHX += addX * time;
		speedHY += addY * time;
	}
	else {
		Physics(speedHX, speedHY, time, clutchObj, msX, msY, clutchX, clutchY, 0, 0);
		if (currentFrameUN > 2 && currentFrameUN < 4.1 && (speedHX > fHX && speedHX< sHX && speedHY> fHY && speedHY < sHY)) {
			if (Keyboard::isKeyPressed(Keyboard::C)) {
				if (currentFrameUN > 4) { currentFrameUN = 2.0; }
				sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, 592, x2, 74));
			}
			else currentFrameUN = 4.2;
		}
		else {
			if (currentFrameUN > 4.1) {
				sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, 592, x2, 74));
			}
			if (currentFrameUN > 8)
			{
				avaible = false;
				currentFrameUN = 0;
			}
		}
	}
}

/*
Функция воспроизведения анимации прыжка, полностью не циклическая анимация
cooldown		-куладун прыжка увеличивается на значение cooldownValue
direction		-направление прыжка
directionValue	-значение направления Смотри "розу направлений"
currentFrameUN	-текущий кадр
time			-часы
animationSpeed	-скорость анимации
frames			-количество кадров в анимации
sprite			-спрайт
y1				-положение верхней точки по Y
y2				-положение нижней точки по Y
x11				-нужен для отражения
aviable			-возвращает значение, выполняется ли еще эта анимация
fHX,sHX,fHY,SHY -ограничения скорости
msX,msY,clutchX,clutchY,clutchObj,addX,addY - нужны для движка физики
*/

void OnlyJumpsAnimation(float & currentFrameUN, float time, float& cooldown, float cooldownValue, bool & avaible, int & direction, int directionValue, double animationSpeed, float & speedHX, float & speedHY, Sprite & sprite, int x11, int y1,int x2,int frames, float msX, float msY, float clutchX, float clutchY, float clutchObj, float addX, float addY,double fHX, double sHX, double fHY, double sHY) {
	cooldown += cooldownValue*time;
	direction = directionValue;
	currentFrameUN += animationSpeed * time;
	if (speedHX > fHX && speedHX< sHX && speedHY> fHY && speedHY < sHY) {
		Physics(speedHX, speedHY, time, /*clutchObj*/ 1, msX, msY, clutchX, clutchY, addX, addY);
	}
	sprite.setTextureRect(IntRect(100 * int(currentFrameUN)+x11, y1, x2, 74));
	if (currentFrameUN > frames)
	{
		avaible = false;
		currentFrameUN = 0;
	}
}