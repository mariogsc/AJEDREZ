#include "Torre.h"
#include <ETSIDI.h>
#include <freeglut.h>

Torre::Torre(COLOR c) :Pieza (TORRE,c, c==Blanco?"imagenes/TorreBlanco.png":"imagenes/TorreNegro.png"){}

bool Torre::validarMovimiento(Vector& origen, Vector& destino,Tablero &tablero) {
    
    // Validación específica para una torre
    if (origen.getx() == destino.getx() || origen.gety() == destino.gety()) {
        
        int variacionX = destino.getx() - origen.getx();
        int variacionY = destino.gety() - origen.gety();
        int pendienteX = (variacionX > 0) ? 1 : -1;
        int pendienteY = (variacionY > 0) ? 1 : -1;

        int x = origen.getx() + pendienteX;
        int y = origen.gety() + pendienteY;

        while (x != destino.getx() || y != destino.gety()) {
            if (tablero.getPieza(x,y) != nullptr) {
                return false; // Si hay una pieza en la diagonal movimiento invalido
            }
            x += pendienteX;
            y += pendienteY;
        }

        return true; // Movimiento válido
    }
    else {
        return false; // Movimiento inválido
    }
}
