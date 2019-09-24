#pragma once
/*
��� ��������� ���������� ����.
���� ����� - ���� ������.
��� ���� �����:
	�������, � ��� �� ��������
*/

#include <vector>
#include "ClassObject.h"

using namespace std;
using namespace sf;

/*
������� ��������� �������� �� �����:
������ ������ ���� �����/�����, ����� ��� ��� �������
������ � ������ ���������� ������ �� ������ ���� ������ 5!
���������� ������������ ������� �� ������ ����� ��������� � ����������

vector[����� ����� �� ������� ��������� ������][����� �������][���������� ������ �������]

�������� ������� �������:
1) ������ �� �������� ��������� ���������� ���������� ������ ����� �������
2) �������� ��������
3) ���� �� �������� ������� ��������
4) ��������� ������ �� ����� �� �
5) ��������� ������ �� ����� �� Y
6) ����� X ������ �������� � �����
7) ����� Y ������ �������� � �����
8) ������ �������� ���������� �� �����
9) ������ �������� ���������� �� �����
10) ����� �� ����� ��� �������� (������� ����� ���� ����������)
11) ��������� ���������� ������ � �������� �� �
12) ��������� ���������� ������ � �������� �� Y
13) ������ ���������� � �������� ������
14) ������ ���������� � �������� ������
15) true-������ ������������ ����� ��������
16) true-������ ������������ ����� �������
17) true-������ ������������ �����������
18) true-������ ������������ ��������
19) ��������� ������ ���������� ������ �������, ����� ����� ����� ����� ��������� � true 14||15||16||17||18
20) �������� �� ������ "��������"?
21) ����������� "��������"

������� ����� ����� � �������;
*/

vector <vector <vector <Object> > > v = {
	//����� � 1
	{
		{Object(false,0.001,"Maps/undMap3.png", -10000, -4500, 0, 0, 3250, 1000, false, 0, 0, 0, 23000, true, false, false, false, 1, true, 1.1, 0)},	//000
		{Object(false,0.001, "Maps/TestMap5.png", 0, 0, 0, 0, 4000, 2250, true, 0, 0, 4000, 2250, true, false, false, false, 1, false, 0, 0)},			//010
		{Object(true,0.001, "Objects/Tree.png", 1700, 330, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0, 0)},			//020
		{Object(true,0.001, "Objects/Tree.png", 1750, 350, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, true, false, 1, false, 0, 0)},			//030
		{Object(true,0.001, "Objects/Tree.png", 1800, 340, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, false, true, 1, false, 0, 0)},			//040
		{Object(true,0.001, "Objects/Obstacles.png", 890, 470, 0, 0, 0, 0, true , 0, 0, 500, 20, false, false, false,false, 1, false, 0, 0)},			//050	//������ ���������� �������, � �������� ���������� ������ ������ �����������(�������� � ��������, �� ������� ��������� �������� ����� ������.)
		{Object(true,0.001, "Objects/Grass.png", 1800, 800, 0, 0, 1, 5, true , 0, -6, 1, 1, true, false, false,false, 1, false, 0, 0),					//060
			Object(true,0.001, "Objects/Grass.png", 1800, 800, 2, 0, 2, 5, true , 0, -6, 1, 1, true, false, false,false, 1, false, 0, 0),				//061
			Object(true,0.001, "Objects/Grass.png", 1800, 800, 5, 0, 3, 5, true , 0, -6, 1, 1, true, false, false,false, 1, false, 0, 0),				//062
			Object(true,0.001, "Objects/Grass.png", 1800, 800, 9, 0, 2, 5, true , 0, -6, 1, 1, true, false, false,false, 1, false, 0, 0)},				//063
		{Object(true,0.001, "Objects/Grass.png", 1800, 802, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 1),					//070
			Object(true,0.001, "Objects/Grass.png", 1800, 802, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//071
			Object(true,0.001, "Objects/Grass.png", 1800, 802, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//072
			Object(true,0.001, "Objects/Grass.png", 1800, 802, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//073
		{Object(true,0.001, "Objects/Grass.png", 1800, 804, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 2),					//080
			Object(true,0.001, "Objects/Grass.png", 1800, 804, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//081
			Object(true,0.001, "Objects/Grass.png", 1800, 804, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//082
			Object(true,0.001, "Objects/Grass.png", 1800, 804, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//083
		{Object(true,0.001, "Objects/Grass.png", 1802, 800, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 3),					//0100
			Object(true,0.001, "Objects/Grass.png", 1802, 800, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0101
			Object(true,0.001, "Objects/Grass.png", 1802, 800, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0102
			Object(true,0.001, "Objects/Grass.png", 1802, 800, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//0103
		{Object(true,0.001, "Objects/Grass.png", 1802, 802, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),					//0110
			Object(true,0.001, "Objects/Grass.png", 1802, 802, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0111
			Object(true,0.001, "Objects/Grass.png", 1802, 802, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0112
			Object(true,0.001, "Objects/Grass.png", 1802, 802, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//0113
		{Object(true,0.001, "Objects/Grass.png", 1802, 804, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 1),					//0120
			Object(true,0.001, "Objects/Grass.png", 1802, 804, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0121
			Object(true,0.001, "Objects/Grass.png", 1802, 804, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0122
			Object(true,0.001, "Objects/Grass.png", 1802, 804, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//0123
		{Object(true,0.001, "Objects/Grass.png", 1804, 800, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 2),					//0130
			Object(true,0.001, "Objects/Grass.png", 1804, 800, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0131
			Object(true,0.001, "Objects/Grass.png", 1804, 800, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0132
			Object(true,0.001, "Objects/Grass.png", 1804, 800, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//0133
		{Object(true,0.001, "Objects/Grass.png", 1804, 802, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 3),					//0140
			Object(true,0.001, "Objects/Grass.png", 1804, 802, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0141
			Object(true,0.001, "Objects/Grass.png", 1804, 802, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0142
			Object(true,0.001, "Objects/Grass.png", 1804, 802, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)},				//0143
		{Object(true,0.001, "Objects/Grass.png", 1804, 804, 0, 0, 1, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),					//0150
			Object(true,0.001, "Objects/Grass.png", 1804, 804, 2, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0151
			Object(true,0.001, "Objects/Grass.png", 1804, 804, 5, 0, 3, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0),				//0152
			Object(true,0.001, "Objects/Grass.png", 1804, 804, 9, 0, 2, 5, true , 0, 4, 1, 1, true, false, false,false, 1, false, 0, 0)}				//0153
	}
	//����� � 2
};