#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>

class Caballo :public Piezas { // CREAMOS UNA CLASE PEON POR HERENCIA DE LA CLASE PIEZAS
public:
	Caballo(Vector p, COLOR c); // Constructor para inicializar las variables
	Sprite ImagenCaballoN{ "imagenes/CaballoNegro.png", 0, 0, tam, tam };
	Sprite ImagenCaballoB{ "imagenes/CaballoBlanco.png", 0, 0, tam, tam };
	void Dibuja();
	bool CheckMov(Vector v, int check);
	//bool Comer(Vector v);
	//void SetPos(Vector p) { posicion = p; }

};

