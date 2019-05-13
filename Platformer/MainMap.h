#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Map {
protected:
	float xModel;							//Положение виртуальной модели по х
	float yModel;							//Положение виртуальной модели по y
	float WidthModel;							//Высота модели
	float HightModel;							//Ширина модели

	String FilePath;						//Файл с расширением
	Image ImageMap;						//Изображение
	Texture TextureMap;					//Текстура
	Sprite SpriteMap;						//Спрайт

public:
	Map(String _filePath, float _xModel, float _yModel, float _widthModel, float _hightModel) {
		FilePath = _filePath;
		WidthModel = _widthModel;
		HightModel = _hightModel;
		xModel = _xModel;
		yModel = _yModel;

		ImageMap.loadFromFile("Sprites/" + FilePath);
		
		TextureMap.loadFromImage(ImageMap);						
		SpriteMap.setTexture(TextureMap);				
		SpriteMap.setTextureRect(IntRect(_xModel, _yModel, _widthModel, _hightModel));
		SpriteMap.setColor(sf::Color(255, 255, 255, 128));
	}

	void Draw(float);
	Sprite Get_Sprite() { return SpriteMap; }
};
