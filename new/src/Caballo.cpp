#include "Caballo.h"
#include <ETSIDI.h>
#include <freeglut.h>

Caballo::Caballo(COLOR c) :Pieza(CABALLO, c, c == Blanco ? "imagenes/CaballoBlanco.png" : "imagenes/CaballoNegro.png") {}

bool Caballo::validarMovimiento(Vector origen, Vector destino, Tablero& tablero) {

    int diferenciax = abs(destino.x - origen.x);
    int diferenciay = abs(destino.y - origen.y);

    if ((tablero.getPieza(destino.x, destino.y) != nullptr) && (tablero.getPieza(origen.x, origen.y)->getColor() == tablero.getPieza(destino.x, destino.y)->getColor()))  return false;

    if ((diferenciax == 2 && diferenciay == 1) || (diferenciax == 1 && diferenciay == 2)) {
               return true;
    }

    return false;

}

