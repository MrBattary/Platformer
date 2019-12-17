#pragma once

#include "ClassObjectAnim.h"
#include "OptimizedRandom.h"

//Анимированная трава
class ObjectAnimGrass : public ObjectAnim {
public:
	ObjectAnimGrass(float _xOnMap, float _yOnMap){
		animated = false;
		movableO = false;

		frames = 4;
		currentFrame = RandomBetweenInt(0, 3);
		crossable = false;
		animSpeed = 0.0003;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 20;
		wM = 100;
		hM = 30;
		xRRealInside = 0;
		yRRealInside = 15;
		xRReal = _xOnMap + xRRealInside;
		yRReal = _yOnMap + yRRealInside;
		wRReal = 100;
		hRReal = 15;
		clutch = 1;

		tracking = false;
		trackingCoefficient = 0;

		passable = true;
		passableJump = false;
		passableSlide = false;
		passableCrouch = false;

		imageObject.loadFromFile("Environment/Objects/Grass.png");

		imageObject.createMaskFromColor(Color(255, 255, 255));					//Прозрачность белого
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//Начальная установка спрайта на позицию отрисовки
		layerSub = 0;
		layer = yRReal + hRReal - layerSub;										//Установили слой
	}

	int Animation(float) override;
};