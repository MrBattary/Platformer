#include "ViewsAndWindow.h";

void SpritesObjectsAndNPCs(RenderWindow& window, Hero h, vector<vector<Object>> vO, vector<vector<NPCFriendly>> vN) //��� ������� �������� �������� �� ���� ����
{
	for (int layer = 0; layer < 10000; layer++)																				//����������� �� �����
	{
		if (h.Get_layerH() == layer) { window.draw(h.Get_Sprite()); }														//���� ����� ���������� �� ���� ����������� ����� �� ����� � ������� SFML

		for (int i = 0; i < vO.size(); i++) 
		{
			if (vO[h.Get_currentMap()][i].Get_layer() == layer) { window.draw(vO[h.Get_currentMap()][i].Get_Sprite()); }
		}

		for (int j = 0; j < vN.size(); j++)
		{
			if (vN[h.Get_currentMap()][j].Get_layerN() == layer) { window.draw(vN[h.Get_currentMap()][j].Get_Sprite()); }
		}
	}
}


void ViewXYfromClassHero(View& MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }						//��������� ������ ������ �� �����