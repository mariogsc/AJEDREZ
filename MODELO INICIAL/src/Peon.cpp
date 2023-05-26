#include <Peon.h>
#include <ETSIDI.h>
#include <freeglut.h>


Peon::Peon(Vector p, COLOR c) {
	tipo = PEON;
	color = c;
	posicion = p;
	primeravez = true;
	ImagenPeonN.setCenter(0.0, 0.0);
	ImagenPeonB.setCenter(0.0, 0.0);
}

void Peon::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenPeonB.draw();
	else if (color == NEGRO) ImagenPeonN.draw();
	glPopMatrix();

}

bool Peon::CheckMov(Vector v, int check) {
	bool retorno = false;

	// Se comprueba si es el primer movimiento del peon para poder avanzar dos casillas
	if (primeravez) {
		if (color == BLANCO && (v.x == posicion.x && v.y == posicion.y + 1.0 || v.x == posicion.x && v.y == posicion.y + 2.0)) {
			retorno = true;
			primeravez = false;
		}
		else if (color == NEGRO && (v.x == posicion.x && v.y == posicion.y - 1.0 || v.x == posicion.x && v.y == posicion.y - 2.0)) {
			retorno = true;
			primeravez = false;
		}


	}
	// movimiento normal del peon (1 casilla)
	else if (primeravez == false) {
		if (color == BLANCO && v.x == posicion.x && v.y == posicion.y + 1.0) retorno = true;
		else if (color == NEGRO && v.x == posicion.x && v.y == posicion.y - 1.0)retorno = true;
	}

	// Se compruba si se puede comer o si la casilla de delante esta ocuapada

	if (check == 1) {
		if (color == BLANCO) {
			if ((v.x == posicion.x - 1.0 || v.x == posicion.x + 1.0) && v.y == posicion.y + 1.0) {
				retorno = true; // si la casilla de arriba y a los lados esta ocupada 
			}
			else retorno = false;
		}
		if (color == NEGRO) {
			if ((v.x == posicion.x - 1.0 || v.x == posicion.x + 1.0) && v.y == posicion.y - 1.0)
			{
				retorno = true; // si la casilla de debajo y los lados esta ocupada 
			}
			else retorno = false;
		}
	}
	else if (check == 2) {
		retorno = false;
	}


	return retorno;
}