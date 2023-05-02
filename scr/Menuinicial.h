#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class menuinicial
{
	float x_ojo = 0.0;
	float y_ojo = 0.0;
	float z_ojo = 20.0;


public:
// PONER TODOS ESTOS COMO PRIVADOS Y CREAR UNA FUNCIÓN QUE SEA GETOPTION Y SETOPTION COMPROBAR EN SETOPTION QUE NO SE PASA DE LOS VALORES DEFINIDOS (ENCAPSULAMIENTO)
// ¿SE PUEDEN PONER LOS SPRITES PRIVADOS?
	int opcion = 1;
	Sprite* menu = new Sprite("imagenes/menu1.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* menu2 = new Sprite("imagenes/menu2.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* realsociedad = new Sprite("imagenes/fondorealsociedad.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* atletico = new Sprite("imagenes/fondoatletico.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* espana = new Sprite("imagenes/fondoespaña.png", 0.0, 0.0, 15.0, 15.0);
	
	
	void dibuja();
	void flecha(int key);
	


};


