#include "ClassObjectAnim.h"

/*
Отрисовка включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
*/

void AnimObject::Draw(View view)
{
	if (tracking == true) {
		sf::Vector2f vector = view.getCenter();																				//Если объект "следящий"
		spriteObject.setPosition(xR + (vector.x - xR) / trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//Соответственно устанавливаем точку отрисовки основываясь на камере вида
	}
	else
	{
		if(animated == true)																								//Если анимированный объект двигается
		spriteObject.setPosition(xR, yR);																					//Надо постоянно менять точку отрисовки
	}
}