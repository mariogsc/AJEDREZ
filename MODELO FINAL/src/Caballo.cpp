#include "Caballo.h"
#include <ETSIDI.h>
#include <freeglut.h>

Caballo::Caballo(COLOR c) :Pieza(CABALLO, c, c == Blanco ? "imagenes/CaballoBlanco.png" : "imagenes/CaballoNegro.png") {}

bool Caballo::validarMovimiento(Vector origen, Vector destino, Tablero& t) {

    int diferenciax = abs(destino.x - origen.x);
    int diferenciay = abs(destino.y - origen.y);
    
    if ((t.getPieza(destino.x, destino.y) != nullptr) && (t.getPieza(origen.x, origen.y)->getColor() == t.getPieza(destino.x, destino.y)->getColor()))  return false;

    if ((diferenciax == 2 && diferenciay == 1) || (diferenciax == 1 && diferenciay == 2)) {
               return true;
    }

    return false;

}

