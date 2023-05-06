#include <Peon.h>
#include <ETSIDI.h>
#include <freeglut.h>

Peon::Peon(Vector p, COLOR c) { 
	tipo = PEON; 
	color = c; 
	posicion = p; 
	ImagenPeonN.setCenter(0.0, 0.0);
	ImagenPeonB.setCenter(0.0,0.0);
}

void Peon::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenPeonB.draw();
	else if (color == NEGRO) ImagenPeonN.draw();
	glPopMatrix();
		
}

bool Peon::CheckMov(Vector v) {
	bool retorno= false;
	
	//Comprovar si es primer movimiento o no

	if (color == NEGRO && v.x == posicion.x && v.y == posicion.y + añadir) {
		retorno = true;
		añadir = 1.0f;
	}
	else if (color == BLANCO && v.x == posicion.x && v.y == posicion.y - añadir) { 
		retorno = true;
		añadir = 1.0f;
	}
	return retorno;
}


