#pragma once
#include <ColorCasilla.h>
#include <Vector.h>
#include <freeglut.h>

class Marcador {
    Rectangulo r1;
public:
    void DibujaMarcador() { //continuar
    }
};

class Rectangulo {
private:
    float base, altura;
    Vector posicion;
    ColorCasilla color;
public:
    Rectangulo(Vector v, ColorCasilla c,float ancho, float alto) {
        base = ancho;
        altura = alto;
        posicion = v;
        color = c;
    }

    void DibujaRectangulo() {
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glVertex3f(posicion.x, posicion.y, 0.0f);
        glVertex3f(posicion.x+base, posicion.y, 0.0f);
        glVertex3f(posicion.x+base, posicion.y+altura, 0.0f);
        glVertex3f(posicion.x,posicion.y+altura, 0.0f);
        glEnd();
        glEnable(GL_LIGHTING);
    };
};
