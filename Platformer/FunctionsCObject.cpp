#include "ClassObject.h"

/*
��������� ��� ��������� ������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� ������� !!!����� ���������!!!
*/
void Object::Draw(View view) {	//��������
	return;
}

//��������� ������� �� ���� ��� ���������� ������������������ ���������
void Object::DetermineLayer()
{
	if (crossable == false) {
		layer = yRReal + hRReal;
	}
	else {//������� ��� ����
		layer = yRReal /*+ hRReal/4*/;
	}
}
