#pragma once
#pragma once
#include "freeglut.h"
#include <ETSIDI.h>

using ETSIDI::getTexture;

using ETSIDI::Sprite;
class Reina
{
	Sprite* ReinaNegro = new Sprite("imagenes/ReinaNegro.png", 17.5, 37.5, 5.0, 5.0);
	Sprite* ReinaBlanco = new Sprite("imagenes/ReinaBlanco.png", 17.5, 2.5, 5.0, 5.0);
public:
	void dibuja();
};

