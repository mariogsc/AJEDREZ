#include "Torre.h"
#include <ETSIDI.h>
#include <freeglut.h>
#include <Tablero.h>

Torre::Torre(Vector p, COLOR c) {
	tipo = TORRE;
	color = c;
	posicion = p;
	ImagenTorreN.setCenter(0.0, 0.0);
	ImagenTorreB.setCenter(0.0, 0.0);
}

void Torre::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenTorreB.draw();
	else if (color == NEGRO) ImagenTorreN.draw();
	glPopMatrix();

}

bool Torre::CheckMov(Vector v, int check) {
	bool retorno = false;

	for (int j = 0; j < 8; j++)
	{
		if (check != 2) {
			if ((v.x == posicion.x - j || v.x == posicion.x + j) && (v.y == posicion.y - j || v.y == posicion.y + j)) retorno = true;
		}
	}



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (check != 2) {
				if (v.x == posicion.x - j || v.x == posicion.x + j)retorno = true;
			}
		}
	}

	return retorno;

}