#pragma once
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
		int opcion = 1;

public:
		MenuInicial();
		~MenuInicial();
		int dibuja();
		void flecha(int key);
		int GetOpcion() { return opcion; }
		void SetOpcion(int o) { this->opcion = o; }


};

