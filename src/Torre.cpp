#include <Torre.h>
#include <ETSIDI.h>
#include <freeglut.h>

Torre::Torre(Vector p, COLOR c) {
	tipo = TORRE;
	color = c;
	posicion = p;
	ImagenTorreN.setCenter(0.0, 0.0);
	ImagenPeonB.setCenter(0.0, 0.0);
}

void Torre::Dibuja() { // Dibujamos 
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenTorreB.draw();
	else if (color == NEGRO) ImagenTorreN.draw();
	glPopMatrix();
}

bool Torre::CheckMov(Vector v) {
	bool retorno = false;

	if (color == NEGRO && v.x == posicion.x && v.y == posicion.y + 1) {
		retorno = true;
	}
	else if (color == BLANCO && v.x == posicion.x && v.y == posicion.y - 1) {
		retorno = true;
	}
	return retorno;
}
