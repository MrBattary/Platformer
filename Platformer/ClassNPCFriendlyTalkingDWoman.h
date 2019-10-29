#pragma once

#include "ClassNPCFriendlyTalking.h"

using namespace sf;

//Класс включающий в себя дружественного квестового NPC женщину

class NPCFriendlyTalkingWoman : public NPCFriendlyTalking {
public:
	NPCFriendlyTalkingWoman(int _Map, float _X, float _Y, int _Health) {
		//Положение на карте и в пространстве
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

		//Здоровье
		healthMaxN = _Health;
		healthN = _Health;

		//Графическая часть
		File = "WomanSprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность белого
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//Вырезаем NPC
	};
	
	void Logic();											//Функция логики для женщины, определяет, какое действие будет производиться

	//AFK

	int WomanIdleRight(float time);		//Бездействие вправо
	int WomanIdleLeft(float time);		//Бездействие влево
	
	void Draw(float) override;			//Перегруженная функция связи анимации и физики
};