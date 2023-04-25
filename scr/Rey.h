#pragma once
#include "freeglut.h"
#include <ETSIDI.h>


using ETSIDI::getTexture;

using ETSIDI::Sprite;


class Rey
{
	Sprite* ReyBlanco = new Sprite("imagenes/ReyBlanco.png", 22.5, 2.5, 5.0, 5.0);
	Sprite* ReyNegro = new Sprite("imagenes/ReyNegro.png", 22.5, 37.5, 5.0, 5.0);
public:
	void dibuja();
};

