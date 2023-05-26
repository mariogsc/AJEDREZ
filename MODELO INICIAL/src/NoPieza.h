#pragma once

#include <Piezas.h>

class NoPieza :public Piezas {
public:
	NoPieza(Vector p) {
		tipo = NT;
		color = NC;
		posicion = p;
	};
};