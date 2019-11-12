#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "ClassObject.h"

using namespace std;
using namespace sf;

//�������� ����������� ���������� �� .��� � .h

void DisplayEnvironment(RenderWindow& window, float time, int I, int L, vector<vector<vector<Object>>>& v, int currentMap)					//������� ���������� �� ��������� �� ����� ��������, ��� �������������
{
	v[currentMap][I][0].Set_currentFrame(v[currentMap][I][0].Get_currentFrame() + v[currentMap][I][L].Get_animSpeed() * time);
	//if (v[currentMap][I][0].Get_currentFrame() >= v[currentMap][I].size()) { v[currentMap][I][0].Set_currentFrame(v[currentMap][I][0].Get_currentFrame() - v[currentMap][I].size()); }
	if (v[currentMap][I][0].Get_currentFrame()+0.1>= v[currentMap][I].size()) { v[currentMap][I][0].Set_currentFrame(0); }	//0.1, ����� ���� ����� ���������� ������������.
	if (L == (int)v[currentMap][I][0].Get_currentFrame()) {
		window.draw(v[currentMap][I][L].Get_Sprite());				//����� �� ����� � ������� SFML
	}
}

//!!!������!!!
void SpitesOfEnvironmentUncrossable(RenderWindow & window, float time, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)//��������� �������� �� ������������ ����, � ��� ����� �� ����� ����������������� ���������
{					
	for (unsigned short int j = 10000; j > 0; j--) {																						//������ ������: ��������� ��� ���� ����� �����!
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i].size(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == false)
				{
					DisplayEnvironment(window, time, i, l, v, currentMap);
				}
			}
		}
	}
}

void SpitesOfEnvironmentUncrossable(RenderWindow& window, Sprite sprite, signed int layer)	//��������� �������� �� ������������ ����, � ��� ����� �� ����� ����������������� ���������
{
	for (unsigned short int j = 10000; j > 0; j--) {										//������ ������: ��������� ��� ���� ����� �����!
		if (layer == j)
		{
			window.draw(sprite);															//����� �� ����� � ������� SFML
		}
	}
}

//!!!������!!!
void SpitesOfEnvironmentBeforeHero(RenderWindow & window, float time,  float Yhero, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)//��������� �������� �� ������������ �� �����
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = 0; j < heroY; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i].size(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == true)
				{
					DisplayEnvironment(window, time, i, l, v, currentMap);
				}
			}
		}
	}
}
//!!!������!!!
void SpitesOfEnvironmentAfterHero(RenderWindow & window, float time, float Yhero, vector<vector<vector<Object>>>& v, int length_arrObj, int currentMap)	//��������� �������� �� ������������ ����� �����
{					
	int heroY = roundf(Yhero);
	for (unsigned short int j = heroY; j < 5000; j++)
	{
		for (int i = 0; i < length_arrObj; i++) {
			for (int l = 0; l < v[currentMap][i].size(); l++)
			{
				if (v[currentMap][i][l].Get_layer() == j && v[currentMap][i][l].Get_crossable() == true)
				{
					DisplayEnvironment(window, time, i, l, v, currentMap);
				}
			}
		}
	}
}

void ViewXYfromClassHero(View & MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }						//��������� ������ ������ �� �����

//��� ��������� ���� ���� ����� ��������