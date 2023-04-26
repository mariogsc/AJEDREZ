#include "Menuinicial.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include <cstdlib>
using ETSIDI::Sprite;


void menuinicial::flecha(int key) {
	switch (key) {


	case GLUT_KEY_UP:
		if (opcion==2) {
			opcion -= 1;
		}
		break;


	case GLUT_KEY_DOWN:
		if (opcion == 1) {
			opcion += 1;
		}
		break;

	case GLUT_KEY_LEFT:
		if (opcion == 6) {
			opcion = 8;
		}
		else if ((opcion == 7) || (opcion == 8)) opcion -= 1;
		break;

	case GLUT_KEY_RIGHT:
		if (opcion == 8) {
			opcion = 6;
		}
		else if ((opcion == 6) || (opcion == 7)) opcion += 1;
		break;

	case 13:
		if (opcion == 6) {
			exit(0);
		}
		if (opcion == 1) { //si le damos cuando estamos en iniciar el juego
			opcion = 6;   // Selecciona tu equipo, se pone la real como primera opcion
		}
		if (opcion == 7) {
			exit(0);
		}
		if (opcion == 8) {
			exit(0);
		}
		if (opcion == 2) exit(0);
		

		break;
	}
}




void menuinicial::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo

	if (opcion == 1) {
		menu->draw();
	}

	if (opcion == 2) {
		menu2->draw();
	}

	if (opcion == 6) {
		realsociedad->draw();
	}

	if (opcion == 7) {
		atletico->draw();
	}

	if (opcion == 8) {
		espana->draw();
	}
}


