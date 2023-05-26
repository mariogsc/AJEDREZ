#include "Torre.h"
#include <ETSIDI.h>
#include <freeglut.h>

Torre::Torre(COLOR c) :Pieza (TORRE,c, c==Blanco?"imagenes/TorreBlanco.png":"imagenes/TorreNegro.png"){}

bool Torre::validarMovimiento(Vector origen, Vector destino, Tablero &t) {
    
    if (origen == destino || ((origen.x != destino.x)&&(origen.y!=destino.y))) {
        // Si el movimiento no es ni horizontal ni vertical, es inválido
        return false;
    }

    if (origen.x == destino.x) {
        // Movimiento vertical
        int minY = min(origen.y, destino.y) + 1;
        int maxY = max(origen.y, destino.y);

        for (int y = minY; y < maxY; y++) {

            if (t.getPieza(origen.x, y) != nullptr) {
                // Si hay una pieza en el camino, el movimiento es inválido
                return false;
            }
        }
    }
    else {
        // Movimiento horizontal
        int minX = min(origen.x, destino.x) + 1;
        int maxX = max(origen.x, destino.x);
        for (int x = minX; x < maxX; x++) {
            if (t.getPieza(x, origen.y) != nullptr) {
                // Si hay una pieza en el camino, el movimiento es inválido
                return false;
            }
        }
    }

    if ((t.getPieza(destino.x, destino.y) != nullptr) && (t.getPieza(origen.x, origen.y)->getColor() == t.getPieza(destino.x, destino.y)->getColor()))  return false;

    // Movimiento válido si no se encontraron piezas en el camino
    return true;
}

