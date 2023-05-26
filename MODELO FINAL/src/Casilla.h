#include <Vector.h>
#include <ColorRGB.h>
#pragma once

class Casilla
{
	int tam;
	Vector pos;
	ColorRGB color; // Inicializado con constructor por defecto a 0,0,0
public:
	Casilla() :color(0,0,0), pos(), tam(1.0) {}; // Constructor por defecto
	Casilla(Vector v, ColorRGB c) :color(c), pos(v),tam(1.0) {};
	void DibujaCasilla(Vector posicion,float x);
	void DibujaCasilla(float x);
	// FUNCIONES DE INTERFAZ
	
	void SetPos(Vector p) { this->pos = p; } // Se asigna el valor pos al introducido en la función (encapsulamieto)
	Vector GetPos() { return pos; } // Se retorna el Vectro pos (encapsulamiento)
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetColor(ColorRGB _color);

	friend class Tablero;
	
};

