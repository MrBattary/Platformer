#include "ClassObject.h"

/*
��������� ��� ��������� ������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� ������� !!!����� ���������!!!
*/
void Object::Draw(View view) {	//��������
	DetermineLayer();
}

//��������� ������� �� ���� ��� ���������� ������������������ ���������
void Object::DetermineLayer()
{
	if(animated==true)
	{
		layer = yRReal + hRReal;
	}
	/*if (crossable == false) {
		layer = yRReal + hRReal;
	}
	else {//������� ��� ����
		layer = yRReal + hRReal/4;
	}*/
}
