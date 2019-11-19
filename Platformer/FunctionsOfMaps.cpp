#include <vector>
#include "Math.h"
#include "MapsFunctions.h"

using namespace std;

void DrawEnvironment(View view, float time, vector<vector<Object>>& v, int currentMap) {
	for (int i = 0; i < v[currentMap].size(); i++)
	{
		v[currentMap][i].Animation(time);												//Вырезание нужных кадров для анимации
		v[currentMap][i].Draw(view);													//Подготовка к отрисовке
	}
}


//!!!АДАПТИРУЕТСЯ ВЫРЕЗАТЬ И УБРАТЬ!!!
/*
Функция взаимодействия персонажа с окружением
		2
	 •――――――•
	1|      |3
	 •――――――•
		4
*/
void IntersectionHeroWithEnvironment(Hero & Hero, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)	//Функция определяющая пересечение физических моделей объектов
{
	//+2 тут могут быть нужны, чтобы не было наслоения персонажа в момент упора в физическую модель другого объекта
	//const char Ex = 2;
	float xHero = Hero.Get_XHReal()/* + Ex*/;
	float yHero = Hero.Get_YHReal()/* + Ex*/;
	float wHero = Hero.Get_WHRealInside()/* + Ex*/;
	float hHero = Hero.Get_HHRealInside()/* + Ex*/;


	for (unsigned short int i=0; i < length_arrObj; i++)
	{
		for (int j = 0; j < v[currentMap][i].size(); j++)
		{
			float xObj = v[currentMap][i][j].Get_xRReal();
			float yObj = v[currentMap][i][j].Get_yRReal();
			float wObj = v[currentMap][i][j].Get_wRReal();
			float hObj = v[currentMap][i][j].Get_hRReal();

			bool checkAviable = true;
			if (v[currentMap][i][j].Get_passable() == true) checkAviable = false;												//Проходим ли объект
			if (Hero.Get_jumpAviable() == true && v[currentMap][i][j].Get_passableJump() == true) checkAviable = false;			//Проходим ли объект прыжком
			if (Hero.Get_jumpLargeAviable() == true && v[currentMap][i][j].Get_passableJump() == true) checkAviable = false;	//Проходим ли объект мощным прыжком
			if (Hero.Get_slideAviable() == true && v[currentMap][i][j].Get_passableSlide() == true) checkAviable = false;		//Проходим ли объект скольжением
			if (Hero.Get_crouchAviable() == true && v[currentMap][i][j].Get_passableCrouch() == true) checkAviable = false;		//Проходим ли объект вприсяди

			if ((xHero + wHero > xObj) && (xHero < xObj + wObj) && (yHero + hHero > yObj) && (yHero + hHero < yObj + hObj))		//Если попали в объект
			{
				Hero.Set_clutchObj(v[currentMap][i][j].Get_clutch());															//Сцепление с объектом
				if (checkAviable == true)
				{
					float dir1 = xHero + wHero - xObj;
					float dir2 = yHero + hHero - yObj;
					float dir3 = xObj + wObj - xHero;
					float dir4 = yObj + hObj - yHero - hHero;
					dir2 = abs(dir2);
					dir4 = abs(dir4);
					if (dir1 < dir2 && dir1 < dir3 && dir1 < dir4) { Hero.Set_XHReal(xHero - (xHero + wHero - xObj)); }			//Выталкивание влево
					if (dir2 < dir1 && dir2 < dir3 && dir2 < dir4) { Hero.Set_YHReal(yHero - (yHero + hHero - yObj)); }			//Выталкивание вверх
					if (dir3 < dir1 && dir3 < dir2 && dir3 < dir4) { Hero.Set_XHReal(xHero + (xObj + wObj - xHero)); }			//Выталкивание вправо
					if (dir4 < dir1 && dir4 < dir2 && dir4 < dir3) { Hero.Set_YHReal(yHero + (yObj + hObj - yHero - hHero)); }	//Выталкивание вниз
				}
			}
		}
	}
}
