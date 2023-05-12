#pragma once
#include <ColorCasilla.h>
#include <Vector.h>
#include <freeglut.h>

class Marcador {
    
    //Finalmente construllo el marcador con la funcion casilla
    
 Casilla r1;
public:

    Marcador() {
        r1.SetAlto(9.0);
        r1.SetAncho(3.0);
        r1.SetColor(200,0,200);
    }


    void DibujaMarcador() {
        r1.DibujaCasilla({ 9.0,0.0 }, {});

      /*  r2.DibujaRectangulo(); //continuar y situar los 5 cuadrados para generar un marcador
        r3.DibujaRectangulo();
        r4.DibujaRectangulo();
        r5.DibujaRectangulo();

        */
        
    }
};    
 
