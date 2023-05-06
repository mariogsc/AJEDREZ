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
	
	//Comprobvar si es primer movimiento o no
	
	if (primeravez) {
		if (color == NEGRO && v.x == posicion.x && ( v.y== posicion.y + 1.0 || v.y == posicion.y + 2.0)) {
			retorno = true;
			primeravez = false;

		}
		else if (color == BLANCO && v.x == posicion.x && (v.y == posicion.y - 1.0 || v.y == posicion.y - 2.0)){
			retorno = true;
			primeravez = false;
		}
		return retorno;
	}
	else {

		if (color == NEGRO && v.x == posicion.x && v.y == posicion.y + 1) {
			retorno = true;
			
		}
		else if (color == BLANCO && v.x == posicion.x && v.y == posicion.y - 1) {
			retorno = true;
			
		}

	}
	return retorno;
	
}


