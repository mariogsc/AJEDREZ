#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Pieza.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>
#include <iostream>
#include <cmath>

class Reina :public Pieza
{

public:
	Reina(COLOR c);

	bool validarMovimiento(Vector origen, Vector destino, Tablero& tablero);
	void DibujaPosible(Vector origen, Tablero& t);
	Pieza* clonar() { return new Reina(*this); }
};

