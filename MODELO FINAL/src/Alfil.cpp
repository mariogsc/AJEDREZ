#include "Alfil.h"
#include <ETSIDI.h>
#include <freeglut.h>

Alfil::Alfil(COLOR c) :Pieza(ALFIL, c, c == Blanco ? "imagenes/AlfilBlanco.png" : "imagenes/AlfilNegro.png") {}

bool Alfil::validarMovimiento(Vector origen, Vector destino, Tablero& t) {
    int variacionX = destino.x - origen.x;
    int variacionY = destino.y - origen.y;

    if (abs(variacionX) != abs(variacionY)) {
        // Si la variación en x no es igual a la variación en y en valor absoluto, no es un movimiento diagonal
        return false;
    }

    int pendienteX = (variacionX > 0) ? 1 : -1;
    int pendienteY = (variacionY > 0) ? 1 : -1;

    int x = origen.x + pendienteX;
    int y = origen.y + pendienteY;

    while (x != destino.x || y != destino.y) {
        if (t.getPieza(x, y) != nullptr) {
            // Si hay una pieza en la diagonal, el movimiento es inválido
            return false;
        }
        x += pendienteX;
        y += pendienteY;
    }

    if ((t.getPieza(destino.x, destino.y) != nullptr) && (t.getPieza(origen.x, origen.y)->getColor() == t.getPieza(destino.x, destino.y)->getColor()))  return false;
    // Movimiento válido si no se encontraron piezas en la diagonal
    return true;
}
