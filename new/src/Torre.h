#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Pieza.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>

class Torre:public Pieza
{

public:
	Torre(COLOR c);
	
	// Añadimos override para la comprobación de que el polimorfismo es correcto
	bool validarMovimiento(Vector& origen, Vector& destino, Tablero &tablero);  

};
