#include "Piezas.h"
#include <ETSIDI.h>
#include"Peones.h"
#include"Rey.h"
#include"Reina.h"
#include"Torre.h"
#include"Alfil.h"
#include"Caballo.h"

Peones peones;
Rey rey;
Reina reina;
Torre torre;
Alfil alfil;
Caballo caballo;


void Piezas::ImprimePiezas() {

	peones.dibuja();
	torre.dibuja();
	alfil.dibuja();
	caballo.dibuja();
	rey.dibuja();
	reina.dibuja();
}



