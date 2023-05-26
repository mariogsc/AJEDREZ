#include <Vector.h>
#include <ColorCasilla.h>
#pragma once

class Casilla
{
	float ancho;
	float alto;
	Vector pos;
	ColorCasilla color; // Inicializado con constructor por defecto a 0,0,0
public:
	Casilla(); //Constructor de casilla por defecto inicializa ancho=altura=1, posicion al 0.0 y color por defecto(0,0,0)
	void DibujaCasilla(Vector posicion,float x);
	Casilla(ColorCasilla c) { color = c; }
	

	// ENCAPSULAMIENTO
	void SetAncho(float a) {this->ancho=a ; }
	void SetAlto(float a) { this->alto = a; }
	void SetPos(Vector p) { this->pos = p; } // Se asigna el valor pos al introducido en la función (encapsulamieto)
	Vector GetPos() { return pos; } // Se retorna el Vectro pos (encapsulamiento)
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetColor(ColorCasilla _color);
	void CheckPosition();

	friend class Tablero;
	
};

