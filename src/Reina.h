#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>
#include <Tablero.h>


class Reina: public Piezas
{
public:
	Reina(Vector p, COLOR c); // Constructor para inicializar las variables
	Sprite ImagenReinaN{ "imagenes/ReinaNegro.png", 0, 0, tam, tam };
	Sprite ImagenReinaB{ "imagenes/ReinaBlanco.png", 0, 0, tam, tam };
	void Dibuja();
	bool CheckMov(Vector v, int check);


};

