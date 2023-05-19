#include "Rey.h"
#include <ETSIDI.h>
#include <freeglut.h>

Rey::Rey(COLOR c) :Pieza(TORRE, c, c == Blanco ? "imagenes/ReyBlanco.png" : "imagenes/ReyNegro.png") {}

bool Rey::validarMovimiento(Vector origen, Vector destino, Tablero& tablero) {

    if (origen == destino) {//para que no seleccione a su propia ficha como verde
        return false;
    }

    if ((tablero.getPieza(destino.x, destino.y) != nullptr) && (tablero.getPieza(origen.x, origen.y)->getColor() == tablero.getPieza(destino.x, destino.y)->getColor()))  return false;
    //esto sirve para que no seleccione piezas de su mismo color

    int distanciaX = abs(destino.x - origen.x);
    int distanciaY = abs(destino.y - origen.y);

    // El rey puede moverse una casilla en cualquier direcci�n
    if (distanciaX <= 1 && distanciaY <= 1) {
        return true;
    }

    return false;
}