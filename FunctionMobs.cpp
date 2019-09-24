/*
Описание всех функций Героя.
*/


#include "ClassMobs.h"
#include "OPTFuncMobs.h"

/*
Функции передвижения героя.
Получаем х и у, локально увеличиваем нужное значение по х/у,
Передаем в функцию карты и проверяем, не ушли ли мы за карту.
Если все ОК, изменяем фактическое положение и спрайт
*/

void Mobs::DrawM(float time)												//Физика на отрисовку персонажа, связывает анимацию и физику
{
	/*
	dirH: РОЗА НАПРАВЛЕНИЙ
	7 4 8
	 ↖↑↗
	3←0→1
	 ↙↓↘
	6 2 5
	*/
	dxM = speedMX; dyM = speedMY;										//Передаем значения ускорения
	xMReal += dxM * time;												//Физика
	yMReal += dyM * time;												//Положенение реальной модели в пространстве
	xM = xMReal - xMRealInside;											//Положение виртуальной модели в пространстве
	yM = yMReal - yMRealInside;
	sprite.setPosition(xMReal, yMReal);									//Установть точку отрисовки на позиции хН,уН
}


int Mobs::MobsRespawn(float time)									//Респавн
{

	
	UncycleAnimationMob(currentUncycleFrame, time, right,  0.0004, sprite, 96, 384, 96,96, 1);
	
	return 0;
}
int Mobs::MobsDieLeft(float time)									//СМЭРТ!ЛЕВО
{

	
	UncycleAnimationMobDie(currentUncycleFrame, stop, time, 0.004, 9, sprite, 96, 100, 288, -96, 96);
	
	return 0;
}
int Mobs::MobsDieRight(float time)									//СМЭРТ!Право
{

	
	UncycleAnimationMobDie(currentUncycleFrame,stop, time,  0.004,9, sprite, 96, 0,288, 96,96);
	
	return 0;
}

int Mobs::MobsIdleRight(float time)										//Безделие взгляд вправо
{
	
	CycleAnimationMob(currentFrame, time, 0.004, 4, sprite, 96, 100, 0, -96, 96);
	return 0;
}

int Mobs::MobsKick(float time)									//Удар
{

	
	UncycleAnimationMobDie(currentUncycleFrame, onlyOneAnimation, time, 0.004, 1, sprite, 96, 0, 384, 96, 96);
	
	return 0;
}



int Mobs::MobsIdleLeft(float time)										//Безделие взгляд влево
{
	CycleAnimationMob(currentFrame, time, 0.004, 4, sprite, 96, 0, 0, 96, 96);

	return 0;
}

int Mobs::MobsMoveRight(float time)										//Бег вправо
{
	
	CycleAnimationMob(currentFrame, time, 0.005, 8, sprite, 96, 100, 96, -96, 96);
	
	return 0;
}



int Mobs::MobsMoveLeft(float time)										//Бег влево
{
	
	CycleAnimationMob(currentFrame, time, 0.005, 8, sprite, 96, 0, 96, 96, 96);
	
	return 0;
}










void Mobs::SetRealSize(float xRealIns, float yRealIns, float wReal, float hReal) {
	wMReal = wReal;
	hMReal = hReal;
}
/*
Функция получения урона Мобом.
*/
void Mobs::MobsGetDamage(float a)
{
	healthM -= a;
}