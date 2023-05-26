#include <Alfil.h>
#include <ETSIDI.h>
#include <freeglut.h>
#include <Tablero.h>

Alfil::Alfil(Vector p, COLOR c) {
	tipo = ALFIL;
	color = c;
	posicion = p;
	ImagenAlfilN.setCenter(0.0, 0.0);
	ImagenAlfilB.setCenter(0.0, 0.0);
}

void Alfil::Dibuja() { // Dibujamos el peon

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.1); // Transladamos un poco por arriba del tablero (eje z)
	if (color == BLANCO) ImagenAlfilB.draw();
	else if (color == NEGRO) ImagenAlfilN.draw();
	glPopMatrix();

}

bool Alfil ::CheckMov(Vector v, int check) {
	bool retorno = false;

		for (int j = 0; j < 8; j++)
		{
			if(check !=2){
				if ((v.x == posicion.x - j || v.x == posicion.x + j) && (v.y == posicion.y - j || v.y == posicion.y + j)) retorno = true;

				
			}
		}
	return retorno;
	
}