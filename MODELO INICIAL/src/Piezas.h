#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Vector.h>
#pragma once  // IMPORTANTE AÑADIRLO SI NO DA ERROR C2011

class Piezas
{
public:
	enum TIPO { NT = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY }; // Enumeracion de todos los tipos posibles
	enum COLOR { NC = -1, BLANCO, NEGRO };  // Enumeración de todos los colores posibles
protected: 
	bool seleccionado=false;
	Vector posicion;
	TIPO tipo;
	COLOR color;
	float tam=1.0; // Definimos un atributo constante que compartiran todas las piezas (no debe ser modificado)
	// ¿Se puede hacer static?

	virtual void Dibuja() {};
	virtual void mueve() {}; // Funcion para realizar el polimorfismo del movimiento
	virtual bool CheckMov(Vector v,int check) { return false; }
	virtual void SetPos(Vector p) { posicion = p; }

	friend class Tablero;
	
};

