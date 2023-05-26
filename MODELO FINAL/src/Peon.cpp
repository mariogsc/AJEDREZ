#include "Peon.h"
#include <ETSIDI.h>
#include <freeglut.h>

Peon::Peon(COLOR c) :Pieza(PEON, c, c == Blanco ? "imagenes/PeonBlanco.png" : "imagenes/PeonNegro.png") {}

bool Peon::validarMovimiento(Vector origen, Vector destino, Tablero& t) {

    //Comprobar si se mueven las blancas o las negras (ya que unas van para arriba y otras para abajo)
    int dirMov = (t.getPieza(origen.x,origen.y)->getColor() == Blanco) ? 1 : -1;  


    //Para el primer movimiento del peón (opción de avanzar dos casillas)
    if (origen.x == destino.x && origen.y + 2 * dirMov == destino.y){
        if (t.getPieza(origen.x, origen.y)->getColor() == Blanco && origen.y == 1 || (t.getPieza(origen.x, origen.y)->getColor() == Negro && origen.y == 6)) {
            //Para comprobar que no salta ninguna casilla
            if (t.getPieza(destino.x, destino.y) == nullptr && t.getPieza(destino.x, destino.y - dirMov) == nullptr) {  
                return true;
            }
        }
    }

    //Movimiento normal hacia adelante
    if ((origen.x == destino.x) && (origen.y + dirMov == destino.y) && (t.getPieza(destino.x, destino.y) == nullptr)) {  
        return true;
    }

    //Movimiento de captura diagonal  
    if (((origen.x - destino.x) == 1 || (origen.x - destino.x) == -1 ) && origen.y + dirMov == destino.y) {     
        if (t.getPieza(destino.x, destino.y) != nullptr && t.getPieza(origen.x, origen.y)->getColor() != t.getPieza(destino.x, destino.y)->getColor()) {
            return true;
        }
    }

    return false;
}