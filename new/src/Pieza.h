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
    enum TIPO { PEON, REY, REINA, ALFIL, TORRE, CABALLO };
   protected:
       COLOR color;
       TIPO tipo;
       const float tam = 1.0;
       Sprite imagen;

       Casilla* lista[MAX];
       int numero;

       //Constructor comun a las piezas
       Pieza(TIPO t, COLOR color, const char* fdibujo):numero(0),tipo(t), color(color), imagen(fdibujo, 0, 0, tam, tam) {
           imagen.setCenter(0, 0);
       };
       
   public:
       void Dibuja(){
           imagen.draw();
       }

       void actualizarPosicion(float x, float y) {
           imagen.setPos(x, y);
       }

       
      // FUNCIONES DE INTERFAZ
       TIPO getTipo() { return tipo;}
       COLOR getColor() { return color; }

       // Método para validar un movimiento de la pieza, se uiliza polimorfismo
       virtual bool validarMovimiento(Vector origen,Vector destino,Tablero& t) { return true; } 
       
       void CompruebaPosible(Vector origen, Tablero& tablero) {
           for (int i = 0; i < 8; i++) {
               for (int j = 0; j < 8; j++) {
                   if (validarMovimiento(origen, { i,j }, tablero) == true)
                   {
                       agregar(new Casilla({i,j}, {0, 255, 0}));
                       
                   }
               }
           }
       }


       bool operator!=(const Pieza& Pieza2) const {
           if (color != Pieza2.color || tipo != Pieza2.tipo)return false;
           else return true;
       }

       bool agregar(Casilla* casilla) {
           if (numero < MAX) {
               lista[numero++] = casilla;
               return true;
           }
           else return false;
       }

       void eliminarContenido() {
           for (int i = 0; i < numero; i++) {
               delete lista[i];
               numero--;
           }
       }

       void DibujaPosibles() {
           for (int i = 0; i < numero; i++)
           {
               lista[i]->DibujaCasilla(0.0005);
           }
       }


};

