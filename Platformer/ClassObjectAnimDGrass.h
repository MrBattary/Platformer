#pragma once

#include "ClassObjectAnim.h"

//Класс определяющий класс-траву
class ObjectAnimGrass : public ObjectAnim {
public:
	ObjectAnimGrass(float _xOnMap, float _yOnMap, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch){
		animated = true;

		frames = 4;
		crossable = false;
		animSpeed = 0.0003;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 20;
		wM = 100;
		hM = 30;
		xRReal = _xOnMap + 0;
		yRReal = _yOnMap + 17;
		wRReal = 100;
		hRReal = 17;
		clutch = _clutch;

		tracking = false;
		trackingCoefficient = 0;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/Objects/Grass.png");

		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);															//Установка спрайта на позицию отрисовки
	}

	int Animation(float) override;
};