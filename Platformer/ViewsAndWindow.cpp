#include "ViewsAndWindow.h";

void ViewXYfromClassHero(View& MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }							//Удержание центра камеры на герое

void Minimap(View& MinimapView, float x, float y) 
{
	MinimapView.setCenter(x / 2, y / 2);
	MinimapView.setSize(x, y);
	MinimapView.setViewport(FloatRect(0.8f, 0.f, 0.2f, 0.2f));
}