//Определение всех функций класса-родителя "NPC"

#include "ClassNPC.h"

void NPC::Draw(float time)																			//Физика на отрисовку NPC, связывает анимацию и физику
{
	dxN = speedNX; dyN = speedNY;										//Передаем значения ускорения
	xNReal += dxN * time;												//Физика
	yNReal += dyN * time;												//Положенение реальной модели в пространстве
	xN = xNReal - xNRealInside;											//Положение виртуальной модели в пространстве
	yN = yNReal - yNRealInside;
	sprite.setPosition(xNReal, yNReal);									//Установть точку отрисовки на позиции хN,уN относительно физической модели
	layerN = trunc(yNReal + hNRealInside);								//Отбросили дробную часть, если нужно округлить: layerH = round(yHReal + hHRealInside);	
}

void NPC::SetRealSizeNPC(float xRealIns, float yRealIns, float wRealIns, float hRealIns) {			//Установить новые размеры физической модели NPC
	xNRealInside = xRealIns;
	yNRealInside = yRealIns;
	wNRealInside = wRealIns;
	hNRealInside = hRealIns;
}