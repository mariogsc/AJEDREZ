#pragma once
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>
class Rey : public Piezas
{
	public:
	Rey(Vector p, COLOR c); // Constructor para inicializar las variables
	Sprite ImagenReyN{ "imagenes/ReyNegro.png", 0, 0, tam, tam };
	Sprite ImagenReyB{ "imagenes/ReyBlanco.png", 0, 0, tam, tam };
	void Dibuja();
	bool CheckMov(Vector v, int check);
	//bool Comer(Vector v);
	//void SetPos(Vector p) { posicion = p; }
};

