#pragma once
#include <Vector.h>
#include "ETSIDI.h"
#include <Casilla.h>

#define MAX 64

using ETSIDI::Sprite;
class Tablero;

class Pieza
{
public:
    enum COLOR { Blanco, Negro };
    enum TIPO { PEON, REY, REINA, ALFIL, TORRE, CABALLO, PIEZAESPECIAL };
   protected:
       COLOR color;
       TIPO tipo;
       const float tam = 1.0;
       Sprite imagen;

       //Constructor comun a las piezas
       Pieza(TIPO t, COLOR color, const char* fdibujo):tipo(t), color(color), imagen(fdibujo, 0, 0, tam, tam) {
           imagen.setCenter(0, 0);
       };
       
   public:
       void Dibuja(){
           imagen.draw();
       }

      // FUNCIONES DE INTERFAZ
       TIPO getTipo() { return tipo;}
       COLOR getColor() { return color; }

       // Método para validar un movimiento de la pieza, se uiliza polimorfismo
       virtual bool validarMovimiento(Vector origen,Vector destino,Tablero& t) { return true; } 
       virtual Pieza* clonar() { return new Pieza(*this); }

       // SOBRECARGA DE OPERADORES
       bool operator!=(const Pieza& Pieza2) const {
           if (color != Pieza2.color || tipo != Pieza2.tipo)return false;
           else return true;
       }

       Pieza** operator[](const Vector& v) {
           return this[v.x][v.y];
       }

};

