#pragma once
#include <ETSIDI.h>
#include "freeglut.h"
using namespace ETSIDI;
using ETSIDI::getTexture;

using ETSIDI::Sprite;
class Menu {
	Sprite* CartelBlancas = new Sprite("imagenes/CartelBlancas.png", 9, 7.6, 1, 0.4);
	Sprite* CartelNegras = new Sprite("imagenes/CartelNegras.png", 10.45, 7.6, 1, 0.4);
public:
	void CreaMenu();
};
