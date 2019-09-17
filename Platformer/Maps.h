#pragma once
/*
��� ��������� ���������� ����.
���� ����� - ���� ������.
��� ���� �����:
	�������, � ��� �� ��������
*/

#include "ClassObject.h"

using namespace sf;

/*
������� ��������� �������� �� �����:
������ ������ ���� �����/�����, ����� ��� ��� �������
������ � ������ ���������� ������ �� ������ ���� ������ 5!
���������� ������������ ������� �� ������ ����� ��������� � ����������

�������� ������� �������:
1) ������ �� �������� ��������� ���������� ���������� ������ ����� �������
2) ���� �� �������� ������� ��������
3) ��������� ������ �� ����� �� �
4) ��������� ������ �� ����� �� Y
5) ����� X ������ �������� � �����
6) ����� Y ������ �������� � �����
7) ������ �������� ���������� �� �����
8) ������ �������� ���������� �� �����
9) ����� �� ����� ��� �������� (������� ����� ���� ����������)
10) ��������� ���������� ������ � �������� �� �
11) ��������� ���������� ������ � �������� �� Y
12) ������ ���������� � �������� ������
13) ������ ���������� � �������� ������
14) true-������ ������������ ����� ��������
15) true-������ ������������ ����� �������
16) true-������ ������������ �����������
17) true-������ ������������ ��������
18) ��������� ������ ���������� ������ �������, ����� ����� ����� ����� ��������� � true 14||15||16||17||18
19) �������� �� ������ "��������"?
20) ����������� "��������"

������� ����� ����� � �������;
*/
Object map1[] = {
	Object(false, "Maps/undMap3.png", -10000, -4500, 0, 0, 3250, 1000, false, 0, 0, 0, 23000, true, false, false, false, 1, true, 1.1),
	Object(false, "Maps/TestMap5.png", 0, 0, 0, 0, 4000, 2250, true, 0, 0, 4000, 2250, true, false, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1700, 330, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1750, 350, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, true, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 1800, 340, 0, 0, 167, 210, true, 45, 160, 35, 35, false, false, false, true, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 890, 470, 0, 0, 0, 0, true , 0, 0, 500, 20, false, false, false,false, 1, false, 0),		//������ ���������� �������, � �������� ���������� ������ ������ �����������(�������� � ��������, �� ������� ��������� �������� ����� ������.)
	Object(true, "Objects/Tree.png", 2620, 435, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3065, 559, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3149, 743, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2326, 752, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2304, 1394, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 2430, 1313, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Tree.png", 3030, 1581, 0, 0, 167, 210, true, 45, 160, 35, 35, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2508, 602, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 1307, 1353, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2368, 1307, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 2554, 815, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Rocks.png", 1926, 573, 0, 0, 75, 52, true, 30, 25, -25, 15, false, true, false, false, 1, false, 0),
	Object(true, "Objects/lake.png", 1508, 733, 0, 0, 196, 41, true, 0, 0, 0, 0, false, true, false, false, 1, false, 0),
	Object(true, "Objects/lake.png", 2318, 1395, 0, 0, 196, 41, true, 5, 0, 0, 0, false, true, false, false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 917, 495, 0, 0, 0, 0, true , 0, 0, 500, 2, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 777, 698, 0, 0, 0, 0, true , 0, 0, 550, 50, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 736, 702, 0, 0, 0, 0, true , 0, 0, 100, 50, false, false, false,false, 1, false, 0),
	Object(true, "Objects/Obstacles.png", 770, 480, 0, 0, 0, 0, true , 0, 0, 100, 100, false, false, false,false, 1, false, 0),



















};
const unsigned short int lengthMap1 = sizeof(map1) / sizeof(map1[0]);	//������� ��������������� �������� ���������� ��������� � �������
