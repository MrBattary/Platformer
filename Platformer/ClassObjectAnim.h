#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"

//Класс анимированных объектов 

class AnimObject : public Object 
{
private:
	float animSpeed;					//Скорость анимации >0
	int frames;							//Кол-во кадров в анимации объекта
	int currentFrame = 0;				//Текущий кадр
	int frameShift;						//Необходимый сдвиг в файле, для анимации
	bool animated;						//Анимированный полностью, если необходимо каждый раз изменять положение в пространстве. Для оптимизации.

public:
	AnimObject(bool _animated, int _frames, int _frameShift, bool _crossable, String _filePath, float _xOnMap, float _yOnMap, float _xModel, float _yModel, float _widthModel, float _hightModel, bool mask, float _xReal, float _yReal, float _wReal, float _hReal, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch, bool _tracking, float _trackingCoef, float _animSpeed) {
		animated = _animated;
		
		frames = _frames;
		frameShift = _frameShift;
		crossable = _crossable;
		animSpeed = _animSpeed;

		filePath = _filePath;
		xR = _xOnMap;
		yR = _yOnMap;
		wM = _widthModel;
		hM = _hightModel;
		xM = _xModel;
		yM = _yModel;
		xRReal = _xOnMap + _xReal;
		yRReal = _yOnMap + _yReal;
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

		if (mask == true) imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(_xModel, _yModel, _widthModel, _hightModel));
		spriteObject.setPosition(xR, yR);															//Установка спрайта на позицию отрисовки
	}

	void Draw(View) override;												//Установка спрайта в позицию на координатной сетке для отрисовки

	float Get_currentFrame() { return currentFrame; }						//Номер кадра
	float Get_animSpeed() { return animSpeed; }								//Получение скорости анимации
	bool Get_animated() { return animated; }								//Анимирован ли полностью объект?
	int Get_frames() { return frames; }										//Возвращает количество кадров анимации
	int Get_frameShift() { return frameShift; }								//Получение сдвига в файле из которого берется картинка

	void Set_currentFrame(float value) { currentFrame = value; }			//Установка текущего кадра
};