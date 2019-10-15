/*
Main.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
�������� � ����������� SFML.
���������� ����������-������, ���������������� ����� .h �.�.�. - �����.
���������� "�������", ��������� ��� ������� TAB.
��� ���������� ������ � ��������� �����, ��� ������� � ������� �����!
	������: xHero - ���������� ���������� �� ��������� ����� �� �. MoveHero - ������� ���������� �� ������������ �����.
���������� ��� ����� ������ ������������, ������� ������� �� ����:
	//����������� ����������� ���
	���
�����:
	���			//����������� ����������� ���

�������� �����������:(����������)
	����-����������� �������/����������, ����� ��� ������� � �� ������������ � �������� ���������.

	GL HF
*/
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")			//���������� �������

#include <conio.h>
#include "ViewsAndWindow.h"
#include "MainFunctions.h"
#include "Maps.h"
#include "HeroHealthBar.h"
#include "HeroStaminaBar.h"

using namespace sf;


//���H ������� ������ �������� �� ������ �� �����
//����� �� ��������������� ���������� � main ��������� ����������� �� #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
/*void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//����� �������
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//����� �������� �� �
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//����� �������� �� Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//����� �������� ������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//����� ������� �� �����
}*/

int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");									//������ ����
	//window.setFramerateLimit(60);														//����������� FPS
	//window.setVerticalSyncEnabled(true);												//����������� FPS=60

	View MainView;																		//������ ������ ����
	Hero MainHero("HeroSpritesBig.png", 1100, 500, 100, 74, 30, 15, 45, 59, 200, 100);	//������� �����
	HeroHealthBar healthBar;															//������� ��� ��������
	HeroStaminaBar staminaBar;															//������� ��� ������������
	MainView.reset(FloatRect(0,0,1280,720));											//��������� ������ ���� �� �����

	Clock clock;													//������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).	
	
	float time;
	float stime = 0;																		
	

	SetLayers(v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());							//������������� �������� �� �����
	while (window.isOpen())											//��������� ���� ���� �������
	{
		time = clock.getElapsedTime().asMicroseconds();				//�������� ��������� ����� � �������������
		clock.restart();											//������������� ����
		time = time / 800;											//�������� ����
		stime += time;												//������ ������
		
		//ConsoleCheck(MainHero,time, false, true,false,false,false,false);//����, ����� �������� �� ������ � ������� !!!��������������,���� �� ������������, �� ��������� �����!!!

		Event event;
		while (window.pollEvent(event))																		//������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
		}


		healthBar.updateBar(MainHero.Get_healthH(), MainHero.Get_healthMaxH(),10);							//��������� ��� ��������
		staminaBar.updateBar(MainHero.Get_staminaH(), MainHero.Get_staminaMaxH(), 10);						//��������� ��� ������������
		
		ControlsMainCharacter(MainHero,time,stime);															//���������� ������� ����������
		ViewXYfromClassHero(MainView, MainHero.Get_XH(), MainHero.Get_YH());								//����������� ������ ���� �� ���������

		SetLayersAnim(v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());					//������������� ���������� �������� �� �����
		IntersectionHeroWithEnvironment(MainHero, v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());				//�������� ������� MainHero �� ����������� � ��������� ���������

		DrawEnvironment(MainView, time, v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());	//���������� � ��������� ���� �������� ����� �� ���������
		MainHero.Draw(time);																				//���������� � ��������� ���������
		
		window.setView(MainView);
		window.clear();																						//������� ���� �� ����������� �������
		
		SpitesOfEnvironmentUncrossable(window, time, v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());												//��������� ��������� (�����)
		SpitesOfEnvironmentBeforeHero(window, time, MainHero.Get_YHReal() + MainHero.Get_HHReal(), v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());//��������� �� ���������
		window.draw(MainHero.Get_Sprite());																																//��������� �� ������ ������� ���������
		SpitesOfEnvironmentAfterHero(window, time, MainHero.Get_YHReal() + MainHero.Get_HHReal(), v, v[MainHero.Get_currentMap()].size(), MainHero.Get_currentMap());	//��������� ����� ���������

		healthBar.drawHealthBar(window);																	//��������� ��� ��������
		staminaBar.drawStaminaBar(window);																	//��������� ��� ������������
		window.display();																					//�����������


	}
	return 0;
}




