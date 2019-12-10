#include "ViewsAndWindow.h";

//TODO: Необходимо понять почему дёргается камера
void ViewXYfromClassHero(View& MainView, float x, float y) { MainView.setCenter(x + 50, y + 37); }							//Удержание центра камеры на герое