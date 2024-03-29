#include "Caballo.h"
#include <ETSIDI.h>
#include <freeglut.h>


Caballo::Caballo(Vector p, COLOR c) {
	tipo = CABALLO;
	color = c;
	posicion = p;
	ImagenCaballoN.setCenter(0.0, 0.0);
	ImagenCaballoB.setCenter(0.0, 0.0);
}

void Caballo::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenCaballoB.draw();
	else if (color == NEGRO) ImagenCaballoN.draw();
	glPopMatrix();

}

bool Caballo::CheckMov(Vector v, int check) {

	bool retorno = false;

	if (check != 2) {
		if (((v.x == posicion.x - 1 || v.x == posicion.x + 1) && (v.y == posicion.y - 2 || v.y == posicion.y + 2)) || (v.x == posicion.x - 2 || v.x == posicion.x + 2) && (v.y == posicion.y - 1 || v.y == posicion.y + 1))
			retorno = true;

	}

	return retorno;

}
