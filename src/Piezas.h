#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Vector.h>
#pragma once  // IMPORTANTE AÑADIRLO SI NO DA ERROR C2011

class Piezas
{
public:
	enum TIPO { NT = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY }; // Enumeracion de todos los tipos posibles
	enum COLOR { NC = -1, BLANCO, NEGRO };  // Enumeración de todos los colores posibles
public: 
	bool seleccionado;
	Vector posicion;
	TIPO tipo;
	COLOR color;
	const float tam=1.0; // Definimos un atributo constante que compartiran todas las piezas (no debe ser modificado)
	// ¿Se puede hacer static?
public:
	//Piezas() {} // Consturctor por defecto (inicializa en la posición 0.5,0.5)
	virtual void Dibuja() {}; // Funcion para realizar el polimorfismo de dibuja
	virtual void mueve() {}; // Funcion para realizar el polimorfismo del movimiento
	friend class Tablero;
	virtual void PosibleMov() {};
	
};

