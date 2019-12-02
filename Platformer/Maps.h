#pragma once
/*
Тут находятся объявления карт.
Одна карта - один массив.
Что дает карта:
	Объекты, и все их свойства
*/

#include <vector>
#include "ClassObject.h"
#include "ClassObjectDTree.h"
#include "ClassObjectAnimDGrass.h"
#include "ClassObjectAnimDReed.h"
#include "ClassObjectDMapFirst.h"

using namespace std;
using namespace sf;

/*
Правила написания объектов на карту:
Первой всегда идет карта/карты, затем уже все объекты
Ширина и высота физической модели не должны быть меньше 5!
Визуальная составляющая объекта не всегда может совпадать с физической

vector[Номер карты на которой находится объект][Номер объекта][Количество кадров объекта]

Описание каждого объекта:
1) Должен ли персонаж впринципе пересекать физическую модель этого объекта
2) Скорость анимации
3) Файл из которого берется текстура
4) Положение модели на карте по Х
5) Положение модели на карте по Y
6) Точка X начала текстуры в файле
7) Точка Y начала текстуры в файле
8) Ширина текстуры вырезаемой из файла
9) Высота текстуры вырезаемой из файла
10) Нужна ли маска для текстуры (сделать белый цвет прозрачным)
11) Положение физической модели в текстуре по Х
12) Положение физической модели в текстуре по Y
13) Ширина физической в текстуре модели
14) Высота физической в текстуре модели
15) true-Объект пересекается любым способом
16) true-Объект пересекается любым прыжком
17) true-Объект пересекается скольжением
18) true-Объект пересекается вприсяди
19) Сцепление внутри физической модели объекта, чтобы имело смысл стоит поставить в true 14||15||16||17||18
20) Является ли объект "следящим"?
21) Коэффициент "слежения"

Примеры можно найти в массиве;
*/
/*
vector <vector <vector <Object> > > v = {
	//Карта № 1
	{
		{Object(false, false, 0,"Maps/undMap3.png", -10000, -5000, 0, 0, 3250, 1000, false, 0, 0, 0, 10000, true, false, false, false, 1, true, 1.1, 0)},		//0.0.0
		{Object(false, false, 0, "Maps/TestMap5.png", 0, 0, 0, 0, 4000, 2250, true, 0, 0, 4000, 2250, true, false, false, false, 1, false, 0, 0)},				//0.1.0
		{Object(true, false, 0, "Objects/Tree.png", 1700, 330, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0, 0)},				//0.2.0
		{Object(true, false, 0, "Objects/Tree.png", 1750, 350, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, true, false, 1, false, 0, 0)},				//0.3.0
		{Object(true, false, 0, "Objects/Tree.png", 1800, 340, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, false, true, 1, false, 0, 0)},				//0.4.0
		{Object(true, false, 0, "Objects/Obstacles.png", 890, 470, 0, 0, 0, 0, true , 0, 0, 500, 20, false, false, false,false, 1, false, 0, 0)},				//0.5.0	//Пример невидимого объекта, у которого физическая модель больше графической(Попробуй с площадки, на которой спаунится персонаж пойти наверх.)
		{Object(true, false, 0.0003, "Objects/Grass.png", 1800, 800, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.6.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 800, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),			//0.6.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 800, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),			//0.6.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 800, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},			//0.6.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1800, 815, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 2),				//0.7.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 815, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.7.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 815, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.7.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 815, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.7.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1800, 830, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 1),				//0.8.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 830, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.8.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 830, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.8.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1800, 830, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.8.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1900, 800, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 2),				//0.9.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 800, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.9.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 800, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.9.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 800, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.9.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1900, 815, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 3),				//0.10.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 815, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.10.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 815, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.10.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 815, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.10.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1900, 830, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 1),				//0.11.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 830, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.11.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 830, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.11.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1900, 830, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.11.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 2000, 800, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.12.0
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 800, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.12.1
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 800, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.12.2
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 800, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.12.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 2000, 815, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 1),				//0.13.0
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 815, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.13.1
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 815, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.13.2
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 815, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.13.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 2000, 830, 0, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 2),				//0.14.0
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 830, 100, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.14.1
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 830, 200, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0),				//0.14.2
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 830, 300, 20, 100, 30, true , 0, 17, 100, 1, true, false, false,false, 1, false, 0, 0)},				//0.14.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 0, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.0
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 20, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.1
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 40, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.15.2
			Object(true, false, 0.0003, "Objects/Grass.png", 1850, 770, 60, 50, 20, 50, true , 5, 45, 100, 5, true, false, false,false, 1, false, 0, 0)},				//0.15.3
		{Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 0, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.0
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 20, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.1
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 40, 50, 20, 50, true , 5, 45, 10, 5, true, false, false,false, 1, false, 0, 0),					//0.16.2
			Object(true, false, 0.0003, "Objects/Grass.png", 2000, 790, 60, 50, 20, 50, true , 5, 45, 100, 5, true, false, false,false, 1, false, 0, 0)},				//0.16.3
	}
	//Карта № 2
};*/


/*
Правила написания объектов на карту:
Первой всегда идет карта/карты, затем уже все объекты
Ширина и высота физической модели не должны быть меньше 5!
Визуальная составляющая объекта не всегда может совпадать с физической

vector[Номер карты на которой находится объект][Номер объекта]

Описание каждого объекта:
1) Положение модели на карте по Х
2) Положение модели на карте по Y
3) true-Объект пересекается любым способом
4) true-Объект пересекается любым прыжком
5) true-Объект пересекается скольжением
6) true-Объект пересекается вприсяди
7) Сцепление внутри физической модели объекта, чтобы имело смысл стоит поставить в true 14||15||16||17||18

Примеры можно найти в массиве;
*/
vector <vector <Object> >  v = {
	//Карта №1
	{
		ObjectMapFirst(),
		ObjectTree(1700, 330, false, true, false, false, 1),
		ObjectTree(1750, 350, false, false, true, false, 1),
		ObjectTree(1800, 340, false, false, false, true, 1),
		ObjectAnimGrass(1800, 800, true, false, false,false, 1),
		ObjectAnimGrass(1900, 815, true, false, false,false, 1),
		ObjectAnimGrass(1900, 830, true, false, false,false, 1),
		ObjectAnimGrass(2000, 800, true, false, false,false, 1),
		ObjectAnimGrass(2000, 815, true, false, false,false, 1),
		ObjectAnimGrass(2000, 830, true, false, false,false, 1),
		ObjectAnimGrass(1850, 770, true, false, false,false, 1),
		ObjectAnimGrass(2000, 790, true, false, false,false, 1),
		//Камыш
		ObjectAnimReed(1500,800,true,false,false,false,1)

	}
};