#pragma once
#include <MenuInicial.h>
#include "freeglut.h"
#include "ETSIDI.h"
#include <cstdlib>
using ETSIDI::Sprite;


MenuInicial::MenuInicial() {
	menu1->setSize(8.0, 8.0);
	menu1->setPos(4.0, 4.0);
	menu2->setSize(8.0, 8.0);
	menu2->setPos(4.0, 4.0);
	realsociedad->setSize(8.0, 8.0);
	realsociedad->setPos(2.0, 2.0);
	atletico->setSize(8.0, 8.0);
	atletico->setPos(2.0, 2.0);
	espana->setSize(8.0, 8.0);
	espana->setPos(2.0, 2.0);
}

void MenuInicial::flecha(int key) {
	if(comienzo==false){
	switch (key) {

	case GLUT_KEY_UP:
		if (modo == 1 && equipo==-1) {
			modo = 0;
		}
		break;


	case GLUT_KEY_DOWN:
		if (modo == 0 && equipo == -1) {
			modo = 1;
		}
		break;

	case GLUT_KEY_RIGHT:
		if (equipo == 0 ) {
			equipo = 1;
		}
		else if (equipo == 1 )
			equipo = 2;
		else if (equipo == 2)
			equipo = 0;
		break;

	case GLUT_KEY_LEFT:
		if (equipo == 2) {
			equipo = 1;
		}
		else if (equipo == 1)
			equipo = 0;
		else if (equipo == 0)
			equipo = 2;
		break;

	case 13:
		if (modo==1 && equipo==-1) {
			exit(0);
		}
		if (modo == 0 && equipo == -1) { //si le damos cuando estamos en iniciar el juego
			equipo = 0;   // Selecciona tu equipo, se pone la real como primera opcion
			delete menu1; 
			delete menu2;
			break;
		}
		// Seleccion de equipo se puede hacer con sobrecarga del espacio
		if (equipo >= 0 && comienzo ==false && modo==0) { 
			delete realsociedad;
			delete espana;
			delete atletico;
			comienzo = true;
		}
		break;
	}
	}
	
}

void MenuInicial::dibuja()
{
//aqui es donde hay que poner el codigo de dibujo


	if (modo == 0 && equipo==-1) { // IMPORTANTE-> hay que poner doble condicion si no intentará dibujar despues de hacer el delete del sprite
		menu1->draw();
	}

	if (modo == 1 && equipo == -1) {
		menu2->draw();
	}
	
	if (equipo == 0 && comienzo == false) {
		realsociedad->draw();
	}

	if (equipo==1 && comienzo == false) {
		atletico->draw();
	}

	if (equipo==2 && comienzo == false) {
		espana->draw();
	}
}
