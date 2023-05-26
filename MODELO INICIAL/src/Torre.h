#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>

class Torre :public Piezas { // CREAMOS UNA CLASE PEON POR HERENCIA DE LA CLASE PIEZAS

	//SpriteSequence ImagenPeonB{ "imagenes/PeonBlanco.png", 1 };  // ¿Cual es la dieferencia entre sprite y spritesequence?
public:
	Torre(Vector p, COLOR c); // Constructor para inicializar las variables
	Sprite ImagenTorreN{ "imagenes/TorreNegro.png", 0, 0, tam, tam };
	Sprite ImagenTorreB{ "imagenes/TorreBlanco.png", 0, 0, tam, tam };
	void Dibuja();
	bool CheckMov(Vector v, int check);
}; 
