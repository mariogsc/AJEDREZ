#pragma once
#include "freeglut.h"
#include <ETSIDI.h>

using ETSIDI::getTexture;

using ETSIDI::Sprite;

class Alfil
{
	Sprite** AlfilBlanco = new Sprite * [1];
	Sprite** AlfilNegro = new Sprite * [1];
public:
	void dibuja();
};

