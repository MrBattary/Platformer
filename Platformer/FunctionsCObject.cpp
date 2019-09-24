#include "ClassObject.h"

/*
Отрисовка включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
3)Вырезание нужного элемента из спрайта
*/
void Object::Draw(View view, float time) {
	if (tracking == true) {
		sf::Vector2f vector=view.getCenter();																			//Если объект "следящий"
		spriteObject.setPosition(xR+ (vector.x - xR) /trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//Соответственно устанавливаем точку отрисовки основываясь на камере вида
	}
	else
	{
		spriteObject.setPosition(xR, yR);																				//Если нет, то все стандартно
	}
	spriteObject.setTexture(textureObject);
	spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
}
