#pragma once
#include "ClassNPCEnemyCommon.h"
class NPCEnemyCommonDLight :public NPCEnemyCommon
{

public:
	NPCEnemyCommonDLight(int _Map, float _X, float _Y, int _Health) 
	{
		currentMap = _Map;
		xN = _X;
		yN = _Y;
		wN = 150;
		hN = 200;
		xNRealInside = 0;
		yNRealInside = 0;
		wNRealInside = 150;
		hNRealInside = 200;
		xNReal = xN + xNRealInside;
		yNReal = yN + yNRealInside;
		speedNX = 0;
		speedNY = 0;
		//HP
		healthN = _Health;
		logicReaction = 0.005;
		
		if(healthN >0)
		lifeDL = true;
		//Графическая часть
		File = "LightSprite.png";
		image.loadFromFile("Sprites/" + File);
		image.createMaskFromColor(Color(255, 255, 255));	//Прозрачность белого
		texture.loadFromImage(image);						//Текстура
		sprite.setTexture(texture);							//Спрайт
		sprite.setTextureRect(IntRect(0, 0, wN, hN));		//Вырезаем NPC
	};
	void Logic(float)override;

	/*
	Функции отвечающие за связь анимации и её физической составляющей
	*/
	
	int Respawn(float);//Движение Респавн
	//AFK	
	int IdleLeft(float);//Смотрит вправо
	int IdleRight(float);//Смотрит влево
	int DieRight(float);//Умирает лицом вправо
	//AFK end
	int MoveRight(float);//Движение вправо
	int MoveLeft(float);//Движение влево	
	//void Draw(float)override;
};

