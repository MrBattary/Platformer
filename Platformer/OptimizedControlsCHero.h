#pragma once
/*
Тут находятся функции, необходимые для подключения в FunctionsControlsCHero.cpp
*/


#include "ClassHero.h";

/*
Функция, отвечающая за правильность комбо 
hitType	- Тип удара, false-легкий, true-мощный
*/

bool ComboCaller(Hero & MainHero, bool hitType)																					
{
	bool correctExecution = false;																								//Булева функция,отвечающая за проверку правильности комбо

	if (MainHero.Get_comboHitH() == 1 && hitType == false) MainHero.Set_comboH(2);												//Определение номера комбо по типу первого удара
	if (MainHero.Get_comboHitH() == 1 && hitType == true) MainHero.Set_comboH(1);									

	if (MainHero.Get_comboH() == 1)																								//1 комбо
	{
		if (MainHero.Get_comboHitH() == 1 && hitType == true) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 2 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 3 && hitType == true && MainHero.Get_comboTimer() > 0) { correctExecution = true; }

		if (correctExecution == false) { MainHero.Set_comboH(0); MainHero.Set_comboHitH(0); }
	}

	if (MainHero.Get_comboH() == 2)																								//2 комбо
	{
		if (MainHero.Get_comboHitH() == 1 && hitType == false) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 2 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 3 && hitType == false && MainHero.Get_comboTimer() > 0) { correctExecution = true; }
		if (MainHero.Get_comboHitH() == 3 && hitType == true && MainHero.Get_comboTimer() > 0) { correctExecution = true; }

		if (correctExecution == false) { MainHero.Set_comboH(0); MainHero.Set_comboHitH(0); }
	}
	if (correctExecution == true) return true;
	else return false;
}