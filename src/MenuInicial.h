#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class MenuInicial
{
		Sprite* menu1 = new Sprite("imagenes/menu1.png", 4.0, 4.0, 8.0, 8.0);
		Sprite* menu2 = new Sprite("imagenes/menu2.png", 4.0, 4.0, 8.0, 8.0);
		Sprite* realsociedad = new Sprite("imagenes/fondorealsociedad.png", 4.0, 4.0, 4.0, 4.0);
		Sprite* atletico = new Sprite("imagenes/fondoatletico.png", 4.0, 4.0, 4.0, 4.0);
		Sprite* espana = new Sprite("imagenes/fondoespaña.png", 4.0, 4.0, 4.0, 4.0);
		bool comienzo; // Variable auxiliar para comenzar la partida
		int modo ; // Variable para seleccion de modo
		int equipo ; // Variable para seleccion de equipo
public:
		MenuInicial() ;
		void dibuja();
		void flecha(int key);
		bool GetComienzo() { return comienzo; }
		int GetModo() { return modo; }
		int GetEquipo() { return equipo; }
		
};

