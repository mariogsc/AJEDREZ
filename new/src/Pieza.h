#pragma once
#include <Vector.h>
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Pieza
{
public:
    enum COLOR { Blanco, Negro };
    enum TIPO { PEON, REY, REINA, ALFIL, TORRE, CABALLO };
   protected:
       COLOR color;
       TIPO tipo;
       const float tam = 1.0;
       Sprite imagen;

       //Constructor comun a las piezas
       Pieza(TIPO t, COLOR color, const char* fdibujo):tipo(t), color(color), imagen(fdibujo, 0, 0, tam, tam) {
           imagen.setCenter(0.0, 0.0);
       };
       
   public:
       void Dibuja() {
           glPushMatrix();
           imagen.draw();
           glEnd();
       }

       
      // FUNCIONES DE INTERFAZ
       TIPO getTipo() { return tipo;}
       COLOR getColor() { return color; }

       // Método para validar un movimiento de la pieza, se uiliza polimorfismo

       virtual bool validarMovimiento(Vector& origen, Vector& destino,Tablero &tablero) { return true; } 
       // DA ERROR AL PASAR EL TABLERO

};
