#pragma once

#include "ClassNPCFriendly.h"

using namespace sf;

//����� ���������� � ���� �������������� ����������� NPC �������

class NPCFriendlyBunny : public NPCFriendly
{
public:
	NPCFriendlyBunny(int _Map, float _X, float _Y, int _Health) {
		//��������� �� ����� � � ������������
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 35;
		hN = 35;
		xNRealInside = 10;
		yNRealInside = 20;
		wNRealInside = 17;
		hNRealInside = 10;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;
		speedNX = 0;
		speedNY = 0;

		//��������
		healthMaxN = _Health;
		healthN = _Health;

		//���������� �����
		logicReaction = 0.005;

		//����������� �����
		File = "BunnySprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//������������ ������
		texture.loadFromImage(image);						//��������
		sprite.setTexture(texture);							//������
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//�������� NPC
	}

	void Logic(float) override;								//������� ������ ��� �������, ����������, ����� �������� ����� �������������

	int BunnyMoveRight(float);	//������ ��������� ������
	int BunnyMoveLeft(float);	//������ ��������� �����
	int BunnyMoveTop(float);	//������ ��������� �����
	int BunnyMoveDown(float);	//������ ��������� ����
	int BunnyEatRight(float);	//������ ��� ������
	int BunnyEatLeft(float);	//������ ��� �����
	int BunnyEatTop(float);		//������ ��� �����
	int BunnyEatDown(float);	//������ ��� ����
};

