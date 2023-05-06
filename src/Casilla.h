#include <Vector.h>
#include <ColorCasilla.h>
#include <Piezas.h>
#pragma once

class Casilla
{
	float tam;
	Vector pos;
	ColorCasilla color; // Inicializado con constructor por defecto a 0,0,0
	Piezas* p;
public:
	Casilla() ; //Constructor de casilla por defecto inicializa longitud a 1, posicion al 0.0 y color por defecto(0,0,0) y la dibuja
	
	// NO HACE FALTA DESTRUCTOR PORQUE LAS CASILLAS NO SE DESTRUYEN DURANTE LA PARTIDA SOLO AL FINAL
	void DibujaCasilla(Vector posicion, float x);
	
	void CreaPieza(int x, int y, int type, Piezas::COLOR color);
	Casilla(ColorCasilla c) { color = c; }
	
	void SetPos(Vector p) { this->pos = p; } // Se asigna el valor pos al introducido en la función (encapsulamieto)
	Vector GetPos() { return pos; } // Se retorna el Vectro pos (encapsulamiento)
	void SetColor(unsigned char r ,unsigned char v, unsigned char a);
	void SetColor(ColorCasilla _color);
	void DibujaPiezas();
	//void creaPieza(int x, int y, int tipo, Piezas::COLOR color);
	Piezas* setPieza(Piezas* pieza) { this->p = p;	return p; }
	
	friend class Tablero;
};

