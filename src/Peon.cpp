#include <Peon.h>
#include <ETSIDI.h>
#include <freeglut.h>

void Peon::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	ImagenPeonN.draw(); // Dibujamos el peon
	glPopMatrix();
		
}

void Peon::mueve() {
	if (seleccionado = true)
	{
		SetPos({posicion.x,posicion.y+1});
	}
}

void Peon::PosibleMov() {
	//posible.DibujaCasilla({ posicion.x,posicion.y + 1 }, 0.005);
	//posible.SetPos({ posicion.x,posicion.y + 1 });
}

