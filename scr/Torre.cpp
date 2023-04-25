#include "Torre.h"

void Torre::dibuja(){
	float PosTorre = 2.5;
	for (int i = 0; i < 8; i++) {
		if (i < 2) {
			TorreNegro[i] = new Sprite("imagenes/TorreNegro.png", PosTorre, 37.5, 6.0, 6.0);
			TorreBlanco[i] = new Sprite("imagenes/TorreBlanco.png", PosTorre, 2.5, 6.0, 6.0);
			TorreBlanco[i]->draw();
			TorreNegro[i]->draw();
			PosTorre += 35.0;
		}
	}
}
