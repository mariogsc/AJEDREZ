#include "Coordinador.h"
#include "freeglut.h"
#include <ETSIDI.h>

Coordinador::Coordinador() :sobrecargaintro(0) {
	estado = INICIO;

	//TAMAÑO Y POSICION
	
}

void Coordinador::inicializa() {
	x_ojo = 5.5;
	y_ojo = 4.0;
	z_ojo = 12.0;


}

void Coordinador::dibuja() {

	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		5.5, 4.0, 0.0,      // hacia que punto mira  
		0.0, 1.0, 0.0);     // definimos hacia arriba (eje Y)

	//METER TODO LO RELATIVO A 
	if (estado == INICIO) {
		ajedrez.dibujaInicio();
	}
	else if (estado == MENU) {
		ajedrez.dibujaMenu();
	}
	
	else if (estado == PARTIDA) {
		ajedrez.dibujaPartida();

	}
	else if (estado == GANA_B) {
		ajedrez.dibujaB();
	}
	else if (estado == GANA_N) {
		ajedrez.dibujaN();
	}
	else if (estado == PAUSA) {
		ajedrez.dibujaPartida();
		ajedrez.dibujaPausa();
	}
	else if (estado == TABLAS) {
		ajedrez.dibujaTablas();
	};

}


void Coordinador::Raton(int button, int state, int x, int y) {
	if (estado == PARTIDA)
		ajedrez.Raton(button, state, x, y);
}

void Coordinador::teclaEspecial(unsigned char key)
{
	ajedrez.teclaEspecial(key);
}


void Coordinador::tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == ' ') {
			estado = MENU;
		}
	}
	if (estado == MENU) {
		ajedrez.tecla(key);
		if (key == 13 && sobrecargaintro == 0)sobrecargaintro = 1;
		else if (key == 13 && sobrecargaintro == 1) {
			estado = PARTIDA;
			sobrecargaintro == 2;
		}
	}
	if (estado == PARTIDA) {
		if (key == 'p' || key == 'P') estado = PAUSA;
		//if (key == 'o') estado = GANA_B;
		
	}
	if (estado == PAUSA) {
		if (key == 'c' || key == 'C') {
			//continuar
			estado = PARTIDA;
		}
		else if (key == 'S' || key == 's') {
			//SALIR DEL JUEGO
			exit(0);
		}
		else if (key == 't' || key == 'T') {
			estado = TABLAS;
		}
		else if (key == 'N'|| key == 'n') {
			estado = GANA_B;
		}
		else if (key == 'B' || key == 'b') {
			estado = GANA_N;
		};
	}
	if(estado==TABLAS){
		if (key == 'S' || key == 's') {
			//SALIR DEL JUEGO
			exit(0);
		}	
	}
	if (estado == GANA_N || estado == GANA_B) {
		//poner en la imagen que si le das a V cuelces a empezar y S sales del programa
		if (key == 'S' || key == 's') {
			exit(0);
		}

	}
}
