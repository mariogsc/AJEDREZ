#include "Casilla.h"
#include <freeglut.h>

Casilla::Casilla() :tam(1.0), pos(0.0, 0.0) {
	for (int i = 0; i < 32; i++) {
		p = nullptr; // Inicializamos todos los punteros de las fichas apuntando a nada (nullptr)
	}
}
void Casilla::DibujaCasilla(Vector posicion, float x) {

	glBegin(GL_POLYGON);
	glVertex3f(posicion.x, posicion.y, x);
	glVertex3f(posicion.x + tam, posicion.y, x);
	glVertex3f(posicion.x + tam, posicion.y + tam, x);
	glVertex3f(posicion.x, posicion.y + tam, x);
	glEnd();

}


void Casilla::SetColor(unsigned char r ,unsigned char v, unsigned char a) {
	this->color.SetColor(r, v, a);
}

void Casilla::SetColor(ColorCasilla _color) {
	this->color.SetColor(_color.GetRojo(), _color.GetVerde(), _color.GetAzul());
}

void Casilla::DibujaPiezas() {
	for (int i = 0; i < 32; i++) {
		//p[i].Dibuja();
	}
}
