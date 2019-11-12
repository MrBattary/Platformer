#include "ClassObject.h"

/*
��������� ��� ��������� ������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� ������� !!!����� ���������!!!
*/
void Object::Draw(View view) {
	if (tracking == true) {
		sf::Vector2f vector=view.getCenter();																			//���� ������ "��������"
		spriteObject.setPosition(xR+ (vector.x - xR) /trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//�������������� ������������� ����� ��������� ����������� �� ������ ����
	}

	/*spriteObject.setTexture(textureObject);
	spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));*/
}

//��������� ������� �� ���� ��� ���������� ������������������ ���������
void Object::SetLayer()
{
	if (crossable == false) {
		layer = yRReal + hRReal;
	}
	else {
		layer = yRReal /*+ hRReal/4*/;
	}
}
