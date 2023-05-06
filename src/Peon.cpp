#include <Peon.h>
#include <ETSIDI.h>
#include <freeglut.h>


Peon::Peon(Vector p, COLOR c) { 
	tipo = Piezas::PEON; 
	color = c; 
	posicion = p; 
	ImagenPeonN.setCenter(0.0, 0.0);
	//seleccionado = false;
}

void Peon::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	ImagenPeonN.draw(); // Dibujamos el peon
	glPopMatrix();
		
}

void Peon::mueve() {
	if (seleccionado == true)
	{

	}
}

bool Peon::CheckMov(Vector v) {
	bool retorno= false;
	
	if (v.x == posicion.x && v.y == posicion.y + 1.0f) retorno = true;
	else (retorno = false);
	//if(retorno==false) ETSIDI::play("sonidos/error.wav");
	return retorno;
}

