#include "Menuinicial.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
using ETSIDI::Sprite;




/*
void menuinicial::tecla(unsigned char key) {
	if (key == 'w') {
		
	}

}*/

/**/void menuinicial::flecha(int key) {
	if (GLUT_KEY_UP) {
		ETSIDI::playMusica("musica/musicaintro.mp3", true);
		
		if (opcion > 1) {
			opcion -= 1;
			dibuja();
		}
		
	}
	if (GLUT_KEY_DOWN) {
		ETSIDI::playMusica("musica/musicaintro.mp3", true);
		
		if (opcion < 3) {
			opcion += 1;
			dibuja();
		}
		
	}
	if (GLUT_KEY_LEFT) {
		ETSIDI::playMusica("musica/musicaintro.mp3", true);
	
	}
	if (GLUT_KEY_RIGHT) {
		ETSIDI::playMusica("musica/musicaintro.mp3", true);
	
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
	if (opcion == 3) {
		menu3->draw();
	}

}


