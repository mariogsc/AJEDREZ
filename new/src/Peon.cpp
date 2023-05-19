#include "Peon.h"
#include <ETSIDI.h>
#include <freeglut.h>

Peon::Peon(COLOR c) :Pieza(PEON, c, c == Blanco ? "imagenes/PeonBlanco.png" : "imagenes/PeonNegro.png") {}

bool Peon::validarMovimiento(Vector origen, Vector destino, Tablero& tablero) {

    int dirMov = (tablero.getPieza(origen.x,origen.y)->getColor() == Blanco) ? 1 : -1;  //Comprobar si se mueven las blancas o las negras ( ya que unas van para arriba y otras para abajo)

    //Para el primer movimiento del peón (opción de avanzar dos casillas)
    if (origen.x == destino.x && origen.y + 2 * dirMov == destino.y){
        if (tablero.getPieza(origen.x, origen.y)->getColor() == Blanco && origen.y == 1 || (tablero.getPieza(origen.x, origen.y)->getColor() == Negro && origen.y == 6)) {
            if (tablero.getPieza(destino.x, destino.y) == nullptr && tablero.getPieza(destino.x, destino.y - dirMov) == nullptr) {  //Para comprobar que no salta ninguna casilla
                return true;
            }
        }
    }

    if ((origen.x == destino.x) && (origen.y + dirMov == destino.y) && (tablero.getPieza(destino.x, destino.y) == nullptr)) {  //Movimiento normal hacia adelante
        return true;
    }

    if (((origen.x - destino.x) == 1 || (origen.x - destino.x) == -1 ) && origen.y + dirMov == destino.y) {     //Movimiento de captura diagonal  
        if (tablero.getPieza(destino.x, destino.y) != nullptr && tablero.getPieza(origen.x, origen.y)->getColor() != tablero.getPieza(destino.x, destino.y)->getColor()) {
            return true;
        }
    }

    return false;
}