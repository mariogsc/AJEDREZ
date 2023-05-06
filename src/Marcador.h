#pragma once
#include <ETSIDI.h>
#include "freeglut.h"
#include <ColorCasilla.h>

using namespace ETSIDI;
using ETSIDI::getTexture;

using ETSIDI::Sprite;
class Marcador {
	Sprite* CartelBlancas = new Sprite("imagenes/CartelBlancas.png", 9, 7.6, 1, 0.4);
	Sprite* CartelNegras = new Sprite("imagenes/CartelNegras.png", 10.45, 7.6, 1, 0.4);
	ColorCasilla ColorMarcador;
public:
	void CreaMarcador(ColorCasilla color1, ColorCasilla color2);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetColor(ColorCasilla _color);
};
