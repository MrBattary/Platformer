#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//����� �� �������� ����������� ��� ������ NPC
class NPC {
protected:
	float xN = 0.f;						//��������� ����������� ������ �� �
	float yN = 0.f;						//��������� ����������� ������ �� y
	float wN = 0.f;						//������ ������	��� ������������
	float hN = 0.f;						//������ ������ ��� ������������
	float xNReal = 0.f;					//� �������� ������ ������ ����������� ������ ������������� ���� ���
	float yNReal = 0.f;					//Y �������� ������ ������ ����������� ������ ������������� ���� ���
	float xNRealInside = 0.f;			//� �������� ������ ������ ����������� ������
	float yNRealInside = 0.f;			//Y �������� ������ ������ ����������� ������
	float wNRealInside = 0.f;			//������ �������� ������ ������ ����������� ������
	float hNRealInside = 0.f;			//������ �������� ������ ������ ����������� ������

	float dxN = 0;						//��������� �� �
	float dyN = 0;						//��������� �� y
	float speedNX = 0;					//�������� NPC �� x
	float speedNY = 0;					//�������� NPC �� y

	float clutchObj = 1;				//��������� NPC � ������������ �� ������� �� �����
	int dirN = 0;						//����������� ��������/�������
	int currentMap = 0;					//������� �����

	int healthN = 1;					//�������� NPC
	int healthMaxN = 1;

	String File;						//���� � �����������
	Image image;						//�����������
	Texture texture;					//��������
	Sprite sprite;						//������
	signed int layerN = 1;				//���� ���������

	float currentFrame = 0;				//����� �������� ����� ����������� ��������
	float currentUncycleFrame = 0;		//����� �������� ����� �� ����������� ��������

	bool movableN = false;				//�������� �� ������ ������� ����������� ����� NPC?
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