#include "Casilla.h"
#include <freeglut.h>

void Casilla::DibujaCasilla(Vector posicion) {

	glBegin(GL_POLYGON);
	glVertex3f(posicion.x, posicion.y, 0.0);
	glVertex3f(posicion.x + tam, posicion.y, 0.0);
	glVertex3f(posicion.x + tam, posicion.y + tam, 0.0);
	glVertex3f(posicion.x, posicion.y + tam, 0.0);
	glEnd();

}

void Casilla::SetColor(unsigned char r ,unsigned char v, unsigned char a) {
	this->color.SetColor(r, v, a);
}

