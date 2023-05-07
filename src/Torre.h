#pragma once
#pragma once
#include <ETSIDI.h>
using ETSIDI::Sprite;
#include <Piezas.h>
#include <Vector.h>
#include <Casilla.h>

class Torre: public Piezas{

public:
		Torre(Vector p, COLOR c);
		Sprite ImagenTorreN{ "imagenes/TorreNegro.png", 0, 0, tam, tam };
		Sprite ImagenTorreB{ "imagenes/TorreBlanco.png", 0, 0, tam, tam };
		void Dibuja();

};
