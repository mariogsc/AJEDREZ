#include "Casilla.h"
#include <freeglut.h>


Casilla::Casilla() : ancho(1.0), alto(1.0), pos(0.0, 0.0) {};
		
void Casilla::DibujaCasilla(Vector posicion, float x = 0.0) {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(posicion.x, posicion.y, x);
	glVertex3f(posicion.x + ancho, posicion.y, x);
	glVertex3f(posicion.x + ancho, posicion.y + alto, x);
	glVertex3f(posicion.x, posicion.y + alto, x);
	glEnd();
	glEnable(GL_LIGHTING);
}


void Casilla::SetColor(unsigned char r ,unsigned char v, unsigned char a) {
	this->color.SetColor(r, v, a);
}

void Casilla::SetColor(ColorCasilla _color) {
	this->color.SetColor(_color.GetRojo(), _color.GetVerde(), _color.GetAzul());
}


void Casilla::CheckPosition() {
	if (pos.x > 7) pos.x = 0;
	if (pos.x < 0) pos.x = 7;
	if (pos.y > 7) pos.y = 0;
	if (pos.y < 0) pos.y = 7;
}