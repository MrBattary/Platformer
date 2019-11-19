#include "ClassObject.h"

/*
Отрисовка для следящего объекта включает:
1)Установку точки, с которой рисовать
2)Загрузку текстуры в спрайт
3)Вырезание нужного элемента из спрайта !!!НУЖНО ПЕРЕНЕСТИ!!!
*/
void Object::Draw(View view) {	//Заглушка
	DetermineLayer();
}

//Установка объекта на слой для корректной последовательности отрисовки
void Object::DetermineLayer()
{
	if(animated==true)
	{
		layer = yRReal + hRReal;
	}
	/*if (crossable == false) {
		layer = yRReal + hRReal;
	}
	else {//Затычка для фона
		layer = yRReal + hRReal/4;
	}*/
}
