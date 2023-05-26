#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>

class Peon:public Piezas { // CREAMOS UNA CLASE PEON POR HERENCIA DE LA CLASE PIEZAS
	
	//SpriteSequence ImagenPeonB{ "imagenes/PeonBlanco.png", 1 };  // ¿Cual es la dieferencia entre sprite y spritesequence?
public:
	Peon(Vector p, COLOR c); // Constructor para inicializar las variables
	Sprite ImagenPeonN{ "imagenes/PeonNegro.png", 0, 0, tam, tam };
	Sprite ImagenPeonB{ "imagenes/PeonBlanco.png", 0, 0, tam, tam };
	bool primeravez; 
	void Dibuja(); 
	bool CheckMov(Vector v,int check);
	//bool Comer(Vector v);
	//void SetPos(Vector p) { posicion = p; }

};
