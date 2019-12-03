#pragma once

#include "ClassObject.h"

//����� �������
class ObjectBox : public Object {
public:
	ObjectBox(float _xOnMap, float _yOnMap, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch) {
		crossable = true;
		movableO = true;

		xR = _xOnMap;
		yR = _yOnMap;
		xM = 0;
		yM = 0;
		wM = 23;
		hM = 31;
		xRRealInside = 0;
		yRRealInside = 6;
		xRReal = xR + xRRealInside;
		yRReal = yR + yRRealInside;
		wRReal = 23;
		hRReal = 25;
		clutch = _clutch;

		tracking = false;
		trackingCoefficient = 0;

		passable = _passable;
		passableJump = _passableJump;
		passableSlide = _passableSlide;
		passableCrouch = _passableCrouch;

		imageObject.loadFromFile("Environment/Objects/box.png");
		imageObject.createMaskFromColor(Color(255, 255, 255));					//������������ ������
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
		spriteObject.setPosition(xR, yR);										//��������� ������� �� ������� ���������
		layer = yRReal + hRReal;												//���������� ���� �������������
	}
};