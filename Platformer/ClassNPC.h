#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//����� �� �������� ����������� ��� ������ NPC
class NPC {
protected:
	float xN;							//��������� ����������� ������ �� �
	float yN;							//��������� ����������� ������ �� y
	float wN;							//������ ������	��� ������������
	float hN;							//������ ������ ��� ������������
	float xNReal;						//� �������� ������ ������ ����������� ������ ������������� ���� ���
	float yNReal;						//Y �������� ������ ������ ����������� ������ ������������� ���� ���
	float xNRealInside;					//� �������� ������ ������ ����������� ������
	float yNRealInside;					//Y �������� ������ ������ ����������� ������
	float wNRealInside;					//������ �������� ������ ������ ����������� ������
	float hNRealInside;					//������ �������� ������ ������ ����������� ������

	float dxN;							//��������� �� �
	float dyN;							//��������� �� y
	float speedNX = 0;					//�������� NPC �� x
	float speedNY = 0;					//�������� NPC �� y

	float clutchObj = 1;				//��������� NPC � ������������ �� ������� �� �����
	int dirN;							//����������� ��������/�������
	int currentMap = 0;					//������� �����

	int healthN;						//�������� NPC
	int healthMaxN;

	String File;						//���� � �����������
	Image image;						//�����������
	Texture texture;					//��������
	Sprite sprite;						//������
	signed int layerN;					//���� ���������

	float currentFrame = 0;				//����� �������� ����� ����������� ��������
	float currentUncycleFrame = 0;		//����� �������� ����� �� ����������� ��������
public:
	NPC() {}

	//Get-�������

	Sprite Get_Sprite() { return sprite; }										//�������� ������
	int Get_currentMap() { return currentMap; }									//������ �� ����� ����� ������ ���������
	int Get_healthN() { return healthN; }										//������ �������� �������� NPC
	int Get_healthMaxN() { return healthMaxN; }									//������ ������������ �������� NPC
	signed int Get_layerN() { return layerN; }									//��������� ���� �� ������� ������������� NPC
	float Get_XN() { return xN; }												//�������� ��������� ����������� ������ �� �
	float Get_YN() { return yN; }												//�������� ��������� ����������� ������ �� �
	float Get_WN() { return wN; }												//�������� ������ ������
	float Get_HN() { return hN; }												//�������� ������ ������
	float Get_XNReal() { return xNReal; }										//�������� ��������� �������� ������ �� ��� �
	float Get_YNReal() { return yNReal; }										//�������� ��������� �������� ������ �� ��� �
	float Get_XNRealInside() { return xNRealInside; }							//�������� � �������� ������
	float Get_YNRealInside() { return yNRealInside; }							//�������� y �������� ������
	float Get_WNRealInside() { return wNRealInside; }							//�������� ������ �������� ������
	float Get_HNRealInside() { return hNRealInside; }							//�������� ������ �������� ������
	float Get_clutchObj() { return clutchObj; }									//�������� �������� ��������� NPC � ������������ �� ������� �� �����

	//Set-�������

	void Set_currentMap(int value) { currentMap = value; }						//���������� ����� ������� �����
	void Set_healthN(int value) { healthN = value; }							//���������� ������� �������� �����
	void Set_healthMaxN(int value) { healthMaxN = value; }						//���������� ������������ �������� �����
	void Set_XN(float value) { xN = value; }									//���������� ��������� ����������� ������ �� �
	void Set_YN(float value) { yN = value; }									//���������� ��������� ����������� ������ �� �
	void Set_XNReal(float value) { xNReal = value; }							//���������� ��������� �������� ������ �� �
	void Set_YNReal(float value) { yNReal = value; }							//���������� ��������� �������� ������ �� �
	void Set_XNRealInside(float value) { xNRealInside = value; }				//���������� x ��a����� ������
	void Set_YNRealInside(float value) { yNRealInside = value; }				//���������� y ��a����� ������
	void Set_WNRealInside(float value) { wNRealInside = value; }				//���������� ������ ��a����� ������
	void Set_HNRealInside(float value) { hNRealInside = value; }				//���������� ������ ��a����� ������
	void Set_clutchObj(float value) { clutchObj = value; }						//���������� �������� ��������� ��������� � ������������ �� ������� �� �����
	void Set_layerN(signed int value) { layerN = value; }						//��������� ����

	virtual void Draw(float);													//����� ������ � ��������
	void SetRealSizeNPC(float, float, float, float);							//��������� �������� ���������� ������
};