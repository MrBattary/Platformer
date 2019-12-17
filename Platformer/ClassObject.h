#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

//Класс объектов
class Object
{
protected:
	float xR = 0.f;						//Положение модели на карте по Х
	float yR = 0.f;						//Положение модели на карте по Y
	float xM = 0.f;						//Точка X начала текстуры в файле
	float yM = 0.f;						//Точка Y начала текстуры в файле
	float wM = 0.f;						//Ширина текстуры
	float hM = 0.f;						//Высота текстуры
	float xRReal = 0.f;					//Положение физической модели на карте по Х
	float yRReal = 0.f;					//Положение физической модели на карте по Y
	float xRRealInside = 0.f;			//X реальной модели внутри виртуальной модели
	float yRRealInside = 0.f;			//Y реальной модели внутри виртуальной модели
	float wRReal = 0.f;					//Ширина физической модели
	float hRReal = 0.f;					//Высота физической модели
	float clutch = 0.f;					//Сцепление	1-нормальное <1-пониженное >1-повышенное
	float trackingCoefficient = 0.f;	//Коэффициент слежения объекта >1
	signed int layer = 0;				//Слой на котором отрисовывается объект
	signed int layerSub = 0;			//Уменьшение слоя, для больших объектов.

	bool passable = false;				//Доступен ли объект для прохождения сквозь него вообще
	bool passableJump = false;			//Доступен ли объект для прохождения сквозь него прыжком
	bool passableSlide = false;			//Доступен ли объект для прохождения сквозь него скольжением
	bool passableCrouch = false;		//Доступен ли объект для прохождения сквозь него вприсяди
	bool crossable = false;				//Должен ли герой впринципе пересекать этот объект?
	bool tracking = false;				//Следящий объект
	bool visible = false;				//Видимость объекта
	bool animated = false;				//Необходимо каждый раз изменять положение в пространстве? Для оптимизации.
	bool movableO = false;				//Способны ли другие объекты передвигать этот объект?
	//bool rendered = false;			//Отрисован ли объект?

	//String filePath;
	Image imageObject;
	Texture textureObject;
	Sprite spriteObject;

public:
	Object() {};		//Конструктор по умолчанию

	virtual void Draw(View);						//Установка спрайта в позицию на координатной сетке для отрисовки

	virtual int Animation(float) { return 0; };		//Анимация для ClassObjectAnim

	//void DetermineLayer();							//Установка слоя

	//Вспомогательные Get-Функции

	Sprite Get_Sprite() { return spriteObject; }	//Получение спрайта
	float Get_xR() { return xR; }					//Получение	модели на карте по Х
	float Get_yR() { return yR; }					//Получение	модели на карте по Y
	float Get_xM() { return xM; }					//Получение X начала текстуры
	float Get_yM() { return yM; }					//Получение Y начала текстуры
	float Get_wM() { return wM; }					//Получение ширины текстуры
	float Get_hM() { return hM; }					//Получение высоты текстуры
	float Get_xRReal() { return xRReal; }			//Получение X начала физической модели
	float Get_yRReal() { return yRReal; }			//Получение Y начала физической модели
	float Get_wRReal() { return wRReal; }			//Получение ширины физической модели
	float Get_hRReal() { return hRReal; }			//Получение высоты физической модели
	float Get_clutch() { return clutch; }			//Получение сцепления
	float Get_trackingCoefficient() { return trackingCoefficient; }			//Получение сцепления
	signed int Get_layer() { return layer; }								//Получение слоя на котором располагается объект
	bool Get_passable() { return passable; }				//Получение доступности прохождения сквозь объект
	bool Get_passableJump() { return passableJump; }		//Получение доступности прохождения сквозь объект прыжком
	bool Get_passableSlide() { return passableSlide; }		//Получение доступности прохождения сквозь объект скольжением
	bool Get_passableCrouch() { return passableCrouch; }	//Получение доступности прохождения сквозь объект присядом
	bool Get_crossable() { return crossable; }				//На одном пространстве с героем рисуется?
	//bool Get_rendered() { return rendered; }				//Отриcован уже объект?
	bool Get_tracking() { return tracking; }				//Следящий ли объект?
	bool Get_animated() { return animated; }				//Передвигается ли объект?
	bool Get_movableO() { return movableO; }				//Движим ли объект?

	//Вспомогательные Set-Функции

	void Set_layer(signed int value) { layer = value; }		//Установка слоя
	void Set_crossable(bool value) { crossable = value; }	//Установка возможности пересечения
	void Set_xRReal(float value) { xRReal = value; }		//Установить x реaльной модели
	void Set_yRReal(float value) { yRReal = value; }		//Установить y реaльной модели
	void Set_spritePosition(float x, float y) { spriteObject.setPosition(x, y); }	//Установить положение спрайта, необходимо за счет упрощения в draw
	//void Set_rendered(bool value) { rendered = value; }		//Установка рендера
};