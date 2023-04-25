#pragma once
#include "freeglut.h"
#include <ETSIDI.h>

using namespace ETSIDI;
using ETSIDI::getTexture;

using ETSIDI::Sprite;
class Peones
{
	Sprite** PeonNegro = new Sprite * [8];
	Sprite** PeonBlanco = new Sprite * [8];
	//Vector2D posicion = { 0.0,0.0 };
public:
	void dibuja();
};

