#pragma once
/*
Тут находятся объявления карт.
Одна карта - один массив.
Что дает карта:
	Объекты, и все их свойства
*/

#include "ClassObject.h"

using namespace sf;

/*
Правила написания объектов на карту:
Первой всегда идет карта/карты, затем уже все объекты
Ширина и высота физической модели не должны быть меньше 5!
Визуальная составляющая объекта не всегда может совпадать с физической

Описание каждого объекта:
1) Должен ли персонаж впринципе пересекать физическую модель этого объекта
2) Файл из которого берется текстура
3) Положение модели на карте по Х
4) Положение модели на карте по Y
5) Точка X начала текстуры в файле
6) Точка Y начала текстуры в файле
7) Ширина текстуры вырезаемой из файла
8) Высота текстуры вырезаемой из файла
9) Нужна ли маска для текстуры (сделать белый цвет прозрачным)
10) Положение физической модели в текстуре по Х
11) Положение физической модели в текстуре по Y
12) Ширина физической в текстуре модели
13) Высота физической в текстуре модели
14) true-Объект пересекается любым способом
15) true-Объект пересекается любым прыжком
16) true-Объект пересекается скольжением
17) true-Объект пересекается вприсяди
18) Сцепление внутри физической модели объекта, чтобы имело смысл стоит поставить в true 14||15||16||17||18
19) Является ли объект "следящим"?
20) Коэффициент "слежения"

Примеры можно найти в массиве;
*/
Object map1[] = {
	Object(false, "Maps/undMap3.png", -10000, -4500, 0, 0, 3250, 1000, false, 0, 0, 0, 23000, true, false, false, false, 1, true, 1.1),
	Object(false, "Maps/TestMap5.png", 0, 0, 0, 0, 4000, 2250, true, 0, 0, 4000, 2250, true, false, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1700, 330, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1750, 350, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, true, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1800, 340, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, false, true, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 890, 470, 0, 0, 0, 0, true , 0, 0, 500, 20, false, false, false,false, 1, false, 0),		//Пример невидимого объекта, у которого физическая модель больше графической(Попробуй с площадки, на которой спаунится персонаж пойти наверх.)
	Object(true, "Objects/Tree.png", 2620, 435, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3065, 559, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3149, 743, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2326, 752, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2304, 1394, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2430, 1313, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3030, 1581, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2508, 602, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 1307, 1353, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2368, 1307, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2554, 815, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 1926, 573, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/lake.png", 1508, 733, 0, 0, 196, 41, true, 0, 0, 0, 0, false, true, false, false, 1, false, 0),
	Object(true, "Objects/lake.png", 2318, 1395, 0, 0, 196, 41, true, 5, 0, 0, 0, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 917, 495, 0, 0, 0, 0, true , 0, 0, 500, 2, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 777, 698, 0, 0, 0, 0, true , 0, 0, 550, 50, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 736, 702, 0, 0, 0, 0, true , 0, 0, 100, 50, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 770, 480, 0, 0, 0, 0, true , 0, 0, 100, 100, false, false, false,false, 1, false, 0),



















};
const unsigned short int lengthMap1 = sizeof(map1) / sizeof(map1[0]);	//Функция автоматического подсчета количества элементов в массиве
