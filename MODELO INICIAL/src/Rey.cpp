#include <Rey.h>
#include <ETSIDI.h>
#include <freeglut.h>


Rey::Rey(Vector p, COLOR c) {
	tipo = REY;
	color = c;
	posicion = p;
	ImagenReyN.setCenter(0.0, 0.0);
	ImagenReyB.setCenter(0.0, 0.0);
}

void Rey::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenReyB.draw();
	else if (color == NEGRO) ImagenReyN.draw();
	glPopMatrix();

}

bool Rey::CheckMov(Vector v, int check) {
	bool retorno = false;
	if (check != 2)
	{
		if ((v.x == posicion.x || v.x == posicion.x + 1 || v.x == posicion.x - 1) && (v.y == posicion.y || v.y == posicion.y + 1 || v.y == posicion.y - 1)) retorno = true;
	}
	else return false;
	return retorno;

}