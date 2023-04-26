#include "Casilla.h"
#include <freeglut.h>

Casilla::Casilla() :tam(1.0), pos(0.0, 0.0) {
	DibujaCasilla(pos);
}
void Casilla::DibujaCasilla(Vector posicion) {

	glBegin(GL_POLYGON);
	glVertex3f(posicion.x, posicion.y, 0.0);
	glVertex3f(posicion.x + tam, posicion.y, 0.0);
	glVertex3f(posicion.x + tam, posicion.y + tam, 0.0);
	glVertex3f(posicion.x, posicion.y + tam, 0.0);
	glEnd();

}