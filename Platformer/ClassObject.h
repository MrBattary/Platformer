#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Object
{
private:
	float xR;							//Положение модели на карте по Х
	float yR;							//Положение модели на карте по Y
	float xM;							//Точка X начала текстуры
	float yM;							//Точка Y начала текстуры
	float wM;							//Ширина текстуры
	float hM;							//Высота текстуры
	float xRReal;						//Положение физической модели на карте по Х
	float yRReal;						//Положение физической модели на карте по Y
	float wRReal;						//Ширина физической модели
	float hRReal;						//Высота физической модели
	float clutch;						//Сцепление	1-нормальное <1-пониженное >1-повышенное
	float trackingCoefficient;			//Коэффициент слежения объекта >1
	signed int layer=0;					//Слой на котором отрисовывается объект

	bool passable;						//Доступен ли объект для прохождения сквозь него вообще
	bool passableJump;					//Доступен ли объект для прохождения сквозь него прыжком
	bool passableSlide;					//Доступен ли объект для прохождения сквозь него скольжением
	bool passableCrouch;				//Доступен ли объект для прохождения сквозь него вприсяди
	bool crossable;						//Должен ли герой впринципе пересекать этот объект?
	bool tracking;						//Следящий объект

	String filePath;						
	Image imageObject;						
	Texture textureObject;					
	Sprite spriteObject;						

public:
	Object(bool _crossable ,String _filePath, float _xOnMap, float _yOnMap, float _xModel, float _yModel, float _widthModel, float _hightModel, bool mask, float _xReal, float _yReal, float _wReal, float _hReal, bool _passable, bool _passableJump, bool _passableSlide,bool _passableCrouch, float _clutch, bool _tracking, float _trackingCoef) {
		crossable = _crossable;

		filePath = _filePath;
		xR = _xOnMap;
		yR = _yOnMap;
		wM = _widthModel;
		hM = _hightModel;
		xM = _xModel;
		yM = _yModel;
		xRReal = _xOnMap+_xReal;
		yRReal = _yOnMap+_yReal;
		wRReal = _wReal;
		hRReal = _hReal;
		clutch = _clutch;

		tracking = _tracking;
		trackingCoefficient = _trackingCoef;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/" + filePath);

		if(mask==true) imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(_xModel, _yModel, _widthModel, _hightModel));
	}

	void Draw(View);								//Отрисовка

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
	signed int Get_layer() { return layer;	}								//Получение слоя на котором располагается объект
	bool Get_passable() { return passable; }		//Получение доступности прохождения сквозь объект
	bool Get_passableJump() { return passableJump; }		//Получение доступности прохождения сквозь объект прыжком
	bool Get_passableSlide() { return passableSlide; }		//Получение доступности прохождения сквозь объект скольжением
	bool Get_passableCrouch() { return passableCrouch; }	//Получение доступности прохождения сквозь объект присядом
	bool Get_crossable() { return crossable; }				//На одном пространстве с героем рисуется?

	void Set_layer(signed int value) { layer = value; }		//Установка слоя
	void Set_crossable(bool value) { crossable = value; }	//Установка возможности пересечения

};