#pragma once

#include "ClassNPCFriendly.h"

using namespace sf;

//Класс включающий в себя дружественного движущегося NPC кролика

class NPCFriendlyBunny : public NPCFriendly
{
public:
	NPCFriendlyBunny(int _Map, float _X, float _Y, int _Health) {
		//Положение на карте и в пространстве
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

		//Здоровье
		healthMaxN = _Health;
		healthN = _Health;

		//Логическая часть
		logicReaction = 0.005;

		//Графическая часть
		File = "BunnySprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность белого
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//Вырезаем NPC
	}

	void Logic(float) override;								//Функция логики для кролика, определяет, какое действие будет производиться

	int BunnyMoveRight(float);	//Кролик двигается вправо
	int BunnyMoveLeft(float);	//Кролик двигается влево
	int BunnyMoveTop(float);	//Кролик двигается вверх
	int BunnyMoveDown(float);	//Кролик двигается вниз
	int BunnyEatRight(float);	//Кролик ест вправо
	int BunnyEatLeft(float);	//Кролик ест влево
	int BunnyEatTop(float);		//Кролик ест вверх
	int BunnyEatDown(float);	//Кролик ест вниз
};

