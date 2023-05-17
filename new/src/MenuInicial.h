#pragma once

#include "Vector.h"
#include <ETSIDI.h>


using ETSIDI::Sprite;

class MenuInicial
{
	Sprite* menu1 = new Sprite("imagenes/menu1.png", 4.0, 4.0, 8.0, 8.0);
	Sprite* menu2 = new Sprite("imagenes/menu2.png", 4.0, 4.0, 8.0, 8.0);
	Sprite* etsidi = new Sprite("imagenes/fondoetsidi.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* atletico = new Sprite("imagenes/fondoatletico.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* espana = new Sprite("imagenes/fondoespaña.png", 4.0, 4.0, 4.0, 4.0);

	bool comienzo; // Variable auxiliar para elegir selección al pulsar intro
	int modo;
	int equipo;
public:
	MenuInicial();
	void dibuja();
	void teclaEspecial(int key);
	void tecla(int key);

	// FUNCIONES DE INTERFAZ
	bool GetComienzo() { return comienzo; }
	int GetModo() { return modo; }
	int GetEquipo() { return equipo; }

};



