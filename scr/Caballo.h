#pragma once
#include "freeglut.h"
#include <ETSIDI.h>

using ETSIDI::getTexture;

using ETSIDI::Sprite;

class Caballo
{
	Sprite** CaballoBlanco = new Sprite * [1];
	Sprite** CaballoNegro = new Sprite * [1];
public:
	void dibuja();
};

