#pragma once

#include "ClassNPCFriendlyTalking.h"

using namespace sf;

//����� ���������� � ���� �������������� NPC ��������� �������

class NPCFriendlyTalkingWoman : public NPCFriendlyTalking {
public:
	NPCFriendlyTalkingWoman(int _Map, float _X, float _Y, int _Health) {
		//��������� �� ����� � � ������������
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 150;
		hN = 200;
		xNRealInside = 38;
		yNRealInside = 180;
		wNRealInside = 58;
		hNRealInside = 10;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;

		//��������
		healthMaxN = _Health;
		healthN = _Health;

		//����������� �����
		File = "WomanSprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//������������ ������
		texture.loadFromImage(image);						//��������
		sprite.setTexture(texture);							//������
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//�������� NPC
	};
	
	//AFK

	void WomanIdleRight(float time);
	void WomanIdleLeft(float time);
	
	void Draw(float);
};