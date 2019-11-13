#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//Класс от которого наследуются все другие NPC
class NPC {
protected:
	float xN;							//Положение виртуальной модели по х
	float yN;							//Положение виртуальной модели по y
	float wN;							//Ширина модели	для конструктора
	float hN;							//Высота модели для конструктора
	float xNReal;						//Х реальной модели внутри виртуальной модели относительной всей оси
	float yNReal;						//Y реальной модели внутри виртуальной модели относительной всей оси
	float xNRealInside;					//Х реальной модели внутри виртуальной модели
	float yNRealInside;					//Y реальной модели внутри виртуальной модели
	float wNRealInside;					//Ширина реальной модели внутри виртуальной модели
	float hNRealInside;					//Высота реальной модели внутри виртуальной модели

	float dxN;							//Ускорение по х
	float dyN;							//Ускорение по y
	float speedNX = 0;					//Скорость NPC по x
	float speedNY = 0;					//Скорость NPC по y

	float clutchObj = 1;				//Сцепление NPC с поверхностью на которой он стоит
	int dirN;							//Направление движения/взгляда
	int currentMap = 0;					//Текущая карта

	int healthN;						//Здоровье NPC
	int healthMaxN;

	String File;						//Файл с расширением
	Image image;						//Изображение
	Texture texture;					//Текстура
	Sprite sprite;						//Спрайт
	signed int layerN;					//Слой отрисовки

	float currentFrame = 0;				//Номер текущего кадра циклической анимации
	float currentUncycleFrame = 0;		//Номер текущего кадра не циклической анимации
public:
	NPC() {}

	//Get-функции

	Sprite Get_Sprite() { return sprite; }										//Получить Спрайт
	int Get_currentMap() { return currentMap; }									//Узнать на какой карте сейчас находимся
	int Get_healthN() { return healthN; }										//Узнать значение здоровья NPC
	int Get_healthMaxN() { return healthMaxN; }									//Узнать максимальное здоровье NPC
	signed int Get_layerN() { return layerN; }									//Получение слоя на котором располагается NPC
	float Get_XN() { return xN; }												//Получить положение виртуальной модели по х
	float Get_YN() { return yN; }												//Получить положение виртуальной модели по у
	float Get_WN() { return wN; }												//Получить ширину модели
	float Get_HN() { return hN; }												//Получить высоту модели
	float Get_XNReal() { return xNReal; }										//Получить положение реальной модели по оси х
	float Get_YNReal() { return yNReal; }										//Получить положение реальной модели по оси у
	float Get_XNRealInside() { return xNRealInside; }							//Получить х реальной модели
	float Get_YNRealInside() { return yNRealInside; }							//Получить y реальной модели
	float Get_WNRealInside() { return wNRealInside; }							//Получить ширину реальной модели
	float Get_HNRealInside() { return hNRealInside; }							//Получить высоту реальной модели
	float Get_clutchObj() { return clutchObj; }									//Получить величину сцепления NPC с поверхностью на которой он стоит

	//Set-функции

	void Set_currentMap(int value) { currentMap = value; }						//Установить номер текущей карты
	void Set_healthN(int value) { healthN = value; }							//Установить текущее здоровье героя
	void Set_healthMaxN(int value) { healthMaxN = value; }						//Установить максимальное здоровье героя
	void Set_XN(float value) { xN = value; }									//Установить положение виртуальной модели по х
	void Set_YN(float value) { yN = value; }									//Установить положение виртуальной модели по у
	void Set_XNReal(float value) { xNReal = value; }							//Установить положение реальной модели по х
	void Set_YNReal(float value) { yNReal = value; }							//Установить положение реальной модели по у
	void Set_XNRealInside(float value) { xNRealInside = value; }				//Установить x реaльной модели
	void Set_YNRealInside(float value) { yNRealInside = value; }				//Установить y реaльной модели
	void Set_WNRealInside(float value) { wNRealInside = value; }				//Установить ширину реaльной модели
	void Set_HNRealInside(float value) { hNRealInside = value; }				//Установить высоту реaльной модели
	void Set_clutchObj(float value) { clutchObj = value; }						//Установить величину сцепления персонажа с поверхностью на которой он стоит
	void Set_layerN(signed int value) { layerN = value; }						//Установка слоя

	virtual void Draw(float);													//Связь физики и анимации
	void SetRealSizeNPC(float, float, float, float);							//Изменение размеров внутренней модели
};