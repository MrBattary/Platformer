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
#include "Pillars.h"
//Контроль персонажа
#include "ControlsCHero.h"
//Карты
#include "Maps.h"
#include "MapsNPC.h"
#include "MapsNPCFunctions.h"
#include "MapsFunctions.h"
//Интерфейс
#include "ViewsAndWindow.h"
#include "ClassHeroHealthBar.h"
#include "ClassHeroStaminaBar.h"

using namespace sf;


//ТЕХH функция вывода значений из класса на экран
//Чтобы ей воспользоваться необходимо в main поставить комментарий на #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
/*void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//Вывод времени
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//Вывод скорости по Х
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//Вывод скорости по Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//Вывод кулдауна прыжка
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//Вывод кулдауна скольжения
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//Вывок времени на комбо
}*/

int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");									//Рендер окна
	//window.setFramerateLimit(60);														//Ограничение FPS
	//window.setVerticalSyncEnabled(true);												//Ограничение FPS=60
	window.setMouseCursorVisible(false);												//Скрыть курсор

	View MainView;																		//Рендер камеры вида
	View MinimapView;																	//Вид миникарты

	Hero MainHero(1100, 500, 200, 100);													//Создаем героя
	HeroHealthBar healthBar;															//Создаем бар здоровья
	HeroStaminaBar staminaBar;															//Создаем бар выносливости

	MainView.reset(FloatRect(0,0,1280,720));											                                    //Установка камеры вида на герое
    MainView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));                                                                //Настройка основной камеры и
	Minimap(MinimapView, vMaps[MainHero.Get_currentMap()][1]->Get_wM(), vMaps[MainHero.Get_currentMap()][1]->Get_hM());		//Миникарты

	Clock clock;													//Создаем переменную времени, т.е. привязка ко времени(а не загруженности/мощности процессора).	
	
	float time;
	float stime = 0;																		

    bool tact = false;
	while (window.isOpen())											//Выполняем пока окно открыто
	{
		time = clock.getElapsedTime().asMicroseconds();				//Получаем прошедшее время в микросекундах
		clock.restart();											//Перезагружаем часы
		time = time / 800;											//Скорость игры
		stime += time;												//Второй таймер
		
		//ConsoleCheck(MainHero,time, false, true,false,false,false,false);//ТЕХН, вывод значений из класса в консоль !!!КОММЕНТИРОВАТЬ,ЕСЛИ НЕ ИСПОЛЬЗУЕТСЯ, ТК ЗАМЕДЛЯЕТ ВРЕМЯ!!!

		Event event;
		while (window.pollEvent(event))																		//Событие закрытия окна
		{
			if (event.type == Event::Closed)
				window.close();
		}


		healthBar.updateBar(MainHero.Get_healthH(), MainHero.Get_healthMaxH(),10);							//ИНТЕРФЕЙС Бар здоровья
		staminaBar.updateBar(MainHero.Get_staminaH(), MainHero.Get_staminaMaxH(), 10);						//ИНТЕРФЕЙС Бар выносливости
		
		ControlsMainCharacter(MainHero,time,stime);															//Управление главным персонажем

		ViewXYfromClassHero(MainView, MainHero.Get_XHReal(), MainHero.Get_YHReal());						//Поддержание центра вида на персонаже


		NPCLogic(time, vNPC, MainHero.Get_currentMap());													//Логика NPC

		IntersectionObjectsAndNPCs(MainHero, vMaps, vNPC);													//Пересечение с объектами окружения всех объектов, NPC, итд.

        //*********************************** ОТРИСОВКА НА ГЛАВНУЮ КАМЕРУ ***********************************
        window.setView(MainView);
		DrawNPC(MainView, time, vNPC, MainHero.Get_currentMap());											//Подготовка к отрисовке NPC
		DrawEnvironment(MainView, time, vMaps, MainHero.Get_currentMap());									//Подготовка к отрисовке объектов
		MainHero.Draw(time);																				//Подготовка к отрисовке персонажа
		
		window.clear();																						//Очистка окна от предыдущего спрайта
		
		SpritesObjectsAndNPCs(window, MainHero, vMaps, vNPC);												//Отрисовка на карту

		healthBar.drawHealthBar(window);																	//ИНТЕРФЕЙС Бар здоровья
		staminaBar.drawStaminaBar(window);																	//ИНТЕРФЕЙС Бар выносливости
        //********************************** ОТРИСОВКА НА ПОБОЧНУЮ КАМЕРУ **********************************
        window.setView(MinimapView);
        SpritesObjects(window, MainHero, vMaps);												            //Отрисовка на карту
        
		window.display();																					//Отображение
	}

	//Очистка памяти из под vNPC
	for (auto i = 0; i < vNPC.size(); i++) {
		for (auto j = 0; j < vNPC[i].size(); j++) {
			delete vNPC[i][j];
		}
	}

	//Очистка памяти из под vMaps
	for (auto i = 0; i < vMaps.size(); i++) {
		for (auto j = 0; j < vMaps[i].size(); j++) {
			delete vMaps[i][j];
		}
	}

	return 0;
}



