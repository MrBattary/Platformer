#pragma once

#include "ClassObject.h"

//Класс коробки
class ObjectTree : public Object {
public:
	ObjectTree(float _xOnMap, float _yOnMap, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch) {
		crossable = true;
		movableO = true;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 0;
		wM = 23;
		hM = 31;
		xRReal = _xOnMap;
		yRReal = _yOnMap + 8;
		wRReal = 23;
		hRReal = 23;
		clutch = _clutch;

		tracking = false;
		trackingCoefficient = 0;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/Objects/box.png");
		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//Установка спрайта на позицию отрисовки
		layer = yRReal + hRReal;												//Установили слой первоначально
	}
};