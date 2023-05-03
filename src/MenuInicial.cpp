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

MenuInicial::~MenuInicial() {
	menu1->~Sprite();
	menu2->~Sprite();
}

void MenuInicial::flecha(int key) {
	switch (key) {


	case GLUT_KEY_UP:
		if (opcion == 2) {
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
			opcion = 10;
		}
		if (opcion == 1) { //si le damos cuando estamos en iniciar el juego
			opcion = 6;   // Selecciona tu equipo, se pone la real como primera opcion
		}
		if (opcion == 7) {
			opcion = 11;
		}
		if (opcion == 8) {
			opcion = 12;
		}
		if (opcion == 2) exit(0);


		break;
	}
}




int MenuInicial::dibuja()
{
//aqui es donde hay que poner el codigo de dibujo


	if (opcion == 1) {
		menu1->draw();
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

	return opcion;
}
