#include <Vector.h>
#include <ColorCasilla.h>
#pragma once

class Casilla
{
	float tam;
	Vector pos;
	ColorCasilla color;
public:
	Casilla() :tam(1.0), pos(0.0, 0.0) {}; //Constructor de casilla por defecto inicializa longitud a 1, posicion al 0.0 y color por defecto(0,0,0) y la dibuja
	
	// NO HACE FALTA DESTRUCTOR PORQUE LAS CASILLAS NO SE DESTRUYEN DURANTE LA PARTIDA SOLO AL FINAL
	void DibujaCasilla(Vector posicion);
	void SetPos(Vector p) { this->pos = p; } // Se asigna el valor pos al introducido en la función (encapsulamieto)
	Vector GetPos() { return pos; } // Se retorna el Vectro pos (encapsulamiento)
	void SetColor(unsigned char r ,unsigned char v, unsigned char a);
};

