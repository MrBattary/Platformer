#pragma once
//Вспомогательные функции для функций персонажа
/*
Функция Physics: физика, отвечает за правильную физику в игре
speedX					-ускорение по оси Х
speedY					-ускорение по оси Y
clutchObj				-показатель сцепления с объектом, чем он меньше, тем сильнее "заносит" персонажа, больше- обратная ситуация
msX(movementspeedX=ms)	-значение по Х, к которому стремится speedX
msY						-значение по Y, к которому стремится speedY
clutchX/clutchY			-показатель сцепления анимации
addX/addY				-доп ускорение (для прыжков,рывков, итд), если не нужно:ставим 0.
*/

void Physics(float &speedX, float &speedY, float time, float clutchObj, float msX, float msY, float clutchX, float clutchY, float addX, float addY) {
	speedX += addX * time;
	speedY += addY * time;
	
	if (speedX < (msX + 0.001 * time * clutchX * clutchObj) && speedX >(msX - 0.001 * time * clutchX * clutchObj)) speedX = msX;
	else {
		if (speedX > msX)speedX -= 0.001 * clutchX * clutchObj * time;
		if (speedX < msX)speedX += 0.001 * clutchX * clutchObj * time;
	}
	if (speedY < (msY + 0.001 * time * clutchY * clutchObj) && speedY >(msY - 0.001 * time * clutchY * clutchObj)) speedY = msY;
	else {
		if (speedY > msY)speedY -= 0.001 * clutchY * clutchObj * time;
		if (speedY < msY)speedY += 0.001 * clutchY * clutchObj * time;
	}
}

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
void CycleAnimation(float & currentFrame, float time, double animationSpeed, int frames,Sprite & sprite, int x1,int x11, int y1, int x2, int y2) {
	currentFrame += animationSpeed * time;
	if (currentFrame > frames) currentFrame -= frames;
	sprite.setTextureRect(IntRect(x1 * int(currentFrame)+x11, y1, x2, y2));
}

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
void UncycleAnimation(float & currentFrameUN, float time, bool & avaible, int & direction, int directionValue, double animationSpeed, Sprite & sprite, int x11, int y1, int x2, int frames) {
	direction = directionValue;
	currentFrameUN += animationSpeed * time;
	sprite.setTextureRect(IntRect(100 * int(currentFrameUN) + x11, y1, x2, 74));
	if (currentFrameUN > frames)
	{
		avaible = false;
		currentFrameUN = 0;
	}
}