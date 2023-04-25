#include"Caballo.h"
#include <ETSIDI.h>

void Caballo::dibuja() {
	float PosCaballo = 7.5;
	for (int i = 0; i < 8; i++) {
		if (i < 2) {
			CaballoNegro[i] = new Sprite("imagenes/CaballoNegro.png", PosCaballo, 37.5, 6.0, 6.0);
			CaballoBlanco[i] = new Sprite("imagenes/CaballoBlanco.png", PosCaballo, 2.5, 6.0, 6.0);
			CaballoBlanco[i]->draw();
			CaballoNegro[i]->draw();
			PosCaballo += 25.0;
		}
	}
}