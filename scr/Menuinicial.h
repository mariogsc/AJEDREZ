#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;

class menuinicial
{
	float x_ojo = 0.0;
	float y_ojo = 0.0;
	float z_ojo = 20.0;


public:
	int opcion = 1;
	void dibuja();
	void flecha(int key);
	Sprite* menu = new Sprite("imagenes/menu1.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* menu2 = new Sprite("imagenes/menu2.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* realsociedad = new Sprite("imagenes/realsociedad.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* atletico = new Sprite("imagenes/atletico.png", 0.0, 0.0, 15.0, 15.0);
	Sprite* espana = new Sprite("imagenes/espana.png", 0.0, 0.0, 15.0, 15.0);


};


