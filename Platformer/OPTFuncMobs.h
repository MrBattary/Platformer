#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
Функция CycleAnimation: воспроизведение ЦИКЛИЧЕСКОЙ анимации, именно она отвечает за двигающуюся картинку.
currentFrame	-текущий кадр
time			-часы
animationSpeed	-скорость анимации
frames			-количество кадров в анимации
sprite			-спрайт
setTextureRect	-вырезает квадратик 1 кадра из всего спрайта по координатам
x1				-положение верхней точки по Х							х1
y1				-положение верхней точки по Y						 у1 •――――――•
x2				-положение нижней точки по Х							|      |
y2				-положение нижней точки по Y							•――――――• y2
x11				-нужен для отражения										   x2
*/
void CycleAnimationMob(float & currentFrame, float time, double animationSpeed, int frames, Sprite & sprite, int x1, int x11, int y1, int x2, int y2) {
	currentFrame += animationSpeed * time;
	if (currentFrame > frames) currentFrame -= frames;
	sprite.setTextureRect(IntRect(x1 * int(currentFrame) + x11, y1, x2, y2));
}
/*
Функция UncycleAnimation : воспроизведение НЕЦИКЛИЧЕСКОЙ анимации.
currentFrame	- текущий кадр
time			- часы
animationSpeed	- скорость анимации
frames			- количество кадров в анимации
sprite			- спрайт
setTextureRect	- вырезает квадратик 1 кадра из всего спрайта по координатам
x1				- положение верхней точки по Х							х1
y1				- положение верхней точки по Y						 у1 •――――――•
x2				- положение нижней точки по Х							|      |
y2				- положение нижней точки по Y							•――――――• y2
x11				- нужен для отражения										   x2
avaible			- возвращает значение, выполняется ли еще эта анимация
*/
void UncycleAnimationMob(float & currentFrameUN, float time, bool & avaible,   double animationSpeed, Sprite & sprite, int x11, int y1, int x2,int x1, int frames) {
	
	currentFrameUN += animationSpeed * time;
	sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, y1, x2, x1));
	if (currentFrameUN > frames)
	{
		avaible = false;
		currentFrameUN = 0;
	}
}
void UncycleAnimationMobDie(float & currentFrameUN, bool & avaible, float time, double animationSpeed,  int frames, Sprite & sprite, int x1, int x11, int y1, int x2, int y2 ) {

	currentFrameUN += animationSpeed * time;
	sprite.setTextureRect(IntRect(x1 * int(currentFrameUN) + x11, y1, x2, y2));
	if (currentFrameUN > frames)
	{
		avaible = true;
		currentFrameUN = 0;
	}
}