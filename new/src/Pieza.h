#pragma once
#include <Vector.h>

class Pieza
{
public:
    enum COLOR { Blanco, Negro };
    enum TIPO { PEON, REY, REINA, ALFIL, TORRE, CABALLO };
   protected:
       COLOR color;
       TIPO t;
      
      //TAMAÑO DE LAS FICHAS
   public:
       // Constructor por defecto
       Pieza(COLOR col) : color(col) {}
      

      // Método para obtener el tipo de la pieza, se utiliza polimorfismo
       virtual TIPO getTipo() {};

       // Método para validar un movimiento de la pieza, se uiliza polimorfismo
       virtual bool validarMovimiento(Vector origen,Vector destino); //Hay que pasarle el tablero o hacerlo friend
    

};
