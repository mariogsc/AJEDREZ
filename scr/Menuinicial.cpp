#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
using ETSIDI::Sprite;


void Mundo1::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	menu->draw();
	

}


void Mundo1::tecla(unsigned char key) {

	if (key == 'w') {

	}
		
	
}



