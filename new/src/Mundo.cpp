#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "cstdlib"

void Mundo::inicializa() {
	x_ojo=5.5;
	y_ojo=4.0;
	z_ojo=12.0;
}


void Mundo::dibuja()
{ 
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		5.5, 4.0, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	//llamamos a la funcion dibuja de cada uno de los objetos que hemos definido en el .h
	
	menu.dibuja();

	if (menu.GetComienzo() == true) {
		if (menu.GetEquipo() == 0) {
			Color color1(255, 255, 255);
			Color color2(0, 0, 255);
		}
		else if (menu.GetEquipo() == 1) {
			Color color1(255, 255, 255);
			Color color2(255, 0, 0);
		}
		else if (menu.GetEquipo() == 2) {
			Color color1(250, 189, 0); // COLOR GUALDA
			Color color2(255, 0, 0);

			tablero.dibuja(color1, color2);
		}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	menu.teclaEspecial(key);
}

void Mundo::tecla(unsigned char key)
{

	menu.tecla(key);
}
