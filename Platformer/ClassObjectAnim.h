#pragma once

#include <SFML/Graphics.hpp>
#include "ClassObject.h"

//����� ������������� �������� 

class ObjectAnim : public Object
{
protected:
	float animSpeed;					//�������� �������� >0
	int frames;							//���-�� ������ � �������� �������
	float currentFrame = 0;				//������� ����
	bool animated;						//������������� ���������, ���� ���������� ������ ��� �������� ��������� � ������������. ��� �����������.

public:
	ObjectAnim() {};

	void Draw(View) override;												//��������� ������� � ������� �� ������������ ����� ��� ���������

	float Get_currentFrame() { return currentFrame; }						//����� �����
	float Get_animSpeed() { return animSpeed; }								//��������� �������� ��������
	bool Get_animated() { return animated; }								//���������� �� ��������� ������?
	int Get_frames() { return frames; }										//���������� ���������� ������ ��������

	void Set_currentFrame(float value) { currentFrame = value; }			//��������� �������� �����
};