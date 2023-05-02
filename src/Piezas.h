#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Vector.h>
#pragma once  // IMPORTANTE AÑADIRLO SI NO DA ERROR C2011

class Piezas
{
public:
	enum TIPO { NT = -1, PEON, CABALLO, TORRE, ALFIL, REINA, REY }; // Enumeracion de todos los tipos posibles
	enum COLOR { NC = -1, BLANCO, NEGRO };  // Enumeración de todos los colores posibles
protected: //PARA QUE SIRVE??
	//bool seleccionado;
	Vector posicion; //Vector objeto que representa la poscion de la pieza
	TIPO tip;
	COLOR col;
public:
	Piezas() :posicion(0.0, 0.0),tipo(NT),color(NC) {} // Consturctor por defecto
	virtual void Dibuja() {}; // Funcion para realizar el polimorfismo ----TODAVIA NO LO HEMOS VISTO----
	void setCasilla(Vector p) { this->posicion = p; } // recibe un objeto de la clase Vector y asigna la posición de la pieza a esa posición.

	Vector getPos() ;  //devuelve posicion de la pieza
	Tipo getTipo(); //devuelve el tipo de pieza
	Color getColor(); //devuelve el color de la pieza

	
};

