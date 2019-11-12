#include "ClassObject.h"

/*
Отрисовка для следящего объекта включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
3)Вырезание нужного элемента из спрайта !!!НУЖНО ПЕРЕНЕСТИ!!!
*/
void Object::Draw(View view) {
	if (tracking == true) {
		sf::Vector2f vector=view.getCenter();																			//Если объект "следящий"
		spriteObject.setPosition(xR+ (vector.x - xR) /trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//Соответственно устанавливаем точку отрисовки основываясь на камере вида
	}

	/*spriteObject.setTexture(textureObject);
	spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));*/
}

//Установка объекта на слой для корректной последовательности отрисовки
void Object::SetLayer()
{
	if (crossable == false) {
		layer = yRReal + hRReal;
	}
	else {
		layer = yRReal /*+ hRReal/4*/;
	}
}
