#include "Coordinador.h"
#include "freeglut.h"
#

Coordinador::Coordinador() {
	estado = MENU;

	//TAMAÑO Y POSICION
	Blancas->setSize(8.0, 8.0);
	Blancas->setPos(2.0, 2.0);

	Negras->setSize(8.0, 8.0);
	Negras->setPos(2.0, 2.0);
}

void Coordinador::inicializa() {
	ajedrez.inicializa();

}

void Coordinador::dibuja() { //METER TODO LO RELATIVO A 
	if (estado == INICIO) { 
		//
		//meter una foto en ajedrez que se menu que le des a E para empezar solo

	}
	else if (estado == MENU) {

	
		ajedrez.dibujaMenu();
		//METER EL MENU con 1 pasar a sel equipo
		//Y 2 salir del programa
		//Se puede meter a mano por tecla o pasarkle una funcion de ajedrez o tablero con la moneda cara o cruz;
	}
	else if (estado == SELECCION) {
		//ajedrez.dibujaMenu();
		//separar el menu
		//ajedrez.dibujaMenu();
	}
	else if (estado == PARTIDA) {
		ajedrez.dibujaPartida();
		//crear una funcion dentro de ajedrez llamada dibuaj tablero y pasarsela
		//esa funcion solo tiene la informacion del tablero y tiene que tener todo lo de dibuja posibles...

	}
	else if (estado == GANA_B) {
		Blancas->draw();
		//poner en tablero mismamente las imagenes de gana b
	}
	else if (estado == GANA_N) {
		Negras->draw();
		//poner en tablero mismamente las imagenes gana N
	}
	else if (estado == PAUSA) {
		//SE PUEDE METER UNA IMAGEN QUEDA MEJOR CREO	
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("SE ENCUENTRA EN EL ESTADO DE PAUSA", -5, 8);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR DEL JUEGO", -5, 6);

	}





}



void Coordinador::Raton(int button, int state, int x, int y) {
	if (estado == PARTIDA)
		ajedrez.Raton( button,  state,  x,  y);
}

void Coordinador::teclaEspecial(unsigned char key)
{
	ajedrez.teclaEspecial(key);
}


void Coordinador::tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e' || key == 'E') {
			//
			//En nuestro caso ya hemos metido la condicion get comienzo en ajeder
			
			estado = MENU;
		}
	}
	if (estado == MENU) {
		ajedrez.tecla(key);
		if(key==' ')estado = PARTIDA;
		//if (key=='t')estado = PARTIDA;
		
		
		/*
		if (key == '1') {
			//funcion dibuja menu
			estado = SELECCION;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}*/
	}
	if (estado == SELECCION) {
		//le podemos meter en dibuja lo de que vaya a los lados o definir una funcion aparte y meterla
		ajedrez.tecla(key);
		if(key=='x') estado=PARTIDA;
	}
	if (estado == PARTIDA) {
		//
		if (key == 'p' || key == 'P') estado = PAUSA;
	}
	if (estado == PAUSA) {
		if (key == 'c'|| key == 'C') {
			//continuar
			estado = PARTIDA;
		}
		else if (key == 'S' || key == 's') {
			//SALIR DEL JUEGO
			exit(0);
		}
		else if (key == 'v' || key == 'V') {
			estado = MENU;
		}
	}
	if (estado == GANA_N || estado == GANA_B) {
		//poner en la imagen que si le das a V cuelces a empezar y S sales del programa
		if (key == 'V'|| key == 'v') {
			estado = INICIO;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}

	}
}
