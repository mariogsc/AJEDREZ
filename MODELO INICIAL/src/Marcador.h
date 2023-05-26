#pragma once
#include <ColorCasilla.h>
#include <Vector.h>
#include <freeglut.h>
#include <Casilla.h>


class Marcador {
    Casilla r1;
public:

    Marcador() {
        r1.SetAlto(9.0);
        r1.SetAncho(3.0);
        r1.SetColor(200,0,200);
    }


    void DibujaMarcador() {
        r1.DibujaCasilla({ 9.0,0.0 }, {});

      /*  r2.DibujaRectangulo();
        r3.DibujaRectangulo();
        r4.DibujaRectangulo();
        r5.DibujaRectangulo();

        */
        
    }
};


