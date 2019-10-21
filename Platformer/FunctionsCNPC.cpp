//Определение всех функций класса-родителя "NPC"

#include "ClassNPC.h"

void NPC::SetRealSizeNPC(float xRealIns, float yRealIns, float wRealIns, float hRealIns) {			//Установить новые размеры физической модели NPC
	xNRealInside = xRealIns;
	yNRealInside = yRealIns;
	wNRealInside = wRealIns;
	hNRealInside = hRealIns;
}