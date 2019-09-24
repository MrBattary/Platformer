#include "ClassObject.h"

/*
��������� ��������:
1)��������� �����, � ������� ��������
2)�������� �������� � ������
3)��������� ������� �������� �� �������
*/
void Object::Draw(View view, float time) {
	if (tracking == true) {
		sf::Vector2f vector=view.getCenter();																			//���� ������ "��������"
		spriteObject.setPosition(xR+ (vector.x - xR) /trackingCoefficient, yR + (vector.y - yR) / trackingCoefficient);	//�������������� ������������� ����� ��������� ����������� �� ������ ����
	}
	else
	{
		spriteObject.setPosition(xR, yR);																				//���� ���, �� ��� ����������
	}
	spriteObject.setTexture(textureObject);
	spriteObject.setTextureRect(IntRect(xM, yM, wM, hM));
}
