#include <Vector.h>
#pragma once

class Casilla
{
	float tam;
	Vector pos;
public:
	Casilla(); //Constructor de casilla por defecto inicializa longitud a 1 y posicion al 0.0
	// NO HACE FALTA DESTRUCTOR PORQUE LAS CASILLAS NO SE DESTRUYEN DURANTE LA PARTIDA SOLO AL FINAL
	void DibujaCasilla(Vector posicion);
	void SetPos(Vector p) { this->pos = p; } // Se asigna el valor pos al introducido en la función (encapsulamieto)
	Vector GetPos() { return pos; } // Se retorna el Vectro pos (encapsulamiento)
};

