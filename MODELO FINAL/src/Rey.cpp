#include "Rey.h"
#include <ETSIDI.h>
#include <freeglut.h>

Rey::Rey(COLOR c) :Pieza(REY, c, c == Blanco ? "imagenes/ReyBlanco.png" : "imagenes/ReyNegro.png") {}

bool Rey::validarMovimiento(Vector origen, Vector destino, Tablero& t) {

    if (origen == destino) {//para que no seleccione a su propia ficha como verde
        return false;
    }

    if ((t.getPieza(destino.x, destino.y) != nullptr) && (t.getPieza(origen.x, origen.y)->getColor() == t.getPieza(destino.x, destino.y)->getColor()))  return false;
    //esto sirve para que no seleccione piezas de su mismo color

    int distanciaX = abs(destino.x - origen.x);
    int distanciaY = abs(destino.y - origen.y);

    // El rey puede moverse una casilla en cualquier dirección
    if (distanciaX <= 1 && distanciaY <= 1) {
        return true;
    }

    return false;
}