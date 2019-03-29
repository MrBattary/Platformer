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

#include <conio.h>
#include <SFML/Graphics.hpp>
#include "ClassHero.h";
#include "ControlsCHero.h";

using namespace sf;

int main() {
	RenderWindow window(sf::VideoMode(1600, 900), "Test");		//������ ����
	window.setVerticalSyncEnabled(true);

	Hero MainHero("NoFightSprites1.png",750,376,100,74);		//������� �����

	Clock clock;												//������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).	
	
	float time;


	while (window.isOpen())										//��������� ���� ���� �������
	{
		time = clock.getElapsedTime().asMicroseconds();			//�������� ��������� ����� � �������������
		clock.restart();										//������������� ����
		time = time / 800;										//�������� ����
		
		//ConsoleCheck(MainHero,time,false,false,false,false,false);//����, ����� �������� �� ������ � ������� !!!��������������,���� �� ������������,��������� �����!!!

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