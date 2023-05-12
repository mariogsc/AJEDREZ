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

void Torre::Dibuja() { // Dibujamos Torre

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenTorreB.draw();
	else if (color == NEGRO) ImagenTorreN.draw();
	glPopMatrix();

}


//Comprobacion Movimeinto Torre
bool Torre::CheckMov(Vector v, int check) {
	bool retorno = false;
	
	for (int i = 0; i < 8; i++) {
		if (check != 2) {
			if (((v.x == posicion.x - i || v.x == posicion.x + i) && (v.y == posicion.y)))retorno = true; //movimiento horizontal de la torre
			else if ((v.y == posicion.y - i || v.y == posicion.y + i) && (v.x == posicion.x)) retorno = true; // movimiento vertical de la torre
		}
	}
	return retorno;

}
