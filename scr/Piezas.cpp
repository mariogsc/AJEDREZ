#include "Piezas.h"
#include <ETSIDI.h>

void Piezas::ImprimePiezas() {
	float PosPeon = -17.5;  // por que si lo quito y lo defino en la clasde no va
	float PosTorre = -17.5;
	float PosCaballo = -12.5;
	float PosAlfil = -7.5;

	for (int i = 0; i < 8; i++) {

		PeonNegro[i] = new Sprite("imagenes/PeonNegro.png", PosPeon, 12.5, 6.0, 6.0);
		PeonBlanco[i] = new Sprite("imagenes/PeonBlanco.png", PosPeon, -12.5, 6.0, 6.0);
		PeonBlanco[i]->draw();
		PeonNegro[i]->draw();
		PosPeon += 5.0;

		if (i < 2) {
			//Impresion de torres
			TorreNegro[i]= new Sprite("imagenes/TorreNegro.png", PosTorre, 17.5, 6.0, 6.0);
			TorreBlanco[i]= new Sprite("imagenes/TorreBlanco.png", PosTorre, -17.5, 6.0, 6.0);
			TorreBlanco[i]->draw();
			TorreNegro[i]->draw();
			PosTorre += 35.0;

			//Impresion de Caballos
			CaballoNegro[i] = new Sprite("imagenes/CaballoNegro.png", PosCaballo, 17.5, 6.0, 6.0);
			CaballoBlanco[i] = new Sprite("imagenes/CaballoBlanco.png", PosCaballo, -17.5, 6.0, 6.0);
			CaballoBlanco[i]->draw();
			CaballoNegro[i]->draw();
			PosCaballo += 25.0;

			//Impresion de Alfiles
			AlfilNegro[i] = new Sprite("imagenes/AlfilNegro.png", PosAlfil, 17.5, 6.0, 6.0);
			AlfilBlanco[i] = new Sprite("imagenes/AlfilBlanco.png", PosAlfil, -17.5, 6.0, 6.0);
			AlfilBlanco[i]->draw();
			AlfilNegro[i]->draw();
			PosAlfil += 15.0;
		}
	}
	ReyBlanco->draw();
	ReyNegro->draw();
	ReinaBlanco->draw();
	ReinaNegro->draw();
	
}

