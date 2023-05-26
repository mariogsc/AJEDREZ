#include "Reina.h"
#include <ETSIDI.h>
#include <freeglut.h>

Reina::Reina(COLOR c) :Pieza(REINA, c, c == Blanco ? "imagenes/ReinaBlanco.png" : "imagenes/ReinaNegro.png") {}

bool Reina::validarMovimiento(Vector origen, Vector destino, Tablero & t) {

    if (origen.x == destino.x || origen.y == destino.y) { //si el movimiento es horizontal o vertical
        if (origen == destino) {
            // si es la misma casilla
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
    else {
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
    
}