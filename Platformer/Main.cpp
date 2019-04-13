/*
Platformer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
Работаем с библиотекой SFML.
Библиотеки встроенные-сверху, пользовательские файлы .h и.т.д. - снизу.
Соблюдайте "лесенку", используя как отступы TAB.
Все переменные только с маленькой буквы, все функции с большой буквы!
	Пример: xHero - переменная отвечающая за положение героя по х. MoveHero - функция отвечающая за передвижение героя.
Добавляйте как можно больше комментариев, большие пишутся по типу:
	//Комментарий описывающий КОД
	КОД
Малые:
	КОД			//Комментарий описывающий КОД

Условные обозначения:(дополняемо)
	ТЕХН-Техническая функция/библиотека, нужна для отладки и не используется в конечной программе.

	GL HF
*/
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")			//Отключение консоли

#include <conio.h>
#include <SFML/Graphics.hpp>
#include "ClassHero.h";
#include "MainFunctions.h";

using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode(1280, 720), "Test");		//Рендер окна
	window.setFramerateLimit(60);								//Ограничение FPS

	Hero MainHero("HeroSpritesBig.png", 590, 286, 100, 74, 100);//Создаем героя

	Clock clock;												//Создаем переменную времени, т.е. привязка ко времени(а не загруженности/мощности процессора).	
	
	float time;


	while (window.isOpen())										//Выполняем пока окно открыто
	{
		time = clock.getElapsedTime().asMicroseconds();			//Получаем прошедшее время в микросекундах
		clock.restart();										//Перезагружаем часы
		time = time / 800;										//Скорость игры
		
		//ConsoleCheck(MainHero,time,false,false,false,false,false,true);//ТЕХН, вывод значений из класса в консоль !!!КОММЕНТИРОВАТЬ,ЕСЛИ НЕ ИСПОЛЬЗУЕТСЯ,ЗАМЕДЛЯЕТ ВРЕМЯ!!!

		Event event;
		while (window.pollEvent(event))																		//Событие закрытия окна
		{
			if (event.type == Event::Closed)
				window.close();
		}

		ControlsMainCharacter(MainHero,time);																//Управление главным персонажем
		
		MainHero.Draw(time);																				//Отрисовка персонажа

		window.clear();																						//Очистка окна от предыдущего спрайта
		window.draw(MainHero.Get_Sprite());																	//Отрисовка на экране спрайта
		window.display();																					//Отображение
	}
	return 0;
}