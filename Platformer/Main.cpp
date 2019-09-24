/*
Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
#include "ViewsAndWindow.h"
#include "MainFunctions.h"
#include "Maps.h"
//#include "ClassMobs.h"

using namespace sf;
/*
//ТЕХH функция вывода значений из класса на экран
//Чтобы ей воспользоваться необходимо в main снять комментарий с #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//Вывод времени
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//Вывод скорости по Х
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//Вывод скорости по Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//Вывод кулдауна прыжка
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//Вывок времени на комбо
}
*/
int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");																//Рендер окна
	window.setFramerateLimit(60);																					//Ограничение FPS

	View MainView;																									//Рендер камеры вида
	Hero MainHero("HeroSpritesBig.png", 1100, 500, 100, 74, 30, 15, 45, 59, 100);									//Создаем героя
	//МОБЫ
	Mobsv1 Mobsv1(2000, 500, 100, 74, 50, 50,50, 120, 150);// Создаем бота
	Mobsv2 Mobsv2(1866, 400, 100, 74, 50, 50, 50, 120, 150);
	//**&^&*^^&*&
	MainView.reset(FloatRect(0,0,1280,720));																		//Установка камеры вида на герое

	Clock clock;																									//Создаем переменную времени, т.е. привязка ко времени(а не загруженности/мощности процессора).	
	
	float time;

	while (window.isOpen())																							//Выполняем пока окно открыто
	{
		time = clock.getElapsedTime().asMicroseconds();																//Получаем прошедшее время в микросекундах
		clock.restart();																							//Перезагружаем часы
		time = time / 800;																							//Скорость игры
		
		//ConsoleCheck(MainHero,time,true,false,false,false,false,false);//ТЕХН, вывод значений из класса в консоль !!!КОММЕНТИРОВАТЬ,ЕСЛИ НЕ ИСПОЛЬЗУЕТСЯ, ТК ЗАМЕДЛЯЕТ ВРЕМЯ!!!

		Event event;
		while (window.pollEvent(event))																				//Событие закрытия окна
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		ControlsMainCharacter(MainHero,time);																		//Управление главным персонажем
		ViewXYfromClassHero(MainView, MainHero.Get_XH(), MainHero.Get_YH());										//Поддержание центра вида на персонаже

		SetLayers(map1, lengthMap1);																				//Распределение объектов по слоям
		IntersectionHeroWithEnvironment(MainHero, map1, lengthMap1);												//Проверка объекта MainHero на пересечение с объектами окружения
		IntersectionHeroWithEnvironmentHM(MainHero,Mobsv1,lengthMap1);
		IntersectionHeroWithEnvironmentHM(MainHero, Mobsv2, lengthMap1);
		DrawEnvironment(MainView, map1, lengthMap1);																//Подготовка к отрисовке всех объектов карты до персонажа
		MainHero.Kick();
		MainHero.Draw(time);																						//Подготовка к отрисовке персонажа
		//МОБЫ
		Mobsv1.update(time);																						// Подготовка к отрисовке БОТА
		Mobsv2.update(time);
		//&&&&&&
		window.setView(MainView);
		window.clear();																								//Очистка окна от предыдущего спрайта
		
		SpitesOfEnvironmentUncrossable(window, map1, lengthMap1);													//Отрисовка окружения (карта)
		SpitesOfEnvironmentBeforeHero(window, MainHero.Get_YHReal() + MainHero.Get_HHReal()+3, map1, lengthMap1);	//Отрисовка до персонажа
		//МОБЫ!!_!_!_!__!_!_!_!_!
		SpitesOfEnvironmentBeforeMobs(window, Mobsv1.Get_YMReal() + Mobsv1.Get_HMReal() + 3, map1, lengthMap1);
		SpitesOfEnvironmentBeforeMobs(window, Mobsv2.Get_YMReal() + Mobsv2.Get_HMReal() + 3, map1, lengthMap1);
		//&&&****&&&&&&
		window.draw(MainHero.Get_Sprite());																			//Отрисовка на экране спрайта персонажа
		window.draw(Mobsv1.Get_Sprite());
		window.draw(Mobsv2.Get_Sprite());

		SpitesOfEnvironmentAfterHero(window, MainHero.Get_YHReal() + MainHero.Get_HHReal()+3, map1, lengthMap1);	//Отрисовка после персонажа
		//МОБЫ
		SpitesOfEnvironmentAfterMobs(window, Mobsv1.Get_YMReal() + Mobsv1.Get_HMReal() + 3, map1, lengthMap1);		// Отрисовка после бота
		SpitesOfEnvironmentAfterMobs(window, Mobsv2.Get_YMReal() + Mobsv2.Get_HMReal() + 3, map1, lengthMap1);
		//&**&*^&*^&*&*^*
		window.display();																							//Отображение
	}
	return 0;
}




