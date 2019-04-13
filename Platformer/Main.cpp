/*
Platformer.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
#include <SFML/Graphics.hpp>
#include "ClassHero.h";
#include "MainFunctions.h";

using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode(1280, 720), "Test");		//������ ����
	window.setFramerateLimit(60);								//����������� FPS

	Hero MainHero("HeroSpritesBig.png", 590, 286, 100, 74, 100);//������� �����

	Clock clock;												//������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).	
	
	float time;


	while (window.isOpen())										//��������� ���� ���� �������
	{
		time = clock.getElapsedTime().asMicroseconds();			//�������� ��������� ����� � �������������
		clock.restart();										//������������� ����
		time = time / 800;										//�������� ����
		
		//ConsoleCheck(MainHero,time,false,false,false,false,false,true);//����, ����� �������� �� ������ � ������� !!!��������������,���� �� ������������,��������� �����!!!

		Event event;
		while (window.pollEvent(event))																		//������� �������� ����
		{
			if (event.type == Event::Closed)
				window.close();
		}

		ControlsMainCharacter(MainHero,time);																//���������� ������� ����������
		
		MainHero.Draw(time);																				//��������� ���������

		window.clear();																						//������� ���� �� ����������� �������
		window.draw(MainHero.Get_Sprite());																	//��������� �� ������ �������
		window.display();																					//�����������
	}
	return 0;
}