/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 756), "Using sf::View", sf::Style::Close | sf::Style::Titlebar); // Create window
    window.setFramerateLimit(60); // Set a framrate limit to reduce the CPU load
    window.setMouseCursorVisible(false); // Hide the cursor

    sf::Texture texOverlay; // Create the overlay texture and sprite
    texOverlay.loadFromFile(resourcePath() + "overlay.png");
    sf::Sprite overlay(texOverlay);
    overlay.setPosition(100.f, 100.f);

    sf::Texture texMap; // Create the world texture and sprite
    texMap.loadFromFile(resourcePath() + "world.png");
    sf::Sprite map(texMap);

    sf::Texture texLink; // Create the link texture and sprite which will be out cursor
    texLink.loadFromFile(resourcePath() + "link.png");
    sf::Sprite link(texLink);
    link.setOrigin(8.f, 8.f); // The cursors point should be in the middle

    sf::View fixed = window.getView(); // The 'fixed' view will never change

    sf::View standard = fixed; // The 'standard' view will be the one that gets always displayed

    unsigned int size = 200; // The 'minimap' view will show a smaller picture of the map
    sf::View minimap(sf::FloatRect(standard.getCenter().x, standard.getCenter().y, static_cast<float>(size), static_cast<float>(window.getSize().y * size / window.getSize().x)));
    minimap.setViewport(sf::FloatRect(1.f - static_cast<float>(minimap.getSize().x) / window.getSize().x - 0.02f, 1.f - static_cast<float>(minimap.getSize().y) / window.getSize().y - 0.02f, static_cast<float>(minimap.getSize().x) / window.getSize().x, static_cast<float>(minimap.getSize().y) / window.getSize().y));
    minimap.zoom(4.f);

    // The 'left' and the 'right' view will be used for splitscreen displays
    sf::View left(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y)));
    left.setViewport(sf::FloatRect(0.f, 0.f, 0.5, 1.f));
    sf::View right(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y)));
    right.setViewport(sf::FloatRect(0.5, 0.f, 0.5, 1.f));
    right.move(100.f, 100.f); // The 'right' view should be set a bit diffrent to notice the difference

    sf::RectangleShape miniback; // We want to draw a rectangle behind the minimap
    miniback.setPosition(minimap.getViewport().left * window.getSize().x - 5, minimap.getViewport().top * window.getSize().y - 5);
    miniback.setSize(sf::Vector2f(minimap.getViewport().width * window.getSize().x + 10, minimap.getViewport().height * window.getSize().y + 10));
    miniback.setFillColor(sf::Color(160, 8, 8));

    sf::Text position;
    position.setString("<0, 0> - <0, 0>"); // The text will contain the position of the cursor
    position.setPosition(10.f, 10.f);
    position.setColor(sf::Color::White);

    sf::Vector2i pos = sf::Mouse::getPosition(); // We will keep track of the old mouse position

    bool overlayClosed = false; // Is the overlay closed?
    bool toggleSplit = false; // Should the screen be split?
    bool moved = true; // Did the views move?
    std::stringstream ss; // Used to convert integers and floats to strings

    while (window.isOpen()) // As long as the window is open
    {
        sf::Event event; // Normal event handling

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (overlayClosed && event.type == sf::Event::MouseWheelMoved) // Zomm in or out if the mouse wheel moves
            {
                standard.zoom(1.f + event.mouseWheel.delta * 0.1f);
                left.zoom(1.f + event.mouseWheel.delta * 0.1f);
                right.zoom(1.f + event.mouseWheel.delta * 0.1f);
                moved = true;
            }
            else if (overlayClosed && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
            {
                toggleSplit = !toggleSplit; // Split or unsplit the screen only on releasing the key Q
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (overlayClosed)
            {
                if (event.key.code == sf::Keyboard::R) // Rotate counter clockwise
                {
                    standard.rotate(0.25f);
                    minimap.rotate(0.25f);
                    left.rotate(0.25f);
                    right.rotate(0.25f);
                    moved = true;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::T) // Rotate clockwise
                {
                    standard.rotate(-0.25f);
                    minimap.rotate(-0.25f);
                    left.rotate(-0.25f);
                    right.rotate(-0.25f);
                    moved = true;
                }

                else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A))
                {
                    // Move left
                    standard.move(-4.f, 0.f);
                    minimap.move(-4.f, 0.f);
                    left.move(-4.f, 0.f);
                    right.move(-4.f, 0.f);
                    moved = true;
                }
                else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D))
                {
                    // Move right
                    standard.move(4.f, 0.f);
                    minimap.move(4.f, 0.f);
                    left.move(4.f, 0.f);
                    right.move(4.f, 0.f);
                    moved = true;
                }
                else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W))
                {
                    // Move up
                    standard.move(0.f, -4.f);
                    minimap.move(0.f, -4.f);
                    left.move(0.f, -4.f);
                    right.move(0.f, -4.f);
                    moved = true;
                }
                else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S))
                {
                    // Move down
                    standard.move(0.f, 4.f);
                    minimap.move(0.f, 4.f);
                    left.move(0.f, 4.f);
                    right.move(0.f, 4.f);
                    moved = true;
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                overlayClosed = true;
        } // events

        if (moved || pos != sf::Mouse::getPosition(window)) // Views got moved or the mouse got moved
        {
            pos = sf::Mouse::getPosition(window); // Get the new position
            link.setPosition(static_cast<sf::Vector2f>(pos)); // Set Link to the new position

            // Convert the position:
            //    left: relative position on the window
            //    right: relative position to the standard view
            ss.str("");
            ss << "<" << pos.x << ", " << pos.y << ">\t<" << window.mapPixelToCoords(pos, standard).x << ", " << window.mapPixelToCoords(pos, standard).y << ">";
            position.setString(ss.str());
        }

        window.clear(); // Remove old content

        if (!toggleSplit) // Draw one map for none split screen
        {
            window.setView(standard);
            window.draw(map);
        }
        else // Draw two maps for split screen
        {
            window.setView(left);
            window.draw(map);
            window.setView(right);
            window.draw(map);
        }

        window.setView(fixed); // Draw 'GUI' elements with fixed positions
        window.draw(position);
        window.draw(miniback);

        window.setView(minimap); // Draw minimap
        window.draw(map);

        window.setView(fixed);
        if (!overlayClosed)
            window.draw(overlay);
        window.draw(link);

        window.display(); // Show everything
    }

    return 0;
}
*/