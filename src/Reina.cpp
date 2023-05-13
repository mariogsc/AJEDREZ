#include <Reina.h>
#include <ETSIDI.h>
#include <freeglut.h>
#include <Tablero.h>

Reina::Reina(Vector p, COLOR c) {
	tipo = REINA;
	color = c;
	posicion = p;
	ImagenReinaN.setCenter(0.0, 0.0);
	ImagenReinaB.setCenter(0.0, 0.0);
}

void Reina::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenReinaB.draw();
	else if (color == NEGRO) ImagenReinaN.draw();
	glPopMatrix();

}

bool Reina::CheckMov(Vector v, int check) {
	bool retorno = false;

	for (int j = 0; j < 8; j++)
	{
		if (check != 2) {
			if ((v.x == posicion.x - j || v.x == posicion.x + j) && (v.y == posicion.y - j || v.y == posicion.y + j)) retorno = true;


		}
	}

	for (int i = 0; i < 8; i++) {
		if (check != 3) {
			if (((v.x == posicion.x - i || v.x == posicion.x + i) && (v.y == posicion.y)))retorno = true; //movimiento horizontal de la torre
			else if ((v.y == posicion.y - i || v.y == posicion.y + i) && (v.x == posicion.x)) retorno = true; // movimiento vertical de la torre
		}
	}
	
	return retorno;

}