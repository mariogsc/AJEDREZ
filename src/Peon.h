
#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>


class Peon:public Piezas { // CREAMOS UNA CLASE PEON POR HERENCIA DE LA CLASE PIEZAS
	
	//SpriteSequence ImagenPeonB{ "imagenes/PeonBlanco.png", 1 };  // ¿Cual es la dieferencia entre sprite y spritesequence?
public:
	Peon(Vector p, COLOR c) { tipo = Piezas::PEON, color = c, posicion = p; } // Constructor para inicializar las variables
	Sprite ImagenPeonN{ "imagenes/PeonNegro.png", 0, 0, tam, tam };
	float añadir = 2.0; // Casillas que se puede mover el peon
	void Dibuja(); 
	void mueve();
	void PosibleMov();
	void SetPos(Vector p) { posicion = p; }
};

