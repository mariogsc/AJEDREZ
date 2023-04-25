#include"Peones.h"
#include <ETSIDI.h>

void Peones::dibuja() {
	float PosPeon = 2.5;
	for (int i = 0; i < 8; i++)
	{
		PeonNegro[i] = new Sprite("imagenes/PeonNegro.png", PosPeon, 32.5, 6.0, 6.0);
		PeonBlanco[i] = new Sprite("imagenes/PeonBlanco.png", PosPeon, 7.5, 6.0, 6.0);
		PeonBlanco[i]->draw();
		PeonNegro[i]->draw();
		PosPeon += 5.0;
		//PeonBlanco[0]->setPos(0, 0);
		//PeonBlanco[i]->draw();
	}
}