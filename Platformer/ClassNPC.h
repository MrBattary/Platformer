#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//����� �� �������� ����������� ��� ������ NPC
//TODO: ��������� ��� ��������������
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

	float dxN = 0;						//��������� �� �
	float dyN = 0;						//��������� �� y
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

	bool movableN;						//�������� �� ������ ������� ����������� ����� NPC?
public:
	NPC() {}

	//Get-�������

	Sprite Get_Sprite() { return sprite; }										//�������� ������
	int Get_currentMap() { return currentMap; }									//������ �� ����� ����� ������ ���������
	int Get_healthN() { return healthN; }										//������ �������� �������� NPC
	int Get_healthMaxN() { return healthMaxN; }									//������ ������������ �������� NPC
	signed int Get_layerN() { return layerN; }									//��������� ���� �� ������� ������������� NPC
	float Get_xN() { return xN; }												//�������� ��������� ����������� ������ �� �
	float Get_yN() { return yN; }												//�������� ��������� ����������� ������ �� �
	float Get_wN() { return wN; }												//�������� ������ ������
	float Get_hN() { return hN; }												//�������� ������ ������
	float Get_xNReal() { return xNReal; }										//�������� ��������� �������� ������ �� ��� �
	float Get_yNReal() { return yNReal; }										//�������� ��������� �������� ������ �� ��� �
	float Get_xNRealInside() { return xNRealInside; }							//�������� � �������� ������
	float Get_yNRealInside() { return yNRealInside; }							//�������� y �������� ������
	float Get_wNRealInside() { return wNRealInside; }							//�������� ������ �������� ������
	float Get_hNRealInside() { return hNRealInside; }							//�������� ������ �������� ������
	float Get_clutchObj() { return clutchObj; }									//�������� �������� ��������� NPC � ������������ �� ������� �� �����
	float Get_speedNX() { return speedNX; }										//�������� �������� �� �
	float Get_speedNY() { return speedNY; }										//�������� �������� �� �
	bool Get_movableN() { return movableN; }									//������ �� NPC?

	//Set-�������

	void Set_currentMap(int value) { currentMap = value; }						//���������� ����� ������� �����
	void Set_healthN(int value) { healthN = value; }							//���������� ������� �������� �����
	void Set_healthMaxN(int value) { healthMaxN = value; }						//���������� ������������ �������� �����
	void Set_xN(float value) { xN = value; }									//���������� ��������� ����������� ������ �� �
	void Set_yN(float value) { yN = value; }									//���������� ��������� ����������� ������ �� �
	void Set_xNReal(float value) { xNReal = value; }							//���������� ��������� �������� ������ �� �
	void Set_yNReal(float value) { yNReal = value; }							//���������� ��������� �������� ������ �� �
	void Set_xNRealInside(float value) { xNRealInside = value; }				//���������� x ��a����� ������
	void Set_yNRealInside(float value) { yNRealInside = value; }				//���������� y ��a����� ������
	void Set_wNRealInside(float value) { wNRealInside = value; }				//���������� ������ ��a����� ������
	void Set_hNRealInside(float value) { hNRealInside = value; }				//���������� ������ ��a����� ������
	void Set_clutchObj(float value) { clutchObj = value; }						//���������� �������� ��������� ��������� � ������������ �� ������� �� �����
	void Set_layerN(signed int value) { layerN = value; }						//��������� ����

	virtual void Draw(float);													//����� ������ � ��������
	virtual void Logic(float) {};												//������
	void SetRealSizeNPC(float, float, float, float);							//��������� �������� ���������� ������
};