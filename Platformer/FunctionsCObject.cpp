#include "ClassObject.h"

/*
��������� ��� ��������� ������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� ������� !!!����� ���������!!!
*/
void Object::Draw(View view) {	//TODO: C������ ���������� �� 3 ������� ������, �������, ��������, ������������� � �� �����������: �������� ������������� � �������� �������
	if (movableO == true) {
		DetermineLayer();
		xR = xRReal - xRRealInside;
		yR = yRReal - yRRealInside;
		spriteObject.setPosition(xR, yR);
	}
}

//��������� ������� �� ���� ��� ���������� ������������������ ���������
void Object::DetermineLayer()
{
	if(animated==true)
	{
		layer = yRReal + hRReal;
	}
}
