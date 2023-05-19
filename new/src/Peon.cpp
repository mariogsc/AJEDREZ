
#include "Peon.h"
#include <ETSIDI.h>
#include <freeglut.h>

Peon::Peon(COLOR c) :Pieza(TORRE, c, c == Blanco ? "imagenes/PeonBlanco.png" : "imagenes/PeonNegro.png") {}

//No come 
/*
bool Peon::validarMovimiento(Vector origen, Vector destino, Tablero& tablero) {
    int deltaX = abs(origen.x - destino.x);
    int deltaY = abs(origen.y - destino.y);

    if (deltaX == 0 && deltaY == 1) {
        // Movimiento vertical de una posición
        if (tablero.getPieza(destino.x, destino.y) != nullptr) {
            // Si hay una pieza en el destino, el movimiento es inválido
            return false;
        }
    }
    else if (deltaX == 0 && deltaY == 2 && origen.y == 1) {
        // Primer movimiento del peón, avanza dos posiciones
        int minY = min(origen.y, destino.y) + 1;
        int maxY = max(origen.y, destino.y);

        for (int y = minY; y < maxY; y++) {
            if (tablero.getPieza(origen.x, y) != nullptr) {
                // Si hay una pieza en el camino, el movimiento es inválido
                return false;
            }
        }
    }
    else if (deltaX == 1 && deltaY == 1) {
        // Movimiento diagonal de una posición
        if (tablero.getPieza(destino.x, destino.y) == nullptr) {
            // Si no hay una pieza en el destino, el movimiento es inválido
            return false;
        }
    }
    else {
        // Movimiento inválido
        return false;
    }

    return true;



}

*/


//Come pero hace falta hacer distincion entre blancas y negras

bool Peon::validarMovimiento(Vector origen, Vector destino, Tablero& tablero) {

    int VariacionX = destino.x - origen.x;
    int VariacionY = destino.y - origen.y;
   
    /*
    
    if (tablero.getPieza(origen.x, origen.y)->getColor() == Pieza::Blanco) {
        if (VariacionY <= 0) {
            // El peón no puede avanzar hacia atrás
            return false;
        }
    }
    else if (VariacionY >= 0) {
        return false;
    }
    */
    if (VariacionY <= 0) {
        // El peón no puede avanzar hacia atrás
        return false;
    }

    

    if (VariacionX == 0 && VariacionY == 1) {
        // Movimiento vertical de una posición
        if (tablero.getPieza(destino.x, destino.y) != nullptr) {
            // Si hay una pieza en el destino, el movimiento es inválido
            return false;
        }
    }
    else if (VariacionX == 0 && VariacionY == 2 && origen.y == 1) {
        // Primer movimiento del peón, avanza dos posiciones
        int minY = min(origen.y, destino.y) + 1;
        int maxY = max(origen.y, destino.y);

        for (int y = minY; y < maxY; y++) {
            if (tablero.getPieza(origen.x, y) != nullptr) {
                // Si hay una pieza en el camino, el movimiento es inválido
                return false;
            }
        }
    }
    else if (VariacionX == 1 && VariacionY == 1) {
        // Movimiento diagonal de una posición
        if (tablero.getPieza(destino.x, destino.y) == nullptr) {
            // Si no hay una pieza en el destino, el movimiento es inválido
            return false;
        }
    }
    else {
        // Movimiento inválido
        return false;
    }

    return true;





}




