#include "ClassObjectAnim.h"

/*
��������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
*/

void AnimObject::Draw(View view)
{
	if (tracking == true) {
		sf::Vector2f vector = view.getCenter();																				//���� ������ "��������"
		spriteObject.setPosition(xR + (vector.x - xR) / trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//�������������� ������������� ����� ��������� ����������� �� ������ ����
	}
	else
	{
		if(animated == true)																								//���� ������������� ������ ���������
		spriteObject.setPosition(xR, yR);																					//���� ��������� ������ ����� ���������
	}
}