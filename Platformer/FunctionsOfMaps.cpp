#include "Math.h"
#include "MainFunctions.h"

void DrawEnvironment(View view, Object * arrObj, const unsigned short int length_arrObj) {								//Расположение объектов в пространстве
		for (unsigned short int i = 0; i < length_arrObj; i++) {
			arrObj[i].Draw(view);
		}
}

void SetLayers(Object * arrObj, const unsigned short int length_arrObj)													//Функция отвечает за присваивание каждому объекту своего слоя
{																														//на основе которых проводится порядок отрисовки
	for (unsigned short int i = 0; i < length_arrObj; i++) {
		arrObj[i].Set_layer(arrObj[i].Get_yRReal()+arrObj[i].Get_hRReal()/4);
	}
}

/*
Функция взаимодействия персонажа с окружением
		2
	 •――――――•
	1|      |3
	 •――――――•
		4
*/
void IntersectionHeroWithEnvironment(Hero & Hero, Object * arrObj, const unsigned short int length_arrObj)				//Функция определяющая пересечение физических моделей объектов
{
	float xHero = Hero.Get_XHReal();
	float yHero = Hero.Get_YHReal();
	float wHero = Hero.Get_WHReal();
	float hHero = Hero.Get_HHReal();


	for (unsigned short int i=0; i < length_arrObj; i++)
	{
		float xObj = arrObj[i].Get_xRReal();
		float yObj = arrObj[i].Get_yRReal();
		float wObj = arrObj[i].Get_wRReal();
		float hObj = arrObj[i].Get_hRReal();

		bool checkAviable = true;
		if (arrObj[i].Get_passable() == true) checkAviable = false;												//Проходим ли объект
		if (Hero.Get_jumpAviable() == true && arrObj[i].Get_passableJump() == true) checkAviable = false;		//Проходим ли объект прыжком
		if (Hero.Get_jumpLargeAviable() == true && arrObj[i].Get_passableJump() == true) checkAviable = false;	//Проходим ли объект мощным прыжком
		if (Hero.Get_slideAviable() == true && arrObj[i].Get_passableSlide() == true) checkAviable = false;		//Проходим ли объект скольжением
		if (Hero.Get_crouchAviable() == true && arrObj[i].Get_passableCrouch() == true) checkAviable = false;	//Проходим ли объект вприсяди

		if ((xHero + wHero > xObj) && (xHero < xObj + wObj) && (yHero + hHero > yObj) && (yHero + hHero < yObj + hObj))	//Если попали в объект
		{
			Hero.Set_clutchObj(arrObj[i].Get_clutch());															//Сцепление с объектом
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