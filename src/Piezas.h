#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Vector.h>
#pragma once  // IMPORTANTE A�ADIRLO SI NO DA ERROR C2011

class Piezas
{
public:
	enum TIPO { NT = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY }; // Enumeracion de todos los tipos posibles
	enum COLOR { NC = -1, BLANCO, NEGRO };  // Enumeraci�n de todos los colores posibles
protected: //PARA QUE SIRVE??
	//bool seleccionado;
	Vector posicion;
	TIPO tipo;
	COLOR color;
public:
	Piezas() :posicion(0.0, 0.0),tipo(NT),color(NC) {} // Consturctor por defecto
	virtual void Dibuja() {}; // Funcion para realizar el polimorfismo ----TODAVIA NO LO HEMOS VISTO----
};

