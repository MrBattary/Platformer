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

using namespace sf;
/*
//���H ������� ������ �������� �� ������ �� �����
//����� �� ��������������� ���������� � main ����� ����������� � #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
void ConsoleCheck(Hero MainHero, float time, bool timecheck, bool speedXH, bool speedHY, bool cooldownJump, bool cooldownSlide, bool comboTimer)		
{
	if (timecheck == true) std::cout << time << "|";												//����� �������
	if (speedXH == true)std::cout << MainHero.Get_speedXH() << "|";									//����� �������� �� �
	if (speedHY == true)std::cout << MainHero.Get_speedXY() << "|";									//����� �������� �� Y
	if (cooldownJump == true)std::cout << MainHero.Get_cooldownAnimationJump() << "|";				//����� �������� ������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (cooldownSlide == true)std::cout << MainHero.Get_cooldownAnimationSlide() << "|";			//����� �������� ����������
	if (comboTimer == true) std::cout << MainHero.Get_comboTimer() << "|";							//����� ������� �� �����
}
*/
int main() {

	RenderWindow window(VideoMode(1280, 720), "Test");									//������ ����
	window.setFramerateLimit(60);														//����������� FPS

	View MainView;																		//������ ������ ����
	Hero MainHero("HeroSpritesBig.png", 1100, 500, 100, 74, 30, 15, 45, 59, 100);		//������� �����
	MainView.reset(FloatRect(0,0,1280,720));											//��������� ������ ���� �� �����

	Clock clock;													//������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).	
	
	float time;

	while (window.isOpen())											//��������� ���� ���� �������
	{
		time = clock.getElapsedTime().asMicroseconds();				//�������� ��������� ����� � �������������
		clock.restart();											//������������� ����
		time = time / 800;											//�������� ����
		
		//ConsoleCheck(MainHero,time,true,false,false,false,false,false);//����, ����� �������� �� ������ � ������� !!!��������������,���� �� ������������, �� ��������� �����!!!

		Event event;
		while (window.pollEvent(event))																		//������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
		}

		
		ControlsMainCharacter(MainHero,time);																//���������� ������� ����������
		ViewXYfromClassHero(MainView, MainHero.Get_XH(), MainHero.Get_YH());								//����������� ������ ���� �� ���������

		SetLayers(map1, lengthMap1);																		//������������� �������� �� �����
		IntersectionHeroWithEnvironment(MainHero, map1, lengthMap1);										//�������� ������� MainHero �� ����������� � ��������� ���������

		DrawEnvironment(MainView, map1, lengthMap1);														//���������� � ��������� ���� �������� ����� �� ���������
		MainHero.Draw(time);																				//���������� � ��������� ���������
		
		window.setView(MainView);
		window.clear();																						//������� ���� �� ����������� �������
		
		SpitesOfEnvironmentUncrossable(window, map1, lengthMap1);													//��������� ��������� (�����)
		SpitesOfEnvironmentBeforeHero(window, MainHero.Get_YHReal() + MainHero.Get_HHReal()+3, map1, lengthMap1);	//��������� �� ���������
		window.draw(MainHero.Get_Sprite());																			//��������� �� ������ ������� ���������
		SpitesOfEnvironmentAfterHero(window, MainHero.Get_YHReal() + MainHero.Get_HHReal()+3, map1, lengthMap1);	//��������� ����� ���������
		
		window.display();																					//�����������
	}
	return 0;
}




