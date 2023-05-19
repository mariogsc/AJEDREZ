#include "Casilla.h"
#include <freeglut.h>

		
void Casilla::DibujaCasilla(Vector posicion, float x = 0.0) {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glVertex3f(posicion.getx(), posicion.gety(), x);
	glVertex3f(posicion.getx() +tam, posicion.gety(), x);
	glVertex3f(posicion.getx() + tam, posicion.gety() + tam, x);
	glVertex3f(posicion.getx(), posicion.gety() + tam, x);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::DibujaCasilla(float x = 0.0) {
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(0,255,0);
	glVertex3f(pos.x+0.1, pos.y+0.1, x);
	glVertex3f(pos.x + tam-0.1, pos.y+0.1, x);
	glVertex3f(pos.x + tam-0.1, pos.y + tam-0.1, x);
	glVertex3f(pos.x+0.1, pos.y + tam-0.1, x);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Casilla::SetColor(unsigned char r ,unsigned char v, unsigned char a) {
	this->color.SetColor(r, v, a);
}

void Casilla::SetColor(Color _color) {
	this->color.SetColor(_color.GetRojo(), _color.GetVerde(), _color.GetAzul());
}
