#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Pieza.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>

class Alfil:public Pieza
{	
public:
	Alfil(COLOR c);

	bool validarMovimiento(Vector origen, Vector destino, Tablero& t);
	Pieza* clonar() { return new Alfil(*this); }
};

