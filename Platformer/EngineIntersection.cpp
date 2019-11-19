#include "Math.h"
#include <tuple>
/*
Функция взаимодействия одного объекта (F) с другим (S)
Расчеты выталкивания производятся для объекта (F)
		2
	 •――――――•
	1|      |3
	 •――――――•
		4
*/
//Функция определяющая сторону пересечения физических моделей двух объектов и насколько нужно сместить первый объект, второй недвижим
std::tuple<int,float> Intersection(float xF, float yF, float wF, float hF, float xS, float yS, float wS, float hS)
{
	if ((xF + wF > xS) && (xF < xS + wS) && (yF + hF > yS) && (yF + hF < yS + hS))		//Если попали в объект
	{
		float dir1 = xF + wF - xS;
		float dir2 = yF + hF - yS;
		float dir3 = xS + wS - xF;
		float dir4 = yS + hS - yF - hF;
		dir2 = abs(dir2);
		dir4 = abs(dir4);
		if (dir1 < dir2 && dir1 < dir3 && dir1 < dir4) return {1, xF - (xF + wF - xS)};			//Обозначили что пересекли слева и вычислили выталкивание
		if (dir2 < dir1 && dir2 < dir3 && dir2 < dir4) return {2, yF - (yF + hF - yS)};			//Обозначили что пересекли вверху и вычислили выталкивание
		if (dir3 < dir1 && dir3 < dir2 && dir3 < dir4) return {3, xF + (xS + wS - xF)};			//Обозначили что пересекли справа и вычислили выталкивание
		if (dir4 < dir1 && dir4 < dir2 && dir4 < dir3) return {4, yF + (yS + hS - yF - hF)};	//Обозначили что пересекли внизу и вычислили выталкивание
	}
	else {																		//Если не попали в объект
		return { 0 , 0 };														//Обозначили что не пересекли и не вытолкнулись
	}
}