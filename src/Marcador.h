#pragma once
#include <ColorCasilla.h>
#include <Vector.h>
#include <freeglut.h>

class Marcador {
     Casilla r1;   
     Sprite* CartelBlancas = new Sprite("imagenes/CartelBlancas.png", 9, 7.6, 1, 0.4);
     Sprite* CartelNegras = new Sprite("imagenes/CartelNegras.png", 10.45, 7.6, 1, 0.4);

public:

    Marcador() {
         r1.SetAlto(8.0);
        r1.SetAncho(3.0);
        r1.SetColor(255,255,255);

        r2.SetAlto(7.2);
        r2.SetAncho(1.4);
        r2.SetColor(color1);

        r3.SetAlto(7.2);
        r3.SetAncho(1.4);
        r3.SetColor(color2);

        r4.SetAlto(0.6);
        r4.SetAncho(1.3);
        r4.SetColor(255, 255, 255);

        r5.SetAlto(0.6);
        r5.SetAncho(1.3);
        r5.SetColor(255, 255, 255);
    }


    void DibujaMarcador() {
        r1.DibujaCasilla({ 8.2,0.0 }, {});
        r2.DibujaCasilla({ 8.3,0.1 }, {});
        r3.DibujaCasilla({ 9.8,0.1 }, {});
        r4.DibujaCasilla({ 8.3, 7.3 }, {});
        r5.DibujaCasilla({ 9.8, 7.3 }, {});   
    }
};    
 
