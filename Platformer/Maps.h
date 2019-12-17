#pragma once
/*
Тут находятся объявления карт.
Одна карта - один массив.
Что дает карта:
	Объекты, и все их свойства
*/

#include <vector>
#include "ClassObject.h"
#include "ClassObjectDBox.h"
#include "ClassObjectDTree.h"
#include "ClassObjectAnimDGrass.h"
#include "ClassObjectAnimDReed.h"
#include "ClassObjectDMapFirst.h"
#include "ClassObjectAnimDMapUndFirstTrack.h"
#include "ClassObjectDWall.h"

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
vector <vector <Object*>>  vMaps = {
	//Карта №1
	{
		new ObjectTrackMapUndFirst(),
		new ObjectMapFirst(),
		//Cтены
		new ObjectWall(850, 470, 70, 60),
		new ObjectWall(850, 520, 40, 50),
		new ObjectWall(820, 560, 55, 45),
		new ObjectWall(790, 600, 60, 50),
		new ObjectWall(760, 650, 60, 60),
		//Верхняя граница
		new ObjectWall(890, 470, 550, 20),
		new ObjectWall(1425, 430, 55, 55),
		new ObjectWall(1480, 430, 110, 25),
		new ObjectWall(1585, 390, 240, 50),
		new ObjectWall(1820, 420, 290, 45),
		new ObjectWall(2100, 400, 190, 50),
		//Нижняя граница
		new ObjectWall(790, 700, 575, 50),
		new ObjectWall(1350, 750, 60, 70),
		new ObjectWall(1400, 800, 65, 50),
		new ObjectWall(1450, 840, 70, 35),
		new ObjectWall(1520, 870, 100, 30),
		new ObjectWall(1610, 900, 230, 30),
		new ObjectWall(1840, 915, 240, 30),
		new ObjectWall(2080, 900, 230, 30),

		//Коробки
		new ObjectBox(1380, 500),
		new ObjectBox(1325, 500),
		new ObjectBox(1350, 500),
		new ObjectBox(920, 520),
		new ObjectBox(920, 540),
		new ObjectTree(1700, 330, false, true, false, false, 1),
		new ObjectTree(1750, 350, false, false, true, false, 1),
		new ObjectTree(1800, 340, false, false, false, true, 1),
		new ObjectTree(1550, 360, false, false, false, false, 1),
		new ObjectTree(1600, 620, false, false, false, false, 1),
		new ObjectTree(1690, 620, false, false, false, false, 1),
		new ObjectTree(1800, 700, false, false, false, false, 1),
		new ObjectTree(1910, 670, false, false, false, false, 1),
		new ObjectTree(2010, 400, false, false, false, false, 1),
		new ObjectTree(2150, 380, false, false, false, false, 1),
		new ObjectTree(2030, 630, false, false, false, false, 1),
		new ObjectTree(2100, 660, false, false, false, false, 1),
		
		//Трава
		new ObjectAnimGrass(2315, 740),
		new ObjectAnimGrass(2330, 755),
		new ObjectAnimGrass(2360, 770),
		new ObjectAnimGrass(2380, 785),
		new ObjectAnimGrass(2400, 800),
		new ObjectAnimGrass(2400, 815),
		new ObjectAnimGrass(2400, 830),
		new ObjectAnimGrass(2400, 845),
		new ObjectAnimGrass(2400, 860),
		new ObjectAnimGrass(2400, 875),
		new ObjectAnimGrass(2235, 455),
		new ObjectAnimGrass(2250, 470),
		new ObjectAnimGrass(2275, 485),
		new ObjectAnimGrass(2300, 500),
		new ObjectAnimGrass(2300, 515),
		new ObjectAnimGrass(2300, 530),
		new ObjectAnimGrass(2300, 545),
		new ObjectAnimGrass(2300, 560),
		new ObjectAnimGrass(2300, 575),
		new ObjectAnimGrass(2300, 590),
		new ObjectAnimGrass(2300, 605),
		new ObjectAnimGrass(2300, 620),
		new ObjectAnimGrass(2300, 635),
		new ObjectAnimGrass(2300, 650),
		new ObjectAnimGrass(2300, 665),
		new ObjectAnimGrass(2300, 680),
		new ObjectAnimGrass(2300, 695),
		new ObjectAnimGrass(2300, 710),
		new ObjectAnimGrass(2300, 725),
		new ObjectAnimGrass(2300, 740),
		new ObjectAnimGrass(2300, 755),
		new ObjectAnimGrass(2300, 770),
		new ObjectAnimGrass(2300, 785),
		new ObjectAnimGrass(2300, 800),
		new ObjectAnimGrass(2300, 815),
		new ObjectAnimGrass(2300, 830),
		new ObjectAnimGrass(2300, 845),
		new ObjectAnimGrass(2300, 860),
		new ObjectAnimGrass(2300, 875),
		new ObjectAnimGrass(2200, 455),
		new ObjectAnimGrass(2200, 470),
		new ObjectAnimGrass(2200, 485),
		new ObjectAnimGrass(2200, 500),
		new ObjectAnimGrass(2200, 515),
		new ObjectAnimGrass(2200, 530),
		new ObjectAnimGrass(2200, 545),
		new ObjectAnimGrass(2200, 560),
		new ObjectAnimGrass(2200, 575),
		new ObjectAnimGrass(2200, 590),
		new ObjectAnimGrass(2200, 605),
		new ObjectAnimGrass(2200, 620),
		new ObjectAnimGrass(2200, 635),
		new ObjectAnimGrass(2200, 650),
		new ObjectAnimGrass(2200, 665),
		new ObjectAnimGrass(2200, 680),
		new ObjectAnimGrass(2200, 695),
		new ObjectAnimGrass(2200, 710),
		new ObjectAnimGrass(2200, 725),
		new ObjectAnimGrass(2200, 740),
		new ObjectAnimGrass(2200, 755),
		new ObjectAnimGrass(2200, 770),
		new ObjectAnimGrass(2200, 785),
		new ObjectAnimGrass(2200, 800),
		new ObjectAnimGrass(2200, 815),
		new ObjectAnimGrass(2200, 830),
		new ObjectAnimGrass(2200, 845),
		new ObjectAnimGrass(2200, 860),
		new ObjectAnimGrass(2200, 875),
		new ObjectAnimGrass(2100, 455),
		new ObjectAnimGrass(2100, 470),
		new ObjectAnimGrass(2100, 485),
		new ObjectAnimGrass(2100, 500),
		new ObjectAnimGrass(2100, 515),
		new ObjectAnimGrass(2100, 530),
		new ObjectAnimGrass(2100, 545),
		new ObjectAnimGrass(2100, 560),
		new ObjectAnimGrass(2100, 575),
		new ObjectAnimGrass(2100, 590),
		new ObjectAnimGrass(2100, 605),
		new ObjectAnimGrass(2100, 620),
		new ObjectAnimGrass(2100, 635),
		new ObjectAnimGrass(2100, 650),
		new ObjectAnimGrass(2100, 665),
		new ObjectAnimGrass(2100, 680),
		new ObjectAnimGrass(2100, 695),
		new ObjectAnimGrass(2100, 710),
		new ObjectAnimGrass(2100, 725),
		new ObjectAnimGrass(2100, 740),
		new ObjectAnimGrass(2100, 755),
		new ObjectAnimGrass(2100, 770),
		new ObjectAnimGrass(2100, 785),
		new ObjectAnimGrass(2100, 800),
		new ObjectAnimGrass(2100, 815),
		new ObjectAnimGrass(2100, 830),
		new ObjectAnimGrass(2100, 845),
		new ObjectAnimGrass(2100, 860),
		new ObjectAnimGrass(2100, 875),
		new ObjectAnimGrass(2000, 455),
		new ObjectAnimGrass(2000, 470),
		new ObjectAnimGrass(2000, 485),
		new ObjectAnimGrass(2000, 500),
		new ObjectAnimGrass(2000, 515),
		new ObjectAnimGrass(2000, 530),
		new ObjectAnimGrass(2000, 545),
		new ObjectAnimGrass(2000, 560),
		new ObjectAnimGrass(2000, 575),
		new ObjectAnimGrass(2000, 590),
		new ObjectAnimGrass(2000, 605),
		new ObjectAnimGrass(2000, 620),
		new ObjectAnimGrass(2000, 635),
		new ObjectAnimGrass(2000, 650),
		new ObjectAnimGrass(2000, 665),
		new ObjectAnimGrass(2000, 680),
		new ObjectAnimGrass(2000, 695),
		new ObjectAnimGrass(2000, 710),
		new ObjectAnimGrass(2000, 725),
		new ObjectAnimGrass(2000, 740),
		new ObjectAnimGrass(2000, 755),
		new ObjectAnimGrass(2000, 770),
		new ObjectAnimGrass(2000, 785),
		new ObjectAnimGrass(2000, 800),
		new ObjectAnimGrass(2000, 815),
		new ObjectAnimGrass(2000, 830),
		new ObjectAnimGrass(2000, 845),
		new ObjectAnimGrass(2000, 860),
		new ObjectAnimGrass(2000, 875),
		new ObjectAnimGrass(1900, 470),
		new ObjectAnimGrass(1900, 485),
		new ObjectAnimGrass(1900, 500),
		new ObjectAnimGrass(1900, 515),
		new ObjectAnimGrass(1900, 530),
		new ObjectAnimGrass(1900, 545),
		new ObjectAnimGrass(1900, 560),
		new ObjectAnimGrass(1900, 575),
		new ObjectAnimGrass(1900, 590),
		new ObjectAnimGrass(1900, 605),
		new ObjectAnimGrass(1900, 620),
		new ObjectAnimGrass(1900, 635),
		new ObjectAnimGrass(1900, 650),
		new ObjectAnimGrass(1900, 665),
		new ObjectAnimGrass(1900, 680),
		new ObjectAnimGrass(1900, 695),
		new ObjectAnimGrass(1900, 710),
		new ObjectAnimGrass(1900, 725),
		new ObjectAnimGrass(1900, 740),
		new ObjectAnimGrass(1900, 755),
		new ObjectAnimGrass(1900, 770),
		new ObjectAnimGrass(1900, 785),
		new ObjectAnimGrass(1900, 800),
		new ObjectAnimGrass(1900, 815),
		new ObjectAnimGrass(1900, 830),
		new ObjectAnimGrass(1900, 845),
		new ObjectAnimGrass(1900, 860),
		new ObjectAnimGrass(1900, 875),
		new ObjectAnimGrass(1900, 885),
		new ObjectAnimGrass(1800, 470),
		new ObjectAnimGrass(1800, 480),
		new ObjectAnimGrass(1800, 500),
		new ObjectAnimGrass(1800, 515),
		new ObjectAnimGrass(1800, 530),
		new ObjectAnimGrass(1800, 545),
		new ObjectAnimGrass(1800, 560),
		new ObjectAnimGrass(1800, 575),
		new ObjectAnimGrass(1800, 590),
		new ObjectAnimGrass(1800, 605),
		new ObjectAnimGrass(1800, 620),
		new ObjectAnimGrass(1800, 635),
		new ObjectAnimGrass(1800, 650),
		new ObjectAnimGrass(1800, 665),
		new ObjectAnimGrass(1800, 680),
		new ObjectAnimGrass(1800, 695),
		new ObjectAnimGrass(1800, 710),
		new ObjectAnimGrass(1800, 725),
		new ObjectAnimGrass(1800, 740),
		new ObjectAnimGrass(1800, 755),
		new ObjectAnimGrass(1800, 770),
		new ObjectAnimGrass(1800, 785),
		new ObjectAnimGrass(1800, 800),
		new ObjectAnimGrass(1800, 815),
		new ObjectAnimGrass(1800, 830),
		new ObjectAnimGrass(1800, 845),
		new ObjectAnimGrass(1800, 860),
		new ObjectAnimGrass(1800, 875),
		new ObjectAnimGrass(1700, 425),
		new ObjectAnimGrass(1700, 440),
		new ObjectAnimGrass(1700, 455),
		new ObjectAnimGrass(1700, 470),
		new ObjectAnimGrass(1700, 490),
		new ObjectAnimGrass(1700, 500),
		new ObjectAnimGrass(1700, 515),
		new ObjectAnimGrass(1700, 530),
		new ObjectAnimGrass(1700, 545),
		new ObjectAnimGrass(1700, 560),
		new ObjectAnimGrass(1700, 575),
		new ObjectAnimGrass(1700, 590),
		new ObjectAnimGrass(1700, 605),
		new ObjectAnimGrass(1700, 620),
		new ObjectAnimGrass(1700, 635),
		new ObjectAnimGrass(1700, 650),
		new ObjectAnimGrass(1700, 665),
		new ObjectAnimGrass(1700, 680),
		new ObjectAnimGrass(1700, 695),
		new ObjectAnimGrass(1700, 710),
		new ObjectAnimGrass(1700, 725),
		new ObjectAnimGrass(1700, 740),
		new ObjectAnimGrass(1700, 755),
		new ObjectAnimGrass(1700, 770),
		new ObjectAnimGrass(1700, 785),
		new ObjectAnimGrass(1700, 800),
		new ObjectAnimGrass(1700, 815),
		new ObjectAnimGrass(1700, 830),
		new ObjectAnimGrass(1700, 845),
		new ObjectAnimGrass(1700, 860),
		new ObjectAnimGrass(1700, 870),
		new ObjectAnimGrass(1600, 455),
		new ObjectAnimGrass(1600, 470),
		new ObjectAnimGrass(1600, 485),
		new ObjectAnimGrass(1600, 500),
		new ObjectAnimGrass(1600, 515),
		new ObjectAnimGrass(1600, 530),
		new ObjectAnimGrass(1600, 545),
		new ObjectAnimGrass(1600, 560),
		new ObjectAnimGrass(1600, 575),
		new ObjectAnimGrass(1600, 590),
		new ObjectAnimGrass(1600, 605),
		new ObjectAnimGrass(1600, 620),
		new ObjectAnimGrass(1600, 635),
		new ObjectAnimGrass(1600, 650),
		new ObjectAnimGrass(1600, 665),
		new ObjectAnimGrass(1600, 680),
		new ObjectAnimGrass(1600, 695),
		new ObjectAnimGrass(1600, 710),
		new ObjectAnimGrass(1600, 725),
		new ObjectAnimGrass(1600, 740),
		new ObjectAnimGrass(1600, 755),
		new ObjectAnimGrass(1600, 770),
		new ObjectAnimGrass(1600, 785),
		new ObjectAnimGrass(1600, 800),
		new ObjectAnimGrass(1600, 815),
		new ObjectAnimGrass(1600, 830),
		new ObjectAnimGrass(1600, 845),
		new ObjectAnimGrass(1600, 860),
		new ObjectAnimGrass(1500, 440),
		new ObjectAnimGrass(1500, 455),
		new ObjectAnimGrass(1500, 470),
		new ObjectAnimGrass(1500, 485),
		new ObjectAnimGrass(1500, 500),
		new ObjectAnimGrass(1500, 515),
		new ObjectAnimGrass(1500, 530),
		new ObjectAnimGrass(1500, 545),
		new ObjectAnimGrass(1500, 560),
		new ObjectAnimGrass(1500, 575),
		new ObjectAnimGrass(1500, 590),
		new ObjectAnimGrass(1500, 605),
		new ObjectAnimGrass(1500, 620),
		new ObjectAnimGrass(1500, 635),
		new ObjectAnimGrass(1500, 650),
		new ObjectAnimGrass(1500, 665),
		new ObjectAnimGrass(1500, 680),
		new ObjectAnimGrass(1500, 695),
		new ObjectAnimGrass(1500, 710),
		new ObjectAnimGrass(1500, 725),
		new ObjectAnimGrass(1500, 740),
		new ObjectAnimGrass(1500, 755),
		new ObjectAnimGrass(1500, 770),
		new ObjectAnimGrass(1500, 785),
		new ObjectAnimGrass(1500, 800),
		new ObjectAnimGrass(1500, 815),
		new ObjectAnimGrass(1500, 830),
		new ObjectAnimGrass(1530, 845),
		new ObjectAnimGrass(1580, 860),
		new ObjectAnimGrass(1450, 455),
		new ObjectAnimGrass(1420, 470),
		new ObjectAnimGrass(1410, 485),
		new ObjectAnimGrass(1400, 500),
		new ObjectAnimGrass(1400, 515),
		new ObjectAnimGrass(1400, 530),
		new ObjectAnimGrass(1400, 545),
		new ObjectAnimGrass(1400, 560),
		new ObjectAnimGrass(1400, 575),
		new ObjectAnimGrass(1400, 590),
		new ObjectAnimGrass(1400, 605),
		new ObjectAnimGrass(1400, 620),
		new ObjectAnimGrass(1400, 635),
		new ObjectAnimGrass(1400, 650),
		new ObjectAnimGrass(1400, 665),
		new ObjectAnimGrass(1400, 680),
		new ObjectAnimGrass(1400, 695),
		new ObjectAnimGrass(1400, 710),
		new ObjectAnimGrass(1400, 725),
		new ObjectAnimGrass(1400, 740),
		new ObjectAnimGrass(1400, 755),
		new ObjectAnimGrass(1380, 547),
		new ObjectAnimGrass(1375, 563),
		new ObjectAnimGrass(1370, 575),
		new ObjectAnimGrass(1365, 592),
		new ObjectAnimGrass(1360, 602),
		new ObjectAnimGrass(1360, 617),
		new ObjectAnimGrass(1360, 633),
		new ObjectAnimGrass(1360, 651),
		new ObjectAnimGrass(1360, 662),
		new ObjectAnimGrass(1360, 681),
		new ObjectAnimGrass(1360, 694),
		new ObjectAnimGrass(1360, 710),
		new ObjectAnimGrass(1365, 725),
		new ObjectAnimGrass(1375, 740),
		new ObjectAnimGrass(1390, 755),
		new ObjectAnimGrass(1410, 770),
		new ObjectAnimGrass(1430, 785),
		new ObjectAnimGrass(1450, 800),
		new ObjectAnimGrass(1470, 815),
		new ObjectAnimGrass(1490, 830),

		//Камыш
		new ObjectAnimReed(1550, 670, true, false, false, false, 1),
		new ObjectAnimReed(1700, 490, true, false, false, false, 1),
		new ObjectAnimReed(2400, 520, true, false, false, false, 1),
		new ObjectAnimReed(2450, 540, true, false, false, false, 1),
		new ObjectAnimReed(2430, 660, true, false, false, false, 1),
		new ObjectAnimReed(2440, 620, true, false, false, false, 1),
		new ObjectAnimReed(2500, 580, true, false, false, false, 1),
		new ObjectAnimReed(2480, 620, true, false, false, false, 1),
		new ObjectAnimReed(2520, 640, true, false, false, false, 1),
		new ObjectAnimReed(2550, 650, true, false, false, false, 1),
		new ObjectAnimReed(2580, 700, true, false, false, false, 1),
		new ObjectAnimReed(2500, 790, true, false, false, false, 1),
		new ObjectAnimReed(2530, 710, true, false, false, false, 1),
		new ObjectAnimReed(2510, 730, true, false, false, false, 1),
		new ObjectAnimReed(2580, 750, true, false, false, false, 1),
		new ObjectAnimReed(2520, 770, true, false, false, false, 1),
		new ObjectAnimReed(2600, 780, true, false, false, false, 1),
		new ObjectAnimReed(2650, 810, true, false, false, false, 1),
		new ObjectAnimReed(2680, 800, true, false, false, false, 1),

	}
};