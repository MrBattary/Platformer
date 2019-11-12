#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"

//����� ������������� �������� 

class AnimObject : public Object 
{
private:
	float animSpeed;					//�������� �������� >0
	int frames;							//���-�� ������ � �������� �������
	int currentFrame = 0;				//������� ����
	int frameShift;						//����������� ����� � �����, ��� ��������
	bool animated;						//������������� ���������, ���� ���������� ������ ��� �������� ��������� � ������������. ��� �����������.

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

		if (mask == true) imageObject.createMaskFromColor(Color(255, 255, 255));					//������������ ������
		textureObject.loadFromImage(imageObject);
		spriteObject.setTexture(textureObject);
		spriteObject.setTextureRect(IntRect(_xModel, _yModel, _widthModel, _hightModel));
		spriteObject.setPosition(xR, yR);															//��������� ������� �� ������� ���������
	}

	void Draw(View) override;												//��������� ������� � ������� �� ������������ ����� ��� ���������

	float Get_currentFrame() { return currentFrame; }						//����� �����
	float Get_animSpeed() { return animSpeed; }								//��������� �������� ��������
	bool Get_animated() { return animated; }								//���������� �� ��������� ������?
	int Get_frames() { return frames; }										//���������� ���������� ������ ��������
	int Get_frameShift() { return frameShift; }								//��������� ������ � ����� �� �������� ������� ��������

	void Set_currentFrame(float value) { currentFrame = value; }			//��������� �������� �����
};