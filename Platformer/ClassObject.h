#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Object
{
protected:
	float xR;							//��������� ������ �� ����� �� �
	float yR;							//��������� ������ �� ����� �� Y
	float xM;							//����� X ������ ��������
	float yM;							//����� Y ������ ��������
	float wM;							//������ ��������
	float hM;							//������ ��������
	float xRReal;						//��������� ���������� ������ �� ����� �� �
	float yRReal;						//��������� ���������� ������ �� ����� �� Y
	float wRReal;						//������ ���������� ������
	float hRReal;						//������ ���������� ������
	float clutch;						//���������	1-���������� <1-���������� >1-����������
	float trackingCoefficient;			//����������� �������� ������� >1
	signed int layer = 0;				//���� �� ������� �������������� ������
	float animSpeed;					//�������� �������� >0
	float currentFrame = 0;				//������� ����
	//int frameShift;					//����������� ����� � �����, ��� ��������

	bool passable;						//�������� �� ������ ��� ����������� ������ ���� ������
	bool passableJump;					//�������� �� ������ ��� ����������� ������ ���� �������
	bool passableSlide;					//�������� �� ������ ��� ����������� ������ ���� �����������
	bool passableCrouch;				//�������� �� ������ ��� ����������� ������ ���� ��������
	bool crossable;						//������ �� ����� ��������� ���������� ���� ������?
	bool tracking;						//�������� ������
	bool visible;						//��������� �������
	//bool animated;					//������������� ���������, ���� ���������� ������ ��� �������� ��������� � ������������. ��� �����������.
	bool rendered = false;				//��������� �� ������?

	String filePath;
	Image imageObject;
	Texture textureObject;
	Sprite spriteObject;

public:
	Object(bool _crossable, float _animSpeed, String _filePath, float _xOnMap, float _yOnMap, float _xModel, float _yModel, float _widthModel, float _hightModel, bool mask, float _xReal, float _yReal, float _wReal, float _hReal, bool _passable, bool _passableJump, bool _passableSlide, bool _passableCrouch, float _clutch, bool _tracking, float _trackingCoef, float _startFrame) {
		animSpeed = _animSpeed;
		currentFrame = _startFrame;
		crossable = _crossable;
		//animated = _animated;

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
	}

	void Draw(View, float);							//���������

	Sprite Get_Sprite() { return spriteObject; }	//��������� �������
	float Get_xR() { return xR; }					//���������	������ �� ����� �� �
	float Get_yR() { return yR; }					//���������	������ �� ����� �� Y
	float Get_xM() { return xM; }					//��������� X ������ ��������
	float Get_yM() { return yM; }					//��������� Y ������ ��������
	float Get_wM() { return wM; }					//��������� ������ ��������
	float Get_hM() { return hM; }					//��������� ������ ��������
	float Get_xRReal() { return xRReal; }			//��������� X ������ ���������� ������
	float Get_yRReal() { return yRReal; }			//��������� Y ������ ���������� ������
	float Get_wRReal() { return wRReal; }			//��������� ������ ���������� ������
	float Get_hRReal() { return hRReal; }			//��������� ������ ���������� ������
	float Get_clutch() { return clutch; }			//��������� ���������
	float Get_trackingCoefficient() { return trackingCoefficient; }			//��������� ���������
	float Get_currentFrame() { return currentFrame; }						//����� �����
	float Get_animSpeed() { return animSpeed; }								//��������� �������� ��������
	signed int Get_layer() { return layer; }								//��������� ���� �� ������� ������������� ������
	//int Get_frameShift() { return frameShift; }			//��������� ������ � ����� �� �������� ������� ��������
	bool Get_passable() { return passable; }				//��������� ����������� ����������� ������ ������
	bool Get_passableJump() { return passableJump; }		//��������� ����������� ����������� ������ ������ �������
	bool Get_passableSlide() { return passableSlide; }		//��������� ����������� ����������� ������ ������ �����������
	bool Get_passableCrouch() { return passableCrouch; }	//��������� ����������� ����������� ������ ������ ��������
	bool Get_crossable() { return crossable; }				//�� ����� ������������ � ������ ��������?
	bool Get_rendered() { return rendered; }				//�������� ��� ������?
	bool Get_tracking() { return tracking; }				//�������� �� ������?

	void Set_layer(signed int value) { layer = value; }		//��������� ����
	void Set_crossable(bool value) { crossable = value; }	//��������� ����������� �����������
	void Set_rendered(bool value) { rendered = value; }		//��������� �������
	void Set_currentFrame(float value) { currentFrame = value; }	//��������� �������� �����
};