#include"Alfil.h"
#include <ETSIDI.h>

void Alfil::dibuja() {
	float PosAlfil = 12.5;
	for (int i = 0; i < 8; i++) {
		if (i < 2) {
			AlfilNegro[i] = new Sprite("imagenes/AlfilNegro.png", PosAlfil, 37.5, 6.0, 6.0);
			AlfilBlanco[i] = new Sprite("imagenes/AlfilBlanco.png", PosAlfil, 2.5, 6.0, 6.0);
			AlfilBlanco[i]->draw();
			AlfilNegro[i]->draw();
			PosAlfil += 15.0;
		}
	}

}