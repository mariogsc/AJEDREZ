#include <Peon.h>
#include <ETSIDI.h>


void Peon::dibuja()
{
	//if (x == 1) {
		if (color == COLOR::BLANCO) {
			glDisable(GL_LIGHTING);
			glTranslatef(posicion.y, -posicion.x - 6, 0);
			ImagenPeonB.setCenter(0, 0);
			ImagenPeonB.setSize(1, 1);
			ImagenPeonB.draw();
			glTranslatef(-posicion.y, posicion.x + 6, 0);
			glEnable(GL_LIGHTING);
		}

		if (color == COLOR::NEGRO) {
			glDisable(GL_LIGHTING);
			glTranslatef(posicion.y + 1, posicion.x - 2, 0);
			ImagenPeonN.setCenter(0, 0);
			ImagenPeonN.setSize(1, 1);
			ImagenPeonN.flip(true, true);
			ImagenPeonN.draw();
			glTranslatef(-posicion.y - 1, -posicion.x + 2, 0);
			glEnable(GL_LIGHTING);
		}
}
