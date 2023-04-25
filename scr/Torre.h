#pragma once
#include "freeglut.h"
#include <ETSIDI.h>

using ETSIDI::getTexture;

using ETSIDI::Sprite;

class Torre
{
	Sprite** TorreBlanco = new Sprite * [1];
	Sprite** TorreNegro = new Sprite * [1];

public:
	void dibuja();

};

